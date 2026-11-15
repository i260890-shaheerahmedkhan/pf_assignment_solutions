#include "terminal.h"
#include <iostream>
using namespace std;

void make_column(int[], int[], char[][114], int, int, int, int &, int &, bool &,
                 int &, int &, int &);
void build_cave(int[], int[], char[][114], int &, int &, bool &);
void load_bird(int, int, char[][9], int &, int &);
void write_digits(char[], int, int);
void draw_frame(int[], int[], char[][114], int, int, int, int, int, int, bool);

int main() {
  const int cols = 114;
  const int rows = 30;

  termInit();

  int cave_top[cols];
  int cave_bottom[cols];
  char rocks[rows][cols];

  int best = 0;
  bool quit = false;

  while (!quit) {
    int dir = 0, len = 0, rock_type = 0, rock_top = 0, rock_offset = 0;
    bool is_rock = false;

    build_cave(cave_top, cave_bottom, rocks, dir, len, is_rock);

    int bird_row = 14;
    int facing = 1;
    int frame = 0;
    int distance = 0;
    bool game_over = false;
    bool restart = false;

    draw_frame(cave_top, cave_bottom, rocks, bird_row, facing, frame, distance,
               best, 70, game_over);

    while (!quit && !restart) {
      while (keyPressed()) {
        int key = readKey();
        if (key == 'q') {
          quit = true;
          break;
        }
        if (game_over) {
          if (key == 'r' || key == ' ') {
            restart = true;
            break;
          }
        } else {
          if (key == 'w' || key == KEY_ARROW_UP) {
            bird_row--;
          } else if (key == 's' || key == KEY_ARROW_DOWN) {
            bird_row++;
          } else if ((key == 'a' || key == KEY_ARROW_LEFT) && facing != -1) {
            facing = -1;
            is_rock = false;
            dir = 0;
            len = 10;
          } else if ((key == 'd' || key == KEY_ARROW_RIGHT) && facing != 1) {
            facing = 1;
            is_rock = false;
            dir = 0;
            len = 10;
          }
        }
      }

      if (quit || restart)
        break;

      int wait_ms = max(30, 70 - distance / 40);

      if (!game_over) {
        if (facing == 1) {
          for (int c = 0; c < cols - 1; c++) {
            cave_top[c] = cave_top[c + 1];
            cave_bottom[c] = cave_bottom[c + 1];
            for (int r = 0; r < rows; r++)
              rocks[r][c] = rocks[r][c + 1];
          }
          make_column(cave_top, cave_bottom, rocks, 113, 112, distance, dir,
                      len, is_rock, rock_type, rock_top, rock_offset);
        } else {
          for (int c = cols - 1; c > 0; c--) {
            cave_top[c] = cave_top[c - 1];
            cave_bottom[c] = cave_bottom[c - 1];
            for (int r = 0; r < rows; r++)
              rocks[r][c] = rocks[r][c - 1];
          }
          make_column(cave_top, cave_bottom, rocks, 0, 1, distance, dir, len,
                      is_rock, rock_type, rock_top, rock_offset);
        }

        frame++;
        distance++;
        best = max(best, distance);

        char sprite[3][9];
        int s_rows = 0, s_cols = 0;
        load_bird(facing, (frame / 3) % 2, sprite, s_rows, s_cols);

        for (int r = 0; r < s_rows; r++) {
          for (int c = 0; c < s_cols; c++) {
            if (sprite[r][c] != ' ') {
              int gr = bird_row + r;
              int gc = 53 + c;
              if (gr < 0 || gr >= rows || gr < cave_top[gc] ||
                  gr >= cave_bottom[gc] || rocks[gr][gc] != ' ') {
                game_over = true;
              }
            }
          }
        }

        draw_frame(cave_top, cave_bottom, rocks, bird_row, facing, frame,
                   distance, best, wait_ms, game_over);
        if (game_over)
          flushKeys();
      }

      sleepMs(wait_ms);
    }
  }

  termRestore();

  return 0;
}

void make_column(int cave_top[], int cave_bottom[], char rocks[][114],
                 int new_col, int old_col, int distance, int &dir, int &len,
                 bool &is_rock, int &rock_type, int &rock_top,
                 int &rock_offset) {
  for (int r = 0; r < 30; r++)
    rocks[r][new_col] = ' ';

  int level = distance / 250;
  int min_gap = max(9, 18 - level);

  if (len <= 0) {
    is_rock = false;
    if (distance >= 150) {
      int chance = min(70, 35 + 5 * level);
      if (randomInt(0, 99) < chance)
        is_rock = true;
    }

    if (is_rock) {
      dir = 0;
      len = 28;
      rock_type = randomInt(0, 1);
      int r_height = (rock_type == 0) ? 3 : 4;
      int r_width = (rock_type == 0) ? 6 : 8;

      int top = cave_top[old_col];
      int bottom = cave_bottom[old_col];
      int max_top = max(top + 1, bottom - 1 - r_height);

      rock_top = randomInt(top + 1, max_top);
      int free_above = rock_top - top;
      int free_below = bottom - (rock_top + r_height);
      if (free_above < 4 && free_below < 4)
        rock_top = top + 1;

      rock_offset = (28 - r_width) / 2;
    } else {
      dir = randomInt(-1, 1);
      len = randomInt(6, 25);
    }
  }

  if (is_rock) {
    cave_top[new_col] = cave_top[old_col];
    cave_bottom[new_col] = cave_bottom[old_col];

    int step = 28 - len;
    int r_width = (rock_type == 0) ? 6 : 8;

    if (step >= rock_offset && step < rock_offset + r_width) {
      int art_col = step - rock_offset;
      if (new_col == 0)
        art_col = (r_width - 1) - art_col;

      if (rock_type == 0) {
        char small_rock[3][7] = {" /##\\ ", "(####)", " \\##/ "};
        for (int r = 0; r < 3; r++) {
          if (small_rock[r][art_col] != ' ' && rock_top + r < 30)
            rocks[rock_top + r][new_col] = small_rock[r][art_col];
        }
      } else {
        char large_rock[4][9] = {"  /##\\  ", " /####\\ ", "(######)",
                                 " \\####/ "};
        for (int r = 0; r < 4; r++) {
          if (large_rock[r][art_col] != ' ' && rock_top + r < 30)
            rocks[rock_top + r][new_col] = large_rock[r][art_col];
        }
      }
    }
    len--;
  } else {
    int gap = cave_bottom[old_col] - cave_top[old_col];
    int centre = cave_top[old_col] + gap / 2;
    centre += dir;

    int roll = randomInt(0, 99);
    if (roll <= 7)
      gap += 1;
    else if (roll <= 15)
      gap -= 1;

    gap = min(min_gap + 4, max(min_gap, gap));

    int top = centre - gap / 2;
    if (top < 1) {
      top = 1;
      dir = 0;
    }
    if (top + gap > 29) {
      top = 29 - gap;
      dir = 0;
    }

    cave_top[new_col] = top;
    cave_bottom[new_col] = top + gap;
    len--;
  }
}

void build_cave(int cave_top[], int cave_bottom[], char rocks[][114], int &dir,
                int &len, bool &is_rock) {
  for (int r = 0; r < 30; r++) {
    for (int c = 0; c < 114; c++)
      rocks[r][c] = ' ';
  }

  cave_top[57] = 5;
  cave_bottom[57] = 25;

  int rt = 0, rtop = 0, roff = 0;
  len = 0;
  for (int c = 58; c < 114; c++) {
    make_column(cave_top, cave_bottom, rocks, c, c - 1, 0, dir, len, is_rock,
                rt, rtop, roff);
  }

  len = 0;
  for (int c = 56; c >= 0; c--) {
    make_column(cave_top, cave_bottom, rocks, c, c + 1, 0, dir, len, is_rock,
                rt, rtop, roff);
  }

  len = 0;
  is_rock = false;
}

void load_bird(int facing, int wing, char sprite[][9], int &s_rows,
               int &s_cols) {
  for (int r = 0; r < 3; r++) {
    for (int c = 0; c < 9; c++)
      sprite[r][c] = ' ';
  }

  s_rows = 3;
  s_cols = 9;

  if (facing == 1) {
    if (wing == 0) {
      char art[3][10] = {"   |\\    ", "~==|_\\o=>", "         "};
      for (int r = 0; r < 3; r++)
        for (int c = 0; c < 9; c++)
          sprite[r][c] = art[r][c];
    } else {
      char art[3][10] = {"         ", "~==|-/o=>", "   |/    "};
      for (int r = 0; r < 3; r++)
        for (int c = 0; c < 9; c++)
          sprite[r][c] = art[r][c];
    }
  } else {
    if (wing == 0) {
      char art[3][10] = {"    /|   ", "<=o/_|==~", "         "};
      for (int r = 0; r < 3; r++)
        for (int c = 0; c < 9; c++)
          sprite[r][c] = art[r][c];
    } else {
      char art[3][10] = {"         ", "<=o\\-|==~", "    \\|   "};
      for (int r = 0; r < 3; r++)
        for (int c = 0; c < 9; c++)
          sprite[r][c] = art[r][c];
    }
  }
}

void write_digits(char line[], int pos, int val) {
  val = min(99999, val);
  for (int i = 4; i >= 0; i--) {
    line[pos + i] = (char)('0' + (val % 10));
    val /= 10;
  }
}

void draw_frame(int cave_top[], int cave_bottom[], char rocks[][114],
                int bird_row, int facing, int frame, int distance, int best,
                int wait_ms, bool game_over) {
  char screen[33][118];
  for (int r = 0; r < 33; r++) {
    for (int c = 0; c < 116; c++)
      screen[r][c] = ' ';
    screen[r][116] = '\n';
    screen[r][117] = '\0';
  }

  screen[0][0] = '+';
  screen[0][115] = '+';
  screen[31][0] = '+';
  screen[31][115] = '+';

  for (int c = 1; c <= 114; c++) {
    screen[0][c] = '-';
    screen[31][c] = '-';
  }
  for (int r = 1; r <= 30; r++) {
    screen[r][0] = '|';
    screen[r][115] = '|';
  }

  for (int c = 0; c < 114; c++) {
    for (int r = 0; r < 30; r++) {
      if (r < cave_top[c] || r >= cave_bottom[c])
        screen[r + 1][c + 1] = '#';
      else if (rocks[r][c] != ' ')
        screen[r + 1][c + 1] = rocks[r][c];
    }
  }

  char sprite[3][9];
  int s_rows = 0, s_cols = 0;
  load_bird(facing, (frame / 3) % 2, sprite, s_rows, s_cols);

  for (int r = 0; r < s_rows; r++) {
    for (int c = 0; c < s_cols; c++) {
      if (sprite[r][c] != ' ' && bird_row + r >= 0 && bird_row + r < 30)
        screen[bird_row + r + 1][53 + c + 1] = sprite[r][c];
    }
  }

  if (game_over) {
    char box[5][31] = {
        "+----------------------------+", "|         GAME  OVER         |",
        "|   R / SPACE : Play Again   |", "|         Q   : Quit         |",
        "+----------------------------+"};
    for (int r = 0; r < 5; r++) {
      for (int c = 0; c < 30; c++)
        screen[13 + r][43 + c] = box[r][c];
    }
  }

  char t1[] = " DIST: ";
  for (int i = 0; t1[i]; i++)
    screen[32][i] = t1[i];
  write_digits(screen[32], 7, distance);

  char t2[] = "   BEST: ";
  for (int i = 0; t2[i]; i++)
    screen[32][12 + i] = t2[i];
  write_digits(screen[32], 21, best);

  char t3[] = "   SPEED: [";
  for (int i = 0; t3[i]; i++)
    screen[32][26 + i] = t3[i];

  int bars = min(10, max(0, (70 - wait_ms) / 4));

  for (int i = 0; i < 10; i++)
    screen[32][37 + i] = (i < bars) ? '>' : '-';
  screen[32][47] = ']';

  char t4[] = "   FLYING: ";
  for (int i = 0; t4[i]; i++)
    screen[32][48 + i] = t4[i];
  screen[32][59] = (facing == 1) ? '>' : '<';
  screen[32][60] = (facing == 1) ? '>' : '<';

  char t5[] = "   [W/S: Move | A/D: Turn | Q: Quit]";
  for (int i = 0; t5[i]; i++)
    screen[32][62 + i] = t5[i];

  cursorHome();
  for (int r = 0; r < 33; r++)
    cout << screen[r];
  cout << flush;
}
