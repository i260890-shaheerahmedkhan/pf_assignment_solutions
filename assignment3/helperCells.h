// =====================================================================
//  helperCells.h  --  PF Assignment 3, CELLS
//
//  Given to students. DO NOT EDIT.
//
//  readKey()      waits for one key and returns it at once, without
//                 Enter and without showing it on the screen
//  clearScreen()  clears the screen, cursor to the top-left corner
//
//  Everywhere else the terminal behaves normally, so cin works as usual.
//
// =====================================================================
#ifndef HELPER_CELLS_H
#define HELPER_CELLS_H

#ifndef __linux__
#error "helperCells.h works on Linux only. Build and run CELLS on Ubuntu."
#endif

#include <iostream>

const int KEY_UP     = 1001;
const int KEY_DOWN   = 1002;
const int KEY_LEFT   = 1003;
const int KEY_RIGHT  = 1004;
const int KEY_ENTER  = 1005;
const int KEY_DELETE = 1006;   // Delete or Backspace

#include <cstdlib>
#include <cerrno>
#include <csignal>
#include <termios.h>
#include <unistd.h>

static struct termios helperCellsSaved;
static volatile sig_atomic_t helperCellsInKeyMode = 0;

static void helperCellsRestore()
{
    if (helperCellsInKeyMode)
    {
        tcsetattr(STDIN_FILENO, TCSANOW, &helperCellsSaved);
        helperCellsInKeyMode = 0;
    }
}

static void helperCellsOnSignal(int sig)
{
    helperCellsRestore();
    signal(sig, SIG_DFL);
    raise(sig);
}

static int helperCellsByte(bool waitForever)
{
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_cc[VMIN] = waitForever ? 1 : 0;
    t.c_cc[VTIME] = waitForever ? 0 : 1;     
    tcsetattr(STDIN_FILENO, TCSANOW, &t);

    unsigned char c = 0;
    ssize_t got = read(STDIN_FILENO, &c, 1);
    while (got < 0 && errno == EINTR)
        got = read(STDIN_FILENO, &c, 1);
    if (got == 1)
        return c;
    if (waitForever)
    {
        helperCellsRestore();
        std::exit(0);
    }
    return -1;
}

int readKey()
{
    std::cout << std::flush;

    if (!isatty(STDIN_FILENO))              
    {
        int c = std::cin.get();
        if (c == '\n') return KEY_ENTER;
        return c;
    }

    static bool hooked = false;
    if (!hooked)
    {
        int signals[] = { SIGINT, SIGTERM, SIGHUP, SIGQUIT,
                          SIGSEGV, SIGBUS, SIGFPE, SIGABRT, SIGILL };
        for (unsigned i = 0; i < sizeof(signals) / sizeof(signals[0]); i++)
            signal(signals[i], helperCellsOnSignal);
        hooked = true;
    }

    tcgetattr(STDIN_FILENO, &helperCellsSaved);
    struct termios keys = helperCellsSaved;
    keys.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &keys);
    helperCellsInKeyMode = 1;

    int key = -1;
    while (key == -1)
    {
        int c = helperCellsByte(true);
        if (c == 27)                         
        {
            char rest[8];
            int n = 0;
            int b = helperCellsByte(false);
            while (b != -1 && n < 8)
            {
                rest[n++] = (char)b;
                if ((b >= 'A' && b <= 'Z') || b == '~')
                    break;
                b = helperCellsByte(false);
            }
            if (n == 2 && rest[0] == '[' && rest[1] == 'A') key = KEY_UP;
            if (n == 2 && rest[0] == '[' && rest[1] == 'B') key = KEY_DOWN;
            if (n == 2 && rest[0] == '[' && rest[1] == 'C') key = KEY_RIGHT;
            if (n == 2 && rest[0] == '[' && rest[1] == 'D') key = KEY_LEFT;
            if (n == 3 && rest[0] == '[' && rest[1] == '3' && rest[2] == '~') key = KEY_DELETE;
        }
        else if (c == 10 || c == 13)
            key = KEY_ENTER;
        else if (c == 127 || c == 8)
            key = KEY_DELETE;
        else if (c >= 32 && c <= 126)
            key = c;
    }

    helperCellsRestore();
    return key;
}

void clearScreen()
{
    std::cout << "\x1b[H\x1b[2J" << std::flush;
}

#endif
