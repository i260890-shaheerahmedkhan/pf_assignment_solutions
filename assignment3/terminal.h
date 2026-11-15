// =====================================================================
//  terminal.h  --  PROVIDED HELPER for PF Assignment 3 (PTERO)
//
//  DO NOT EDIT. Linux (Ubuntu) only.
//
//  Put this in the same folder as your solution and write
//    #include "terminal.h"
//  at the top of your program. 
//
//    termInit()             call once, just before the game loop
//    termRestore()          call once, before the program ends
//    keyPressed()           true if a key is waiting (never waits)
//    readKey()              the waiting key: a lowercase letter, or
//                           KEY_ARROW_UP / DOWN / LEFT / RIGHT
//    flushKeys()            throws away any keys still waiting
//    cursorHome()           moves the cursor to the top-left corner,
//                           so the next frame prints over the last one
//    sleepMs(ms)            waits ms milliseconds
//    randomInt(low, high)   a random whole number from low to high,
//                           both included (starts from the clock, so
//                           every run is different)
// =====================================================================
#ifndef TERMINAL_H
#define TERMINAL_H

#ifndef __linux__
#error "terminal.h only works on Linux. Build and run PTERO on Ubuntu."
#endif

#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <sys/select.h>
#include <sys/resource.h>

const int KEY_NONE = 0;
const int KEY_ARROW_UP = 1001;
const int KEY_ARROW_DOWN = 1002;
const int KEY_ARROW_LEFT = 1003;
const int KEY_ARROW_RIGHT = 1004;

// ------------------------------------------------------------
__attribute__((constructor)) static void termRaiseStack()
{
    struct rlimit limit;
    if (getrlimit(RLIMIT_STACK, &limit) == 0)
    {
        limit.rlim_cur = limit.rlim_max;
        setrlimit(RLIMIT_STACK, &limit);
    }
}

// ------------------------------------------------------- random numbers
static unsigned int termRandomNext()
{
    static unsigned int state = 0;
    if (state == 0)
    {
        struct timespec now;
        clock_gettime(CLOCK_REALTIME, &now);
        state = (unsigned int)now.tv_sec * 2654435761u
              ^ (unsigned int)now.tv_nsec * 40503u
              ^ (unsigned int)getpid() * 2246822519u;
        if (state == 0)
            state = 1;
        for (int i = 0; i < 8; i++)         
        {
            state ^= state << 13;
            state ^= state >> 17;
            state ^= state << 5;
        }
    }
    state ^= state << 13;
    state ^= state >> 17;
    state ^= state << 5;
    return state;
}

int randomInt(int low, int high)
{
    if (high < low)
    {
        int t = low;
        low = high;
        high = t;
    }
    unsigned int range = (unsigned int)(high - low) + 1u;
    return low + (int)(termRandomNext() % range);
}

// ------------------------------------------------------------- terminal
static struct termios termSaved;
static bool termActive = false;

void termRestore()
{
    if (termActive)
        tcsetattr(STDIN_FILENO, TCSANOW, &termSaved);
    termActive = false;
    std::cout << "\x1b[?25h" << std::endl;     
}

static void termOnSignal(int)
{
    termRestore();
    _exit(0);
}

void termInit()
{
    if (tcgetattr(STDIN_FILENO, &termSaved) == 0)
    {
        struct termios raw = termSaved;
        raw.c_lflag &= ~(ICANON | ECHO);       
        raw.c_cc[VMIN] = 1;
        raw.c_cc[VTIME] = 0;
        tcsetattr(STDIN_FILENO, TCSANOW, &raw);
        termActive = true;
    }
    signal(SIGINT, termOnSignal);              
    signal(SIGTERM, termOnSignal);
    std::cout << "\x1b[2J\x1b[?25l" << std::flush;  
}

// ------------------------------------------------------------- keyboard
bool keyPressed()
{
    fd_set set;
    FD_ZERO(&set);
    FD_SET(STDIN_FILENO, &set);
    struct timeval noWait;
    noWait.tv_sec = 0;
    noWait.tv_usec = 0;
    return select(STDIN_FILENO + 1, &set, 0, 0, &noWait) > 0;
}

static int termReadByte()
{
    unsigned char c = 0;
    if (read(STDIN_FILENO, &c, 1) != 1)
        return KEY_NONE;
    return c;
}

int readKey()
{
    int c = termReadByte();
    if (c == 27 && keyPressed())                
    {
        int next = termReadByte();
        if ((next == '[' || next == 'O') && keyPressed())
        {
            int code = termReadByte();
            if (code == 'A') return KEY_ARROW_UP;
            if (code == 'B') return KEY_ARROW_DOWN;
            if (code == 'C') return KEY_ARROW_RIGHT;
            if (code == 'D') return KEY_ARROW_LEFT;
        }
        return KEY_NONE;
    }
    if (c >= 'A' && c <= 'Z')
        c = c - 'A' + 'a';
    return c;
}

void flushKeys()
{
    while (keyPressed())
        readKey();
}

// --------------------------------------------------------- screen, time
void cursorHome()
{
    std::cout << "\x1b[H";
}

void sleepMs(int ms)
{
    if (ms <= 0)
        return;
    struct timespec t;
    t.tv_sec = ms / 1000;
    t.tv_nsec = (long)(ms % 1000) * 1000000L;
    nanosleep(&t, 0);
}

#endif
