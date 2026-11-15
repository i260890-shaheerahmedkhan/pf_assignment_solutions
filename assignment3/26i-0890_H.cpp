#include <iostream>
#define readKey cellsReadKey
#include "helperCells.h"
#undef readKey
#include "terminal.h"

using namespace std;

// questions

void question1();
void question2();
void question3();
void question4();
void question5();
void question6();
void question7();
void question8();
void question9();

// utilities

// for question 2
void print_calendar(int, int);

// for question 3
void row(int, int, int);

// for question 4
long long sequence_sum(int, int);
long long position_value(int, int, int, int);
char display_value(long long);

// for question 5
long long power10(int);
long long &get_row(int, long long &, long long &, long long &, long long &,
                   long long &, long long &, long long &, long long &,
                   long long &, long long &);
int get_cell(int, int, long long, long long, long long, long long, long long,
             long long, long long, long long, long long, long long);
void set_cell(int, int, int, long long &, long long &, long long &, long long &,
              long long &, long long &, long long &, long long &, long long &,
              long long &);

// for question 6
int find_process(int[], int, int);
int amount_of_free_memory(int[], int);
int largest_free_consecutive_memory(int[], int);
bool allocate_memory(int[], int, int, int);
void free_memory(int[], int, int);
void display_memory(int[], int);
void memory_compaction(int[], int);
void process_info(int, int[], int[], int[], int[], int[], int[]);
void process_schedule(int, int, int, int[], int[], int[], int[], int[]);
void non_preemptive(int, int, int[], int[], int[], int[], int[], int[], int[],
                    int[]);
void round_robin(int, int[], int[], int[], int[], int[], int[], int[], int[]);
void stats(int, int[], int[], int, int, int, int[], int[], int[]);

// for question 7
void clear_board(char[][7]);
void show_board(char[][7]);
bool valid_move(char[][7], int);
int place_piece(char[][7], int, char);
bool has_won(char[][7], char);
bool board_full(char[][7]);
int window_points(char, char, char, char);
int score_position(char[][7]);
int best_move(char[][7]);

// for question 8
void make_column(int[], int[], char[][114], int, int, int, int &, int &, bool &,
                 int &, int &, int &);
void build_cave(int[], int[], char[][114], int &, int &, bool &);
void load_bird(int, int, char[][9], int &, int &);
void write_digits(char[], int, int);
void draw_frame(int[], int[], char[][114], int, int, int, int, int, int, bool);

// for question 9
int str_len(const char[]);
void str_copy(char[], const char[], int);
char to_upper(char);
bool same_word(const char[], const char[]);
int compare_text(const char[], const char[]);

double floor_val(double);
double sqrt_val(double);
double pow_int(double, long long);
double round_val(double, int);

void set_error(int &, int &, int);
void error_text(int, char[]);
void format_num(double, char[]);
void value_to_text(int, double, const char[], int, char[]);
bool parse_number(const char[], double &);
bool parse_coord(const char[], int, int &, int &, bool &);
int func_id(const char[]);
void range_bounds(int, int, int, int, int &, int &, int &, int &);

int tokenize(const char[], int[], double[], char[][61], int[], int[], int[],
             int[], int[], int &);
int precedence(int);
bool right_assoc(int);
bool compare_values(int, int, double, const char[], int, double, const char[]);
void run_operator(int, int[], double[], char[][61], int[], int &);
bool pop_error_if_any(int, int, int[], int[], int[][26], int[][26], int[],
                      int[], int[], int[], int &);
void eval_list(int, int, int, int[][26], double[][26], char[][26][61],
               int[][26], int[], double[], char[][61], int[], int[], int[],
               int[], int[], int &);
void eval_math_func(int, int, int, int[], double[], int[], int &);
void run_function(int, int, int[][26], double[][26], char[][26][61], int[][26],
                  int[], double[], char[][61], int[], int[], int[], int[],
                  int[], int &);
void eval_formula(const char[], int[][26], double[][26], char[][26][61],
                  int[][26], int &, double &, char[], int &);
bool deps_ready(int[], int[], int[], int[], int[], int, bool[]);
void recalc_all(char[][26][61], int[][26], double[][26], char[][26][61],
                int[][26], char[][26][61]);

void cell_label(int, int, char[]);
int col_width(int, int, int, char[][26][61], int, int);
int fit_cols(int, int, int, char[][26][61], int, int, int[], int[]);
void print_hline(int, int[]);
void render_sheet(char[][26][61], int[][26], char[][26][61], int, int, int &,
                  int &, bool);

int main() {

  int choice;

  cout << "\nEnter the question that you want to run(1-8) and 9 for bonus: ";
  cin >> choice;

  switch (choice) {

  case 1:
    question1();
    break;
  case 2:
    question2();
    break;
  case 3:
    question3();
    break;
  case 4:
    question4();
    break;
  case 5:
    question5();
    break;
  case 6:
    question6();
    break;
  case 7:
    question7();
    break;
  case 8:
    question8();
    break;
  case 9:
    question9();
    break;
  default:
    cout << "\nInvalid choice!";
  }

  return 0;
}

// answers

void question1() {

  int n;
  cout << "\nEnter n: ";
  cin >> n;
  if ((n <= 2) || !(n & 1)) {
    cout << "\nInvalid input!\n";
    return;
  }

  int bound = n;

  cout << "\n";

  for (int i = 1; i <= bound; i++) {
    for (int j = 1; j <= bound; j++) {
      int d = min(min(i, min(j, bound - j + 1)), bound - i + 1);
      cout << d % 10 << " ";
    }
    cout << "\n";
  }
}

void question2() {
  int y = 1;
  int m = 1;

  cout << "Year::: ";
  cin >> y;
  cout << "Month::: ";
  cin >> m;
  cout << "\n\n";

  if ((y < 1) || (y > 9999) || (m < 1) || (m > 12)) {
    cout << "Invalid date entered!";
    return;
  }

  cout << "\t\b\b";

  switch (m) {
  case 1:
    cout << "January " << y << "\n";
    print_calendar(m, y);
    break;
  case 2:
    cout << "February " << y << "\n";
    print_calendar(m, y);
    break;
  case 3:
    cout << "March " << y << '\n';
    print_calendar(m, y);
    break;
  case 4:
    cout << "April " << y << '\n';
    print_calendar(m, y);
    break;
  case 5:
    cout << "May " << y << "\n";
    print_calendar(m, y);
    break;
  case 6:
    cout << "June " << y << "\n";
    print_calendar(m, y);
    break;
  case 7:
    cout << "July " << y << "\n";
    print_calendar(m, y);
    break;
  case 8:
    cout << "August " << y << "\n";
    print_calendar(m, y);
    break;
  case 9:
    cout << "September " << y << "\n";
    print_calendar(m, y);
    break;
  case 10:
    cout << "October " << y << "\n";
    print_calendar(m, y);
    break;
  case 11:
    cout << "November " << y << "\n";
    print_calendar(m, y);
    break;
  case 12:
    cout << "December " << y << "\n";
    print_calendar(m, y);
    break;
  }

  cout << "\n";
}

void question3() {

  int n;

  cout << "\nEnter n: ";
  cin >> n;

  if ((n <= 2) || !(n & 1)) {
    cout << "\nInvalid input!";
    return;
  }

  int correction = (n - 1) % 4;

  for (int i = 1; i <= n; i++) {
    row(i, n, correction);
  }

  for (int i = n - 1; i >= 1; i--) {
    row(i, n, correction);
  }
}

void question4() {
  int n, base, seed;

  cout << "\nN: ";
  cin >> n;
  cout << "Base: ";
  cin >> base;
  cout << "Seed: ";
  cin >> seed;

  if (n < 1 || base < 2 || base > 16) {
    cout << "\nInvalid input!\n";
    return;
  }

  cout << "\n";

  for (int i = 1; i <= 2 * n - 1; i++) {
    for (int j = 1; j <= 2 * n - 1; j++) {
      cout << display_value(position_value(j - n, i - n, seed, base)) << " ";
    }
    cout << "\n";
  }
}

void question5() {

  int n;
  cin >> n;

  if (n < 2 || n > 10) {
    cout << "\nInvalid grid size!\n";
    return;
  }

  long long r0 = 0, r1 = 0, r2 = 0, r3 = 0, r4 = 0;
  long long r5 = 0, r6 = 0, r7 = 0, r8 = 0, r9 = 0;

  int gold = 0;
  bool reached_exit = false;

  for (int r = 0; r < n; r++) {
    for (int c = 0; c < n; c++) {
      char tile;
      cin >> tile;

      int code = 0;
      if (tile == '*')
        code = 1;
      else if (tile == 'G')
        code = 2;
      else if (tile == 'E')
        code = 4;
      else if (tile == 'S')
        code = 5;

      set_cell(r, c, code, r0, r1, r2, r3, r4, r5, r6, r7, r8, r9);
    }
  }

  cout << "\n";

  bool expanded = true;
  while (expanded) {
    expanded = false;

    for (int r = 0; r < n; r++) {
      for (int c = 0; c < n; c++) {
        if (get_cell(r, c, r0, r1, r2, r3, r4, r5, r6, r7, r8, r9) != 5)
          continue;

        for (int side = 0; side < 4; side++) {
          int next_r = r;
          int next_c = c;

          if (side == 0)
            next_r--;
          else if (side == 1)
            next_r++;
          else if (side == 2)
            next_c--;
          else
            next_c++;

          if (next_r < 0 || next_r >= n || next_c < 0 || next_c >= n)
            continue;

          int cell =
              get_cell(next_r, next_c, r0, r1, r2, r3, r4, r5, r6, r7, r8, r9);

          if (cell == 0 || cell == 2 || cell == 4) {
            if (cell == 2)
              gold++;
            else if (cell == 4)
              reached_exit = true;

            set_cell(next_r, next_c, 5, r0, r1, r2, r3, r4, r5, r6, r7, r8, r9);
            expanded = true;
          }
        }
      }
    }
  }

  cout << "Solvable: " << (reached_exit ? "YES" : "NO") << "\n";
  cout << "Gold reachable: " << gold << "\n";
}

void question6() {

  const int PROCESSES = 100;
  const int MEMORY = 100;

  int pid[PROCESSES] = {0};
  int arrival_time[PROCESSES] = {0};
  int burst_time[PROCESSES] = {0};
  int remaining_burst_time[PROCESSES] = {0};
  int priority[PROCESSES] = {0};
  int completion_time[PROCESSES] = {0};
  int turnaround_time[PROCESSES] = {0};
  int waiting_time[PROCESSES] = {0};
  int memory_requirement[PROCESSES] = {0};
  int process_status[PROCESSES] = {0};

  int memory[MEMORY] = {0};

  int registered_processes = 0, successful_allocations = 0,
      failed_allocations = 0;

  int choice = 0;

  while (true) {
    cout << "\n===== CRUEL ANGEL'S THESIS: NERV OS RECOVERY =====\n";
    cout << "\n1. Register process\n2. Display processes\n3. Search process\n"
         << "4. Allocate memory to a process\n5. Terminate process\n"
         << "6. Display memory\n7. Compact memory\n8. Run FCFS\n9. Run SJF\n"
         << "10. Run Round Robin\n11. System statistics\n0. Exit\nChoice: ";
    cin >> choice;

    switch (choice) {
    case 0:
      cout << "\nNERV OS recovery simulator shutting down.\n";
      return;

    case 1: {
      if (registered_processes >= PROCESSES) {
        cout << "\nMaximum process capacity reached!\n";
        break;
      }
      cout << "\nArrival time, burst time, priority, memory requirement: ";
      cin >> arrival_time[registered_processes] >>
          burst_time[registered_processes] >> priority[registered_processes] >>
          memory_requirement[registered_processes];

      if (arrival_time[registered_processes] < 0 ||
          burst_time[registered_processes] <= 0 ||
          memory_requirement[registered_processes] <= 0) {
        cout << "Invalid process parameters!\n";
        break;
      }

      pid[registered_processes] = 101 + registered_processes;
      remaining_burst_time[registered_processes] =
          burst_time[registered_processes];

      if (allocate_memory(memory, MEMORY, pid[registered_processes],
                          memory_requirement[registered_processes])) {
        process_status[registered_processes] = 1;
        successful_allocations++;
        cout << "Process registered. PID = " << pid[registered_processes]
             << "; memory allocated.\n";

      } else {
        process_status[registered_processes] = 0;
        failed_allocations++;
        cout << "Process registered as NoMemory. Allocation failed; try "
                "compaction or retry allocation later. PID = "
             << pid[registered_processes] << "\n";
      }

      registered_processes++;
      break;
    }

    case 2: {
      int mode, status = -1;

      cout << "1. All   2. By status (0=New, 1=Ready, 2=Running, "
              "3=Terminated): ";
      cin >> mode;

      if (mode == 2) {
        cout << "Status: ";
        cin >> status;
      }

      for (int i = 0; i < registered_processes; i++) {
        if (mode == 1 || process_status[i] == status)
          process_info(i, pid, arrival_time, burst_time, priority,
                       memory_requirement, process_status);
      }

      break;
    }

    case 3: {
      int target;
      cout << "PID: ";
      cin >> target;
      int position = find_process(pid, registered_processes, target);
      if (position == -1)
        cout << "Not found.\n";
      else
        process_info(position, pid, arrival_time, burst_time, priority,
                     memory_requirement, process_status);

      break;
    }

    case 4: {
      int target;

      cout << "PID to allocate memory for: ";
      cin >> target;

      int position = find_process(pid, registered_processes, target);
      if (position == -1 || process_status[position] == 3)
        cout << "Invalid or terminated PID.\n";
      else if (process_status[position] == 1)
        cout << "Already allocated.\n";
      else if (allocate_memory(memory, MEMORY, pid[position],
                               memory_requirement[position])) {
        process_status[position] = 1;
        successful_allocations++;
        cout << "Memory allocation successful. Process is Ready.\n";
      } else {
        failed_allocations++;
        cout << "Allocation failed. Free memory = "
             << amount_of_free_memory(memory, MEMORY) << "; largest region = "
             << largest_free_consecutive_memory(memory, MEMORY) << '\n';
      }

      break;
    }

    case 5: {
      int target;
      cout << "PID to terminate: ";
      cin >> target;

      int position = find_process(pid, registered_processes, target);

      if (position == -1 || process_status[position] == 3)
        cout << "Invalid or already terminated PID.\n";
      else {
        free_memory(memory, MEMORY, target);
        process_status[position] = 3;
        cout << "Process terminated and its memory released.\n";
      }

      break;
    }

    case 6:
      display_memory(memory, MEMORY);
      break;

    case 7:
      memory_compaction(memory, MEMORY);
      break;

    case 8:
      non_preemptive(1, registered_processes, pid, arrival_time, burst_time,
                     remaining_burst_time, completion_time, turnaround_time,
                     waiting_time, process_status);
      break;

    case 9:
      non_preemptive(2, registered_processes, pid, arrival_time, burst_time,
                     remaining_burst_time, completion_time, turnaround_time,
                     waiting_time, process_status);
      break;

    case 10:
      round_robin(registered_processes, pid, arrival_time, burst_time,
                  remaining_burst_time, completion_time, turnaround_time,
                  waiting_time, process_status);
      break;

    case 11:
      stats(registered_processes, process_status, memory, MEMORY,
            successful_allocations, failed_allocations, completion_time,
            turnaround_time, waiting_time);
      break;

    default:
      cout << "Invalid Choice!\n";
      break;
    }
  }
}

void question7() {
  char board[6][7];
  clear_board(board);
  show_board(board);

  while (true) {
    int col;
    cout << "Enter column (0-6): ";
    cin >> col;
    while (!valid_move(board, col)) {
      cout << "Invalid or full column!\nEnter column (0-6): ";
      cin >> col;
    }

    place_piece(board, col, 'X');
    show_board(board);

    if (has_won(board, 'X')) {
      cout << "Human wins!\n";
      break;
    }
    if (board_full(board)) {
      cout << "Draw!\n";
      break;
    }

    int ai_col = best_move(board);
    place_piece(board, ai_col, 'O');
    cout << "Computer plays column " << ai_col << ":\n";
    show_board(board);

    if (has_won(board, 'O')) {
      cout << "Computer wins!\n";
      break;
    }
    if (board_full(board)) {
      cout << "Draw!\n";
      break;
    }
  }
}

void question8() {
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

  return;
}

void question9() {
  char raw[51][26][61];
  int type[51][26];
  double num[51][26];
  char text[51][26][61];
  int err[51][26];
  char shown[51][26][61];

  for (int r = 0; r < 51; r++) {
    for (int c = 0; c < 26; c++) {
      raw[r][c][0] = '\0';
      type[r][c] = 0;
      num[r][c] = 0.0;
      text[r][c][0] = '\0';
      err[r][c] = 0;
      shown[r][c][0] = '\0';
    }
  }

  int cur_r = 0, cur_c = 0;
  int top_row = 0, left_col = 0;

  while (true) {
    clearScreen();
    render_sheet(raw, type, shown, cur_r, cur_c, top_row, left_col, false);

    int key = cellsReadKey();
    if (key == KEY_UP) {
      if (cur_r > 0)
        cur_r--;
    } else if (key == KEY_DOWN) {
      if (cur_r < 50)
        cur_r++;
    } else if (key == KEY_LEFT) {
      if (cur_c > 0)
        cur_c--;
    } else if (key == KEY_RIGHT) {
      if (cur_c < 25)
        cur_c++;
    } else if (key == KEY_DELETE) {
      raw[cur_r][cur_c][0] = '\0';
      recalc_all(raw, type, num, text, err, shown);
    } else if (key == KEY_ENTER) {
      clearScreen();
      render_sheet(raw, type, shown, cur_r, cur_c, top_row, left_col, true);

      char line[512];
      cin.getline(line, 512);
      if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
      }

      char clean[61];
      int count = 0;
      for (int i = 0; line[i] != '\0' && count < 60; i++) {
        unsigned char ch = (unsigned char)line[i];
        if (ch >= 32 && ch <= 126)
          clean[count++] = (char)ch;
      }
      clean[count] = '\0';

      if (count > 0) {
        str_copy(raw[cur_r][cur_c], clean, 61);
        recalc_all(raw, type, num, text, err, shown);
      }
    } else if (key == 'q' || key == 'Q') {
      clearScreen();
      return;
    }
  }
}

// utility functions

// for question 9
int str_len(const char s[]) {
  int n = 0;
  while (s[n] != '\0')
    n++;
  return n;
}

void str_copy(char dst[], const char src[], int limit) {
  int i = 0;
  while (i < limit - 1 && src[i] != '\0') {
    dst[i] = src[i];
    i++;
  }
  dst[i] = '\0';
}

char to_upper(char c) {
  if (c >= 'a' && c <= 'z')
    return (char)(c - 'a' + 'A');
  return c;
}

bool same_word(const char a[], const char b[]) {
  int i = 0;
  while (a[i] != '\0' && b[i] != '\0') {
    if (to_upper(a[i]) != to_upper(b[i]))
      return false;
    i++;
  }
  return (a[i] == '\0' && b[i] == '\0');
}

int compare_text(const char a[], const char b[]) {
  int i = 0;
  while (a[i] != '\0' && b[i] != '\0') {
    if ((unsigned char)a[i] < (unsigned char)b[i])
      return -1;
    if ((unsigned char)a[i] > (unsigned char)b[i])
      return 1;
    i++;
  }
  if (a[i] == '\0' && b[i] == '\0')
    return 0;
  return (a[i] == '\0') ? -1 : 1;
}

double floor_val(double x) {
  if (abs(x) >= 4.5e15)
    return x;
  long long i = (long long)x;
  if ((double)i > x)
    i--;
  return (double)i;
}

double sqrt_val(double x) {
  if (x == 0.0)
    return 0.0;
  double g = max(x, 1.0);
  for (int i = 0; i < 60; i++)
    g = 0.5 * (g + x / g);
  return g;
}

double pow_int(double base, long long exp) {
  if (exp == 0)
    return 1.0;
  bool neg = (exp < 0);
  unsigned long long e =
      neg ? (unsigned long long)(-exp) : (unsigned long long)exp;
  double res = 1.0;
  while (e > 0) {
    if (e & 1ULL)
      res *= base;
    base *= base;
    e >>= 1ULL;
  }
  return neg ? (1.0 / res) : res;
}

double round_val(double x, int d) {
  double factor = pow_int(10.0, d);
  double scaled = x * factor;
  if (abs(scaled) >= 4.5e15)
    return x;
  if (scaled >= 0.0)
    scaled = floor_val(scaled + 0.5);
  else
    scaled = -floor_val(-scaled + 0.5);
  return scaled / factor;
}

void set_error(int &t, int &e, int code) {
  t = 3;
  e = code;
}

void error_text(int code, char out[]) {
  if (code == 1)
    str_copy(out, "#SYNTAX!", 61);
  else if (code == 2)
    str_copy(out, "#NAME?", 61);
  else if (code == 3)
    str_copy(out, "#REF!", 61);
  else if (code == 4)
    str_copy(out, "#VALUE!", 61);
  else if (code == 5)
    str_copy(out, "#DIV/0!", 61);
  else if (code == 6)
    str_copy(out, "#NUM!", 61);
  else if (code == 7)
    str_copy(out, "#CYCLE!", 61);
  else
    out[0] = '\0';
}

void format_num(double val, char out[]) {
  double r = round_val(val, 4);
  if (abs(val) >= 1e15 || abs(r) >= 1e15) {
    error_text(6, out);
    return;
  }
  if (abs(r) < 1e-9)
    r = 0.0;

  int pos = 0;
  if (r < 0.0) {
    out[pos++] = '-';
    r = -r;
  }

  long long scaled = (long long)floor_val(r * 10000.0 + 0.5);
  long long whole = scaled / 10000;
  long long frac = scaled % 10000;

  char digits[32];
  int d_count = 0;
  if (whole == 0) {
    digits[d_count++] = '0';
  } else {
    while (whole > 0) {
      digits[d_count++] = (char)('0' + (whole % 10));
      whole /= 10;
    }
  }
  for (int i = d_count - 1; i >= 0 && pos < 60; i--)
    out[pos++] = digits[i];

  if (frac > 0 && pos < 56) {
    out[pos++] = '.';
    int f[4] = {(int)((frac / 1000) % 10), (int)((frac / 100) % 10),
                (int)((frac / 10) % 10), (int)(frac % 10)};
    int last = 3;
    while (last >= 0 && f[last] == 0)
      last--;
    for (int i = 0; i <= last && pos < 60; i++)
      out[pos++] = (char)('0' + f[i]);
  }
  out[pos] = '\0';
}

void value_to_text(int t, double n, const char s[], int e, char out[]) {
  if (t == 0)
    out[0] = '\0';
  else if (t == 1)
    format_num(n, out);
  else if (t == 2)
    str_copy(out, s, 61);
  else
    error_text(e, out);
}

bool parse_number(const char s[], double &out) {
  int i = 0;
  if (s[i] == '\0')
    return false;
  bool neg = (s[i] == '-');
  if (neg)
    i++;

  int int_digits = 0;
  double val = 0.0;
  while (s[i] >= '0' && s[i] <= '9') {
    val = val * 10.0 + (s[i] - '0');
    int_digits++;
    i++;
  }

  int frac_digits = 0;
  if (s[i] == '.') {
    i++;
    double place = 0.1;
    while (s[i] >= '0' && s[i] <= '9') {
      val += (s[i] - '0') * place;
      place *= 0.1;
      frac_digits++;
      i++;
    }
    if (frac_digits == 0)
      return false;
  }

  if (int_digits == 0 || s[i] != '\0')
    return false;
  out = neg ? -val : val;
  return true;
}

bool parse_coord(const char s[], int len, int &r_out, int &c_out,
                 bool &looks_like_cell) {
  looks_like_cell = false;
  int i = 0, letters = 0, col = 0;
  while (i < len &&
         ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))) {
    col = col * 26 + (to_upper(s[i]) - 'A' + 1);
    letters++;
    i++;
  }
  if (letters == 0 || i >= len)
    return false;

  int row = 0, digits = 0;
  while (i < len && s[i] >= '0' && s[i] <= '9') {
    row = row * 10 + (s[i] - '0');
    digits++;
    i++;
  }
  if (digits == 0 || i != len)
    return false;

  looks_like_cell = true;
  col -= 1;
  if (letters == 1 && col >= 0 && col < 26 && row >= 0 && row < 51) {
    r_out = row;
    c_out = col;
    return true;
  }
  r_out = 0;
  c_out = 0;
  return false;
}

int func_id(const char name[]) {
  if (same_word(name, "SUM"))
    return 1;
  if (same_word(name, "AVG"))
    return 2;
  if (same_word(name, "MIN"))
    return 3;
  if (same_word(name, "MAX"))
    return 4;
  if (same_word(name, "COUNT"))
    return 5;
  if (same_word(name, "MEDIAN"))
    return 6;
  if (same_word(name, "CONCAT"))
    return 7;
  if (same_word(name, "ABS"))
    return 8;
  if (same_word(name, "ROUND"))
    return 9;
  if (same_word(name, "POW"))
    return 10;
  if (same_word(name, "SQRT"))
    return 11;
  if (same_word(name, "MOD"))
    return 12;
  if (same_word(name, "IF"))
    return 13;
  if (same_word(name, "LEN"))
    return 14;
  if (same_word(name, "UPPER"))
    return 15;
  return 0;
}

void range_bounds(int r1, int c1, int r2, int c2, int &r_lo, int &r_hi,
                  int &c_lo, int &c_hi) {
  r_lo = min(r1, r2);
  r_hi = max(r1, r2);
  c_lo = min(c1, c2);
  c_hi = max(c1, c2);
}

int tokenize(const char expr[], int kind[], double t_num[], char t_str[][61],
             int r1[], int c1[], int r2[], int c2[], int op[], int &count) {
  int saved_err = 0;
  count = 0;
  int i = 0, prev = 0;
  int paren_depth = 0;

  while (expr[i] != '\0') {
    if (expr[i] == ' ') {
      i++;
      continue;
    }
    if (count >= 120)
      return 1;

    char c = expr[i];
    bool need_val = (prev == 0 || prev == 6 || prev == 7 || prev == 9);

    if (c == '"') {
      if (!need_val)
        return 1;
      i++;
      int p = 0;
      while (expr[i] != '\0' && expr[i] != '"') {
        if (p < 60)
          t_str[count][p++] = expr[i];
        i++;
      }
      if (expr[i] != '"')
        return 1;
      i++;
      t_str[count][p] = '\0';
      kind[count] = 2;
      prev = 2;
      count++;
      continue;
    }

    if ((c >= '0' && c <= '9') || c == '.') {
      if (!need_val)
        return 1;
      char buf[64];
      int p = 0, dots = 0;
      while ((expr[i] >= '0' && expr[i] <= '9') || expr[i] == '.') {
        if (expr[i] == '.')
          dots++;
        if (p < 62)
          buf[p++] = expr[i];
        i++;
      }
      buf[p] = '\0';
      double val = 0.0;
      if (dots > 1 || !parse_number(buf, val))
        return 1;
      kind[count] = 1;
      t_num[count] = val;
      prev = 1;
      count++;
      continue;
    }

    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
      if (!need_val)
        return 1;
      char id1[64];
      int p1 = 0;
      while ((expr[i] >= 'A' && expr[i] <= 'Z') ||
             (expr[i] >= 'a' && expr[i] <= 'z') ||
             (expr[i] >= '0' && expr[i] <= '9')) {
        if (p1 < 62)
          id1[p1++] = expr[i];
        i++;
      }
      id1[p1] = '\0';

      int j = i;
      while (expr[j] == ' ')
        j++;

      if (expr[j] == ':') {
        i = j + 1;
        while (expr[i] == ' ')
          i++;
        char id2[64];
        int p2 = 0;
        while ((expr[i] >= 'A' && expr[i] <= 'Z') ||
               (expr[i] >= 'a' && expr[i] <= 'z') ||
               (expr[i] >= '0' && expr[i] <= '9')) {
          if (p2 < 62)
            id2[p2++] = expr[i];
          i++;
        }
        id2[p2] = '\0';

        int ra = 0, ca = 0, rb = 0, cb = 0;
        bool f1 = false, f2 = false;
        bool ok1 = parse_coord(id1, p1, ra, ca, f1);
        bool ok2 = parse_coord(id2, p2, rb, cb, f2);
        if (!f1 || !f2)
          return 1;
        if (!ok1 || !ok2) {
          if (saved_err == 0)
            saved_err = 3;
          ra = 0;
          ca = 0;
          rb = 0;
          cb = 0;
        }

        kind[count] = 4;
        r1[count] = ra;
        c1[count] = ca;
        r2[count] = rb;
        c2[count] = cb;
        prev = 4;
        count++;
        continue;
      }

      if (expr[j] == '(') {
        int fn = func_id(id1);
        if (fn == 0 && saved_err == 0)
          saved_err = 2;
        kind[count] = 5;
        op[count] = fn;
        prev = 5;
        count++;
        continue;
      }

      int ra = 0, ca = 0;
      bool f1 = false;
      bool ok1 = parse_coord(id1, p1, ra, ca, f1);
      if (!f1) {
        if (saved_err == 0)
          saved_err = 2;
        ra = 0;
        ca = 0;
      } else if (!ok1) {
        if (saved_err == 0)
          saved_err = 3;
        ra = 0;
        ca = 0;
      }

      kind[count] = 3;
      r1[count] = ra;
      c1[count] = ca;
      prev = 3;
      count++;
      continue;
    }

    if (c == '(') {
      if (!need_val && prev != 5)
        return 1;
      paren_depth++;
      kind[count] = 7;
      prev = 7;
      count++;
      i++;
      continue;
    }

    if (c == ')') {
      if (need_val && prev != 7)
        return 1;
      paren_depth--;
      if (paren_depth < 0)
        return 1;
      kind[count] = 8;
      prev = 8;
      count++;
      i++;
      continue;
    }

    if (c == ',') {
      if (need_val || paren_depth <= 0)
        return 1;
      kind[count] = 9;
      prev = 9;
      count++;
      i++;
      continue;
    }

    int code = 0, step = 1;
    if (c == '^')
      code = 1;
    else if (c == '*')
      code = 3;
    else if (c == '/')
      code = 4;
    else if (c == '+')
      code = 5;
    else if (c == '-')
      code = need_val ? 2 : 6;
    else if (c == '=')
      code = 7;
    else if (c == '<') {
      if (expr[i + 1] == '>') {
        code = 8;
        step = 2;
      } else if (expr[i + 1] == '=') {
        code = 11;
        step = 2;
      } else
        code = 9;
    } else if (c == '>') {
      if (expr[i + 1] == '=') {
        code = 12;
        step = 2;
      } else
        code = 10;
    } else {
      return 1;
    }

    if (code != 2 && need_val)
      return 1;
    kind[count] = 6;
    op[count] = code;
    prev = 6;
    count++;
    i += step;
  }

  if (count == 0 || paren_depth != 0 || prev == 6 || prev == 7 || prev == 9 ||
      prev == 5)
    return 1;
  return saved_err;
}

int precedence(int op) {
  if (op == 1)
    return 5;
  if (op == 2)
    return 4;
  if (op == 3 || op == 4)
    return 3;
  if (op == 5 || op == 6)
    return 2;
  return 1;
}

bool right_assoc(int op) { return (op == 1 || op == 2); }

bool compare_values(int op, int t1, double n1, const char s1[], int t2,
                    double n2, const char s2[]) {
  if (t1 == 0 && t2 == 0)
    return (op == 7 || op == 11 || op == 12);

  int cmp = 0;
  if (t1 == 2 || t2 == 2) {
    cmp = compare_text((t1 == 2) ? s1 : "", (t2 == 2) ? s2 : "");
  } else {
    double a = (t1 == 0) ? 0.0 : n1;
    double b = (t2 == 0) ? 0.0 : n2;
    cmp = (a < b) ? -1 : ((a > b) ? 1 : 0);
  }

  if (op == 7)
    return cmp == 0;
  if (op == 8)
    return cmp != 0;
  if (op == 9)
    return cmp < 0;
  if (op == 10)
    return cmp > 0;
  if (op == 11)
    return cmp <= 0;
  return cmp >= 0;
}

void run_operator(int op, int vt[], double vn[], char vs[][61], int ve[],
                  int &top) {
  if (op == 2) {
    if (top < 0 || vt[top] == 3)
      return;
    if (vt[top] == -1 || vt[top] == 2) {
      set_error(vt[top], ve[top], 4);
      return;
    }
    double x = (vt[top] == 0) ? 0.0 : vn[top];
    vt[top] = 1;
    vn[top] = -x;
    return;
  }

  if (top < 1)
    return;
  int t2 = vt[top], e2 = ve[top];
  double n2 = vn[top];
  char s2[61];
  str_copy(s2, vs[top], 61);
  top--;

  int t1 = vt[top], e1 = ve[top];
  double n1 = vn[top];
  char s1[61];
  str_copy(s1, vs[top], 61);

  if (t1 == 3) {
    set_error(vt[top], ve[top], e1);
    return;
  }
  if (t2 == 3) {
    set_error(vt[top], ve[top], e2);
    return;
  }
  if (t1 == -1 || t2 == -1) {
    set_error(vt[top], ve[top], 4);
    return;
  }

  if (op >= 7 && op <= 12) {
    if ((t1 == 2 && t2 == 1) || (t1 == 1 && t2 == 2)) {
      set_error(vt[top], ve[top], 4);
      return;
    }
    vt[top] = 1;
    vn[top] = compare_values(op, t1, n1, s1, t2, n2, s2) ? 1.0 : 0.0;
    return;
  }

  if (t1 == 2 || t2 == 2) {
    set_error(vt[top], ve[top], 4);
    return;
  }

  double a = (t1 == 0) ? 0.0 : n1;
  double b = (t2 == 0) ? 0.0 : n2;
  double res = 0.0;

  if (op == 5)
    res = a + b;
  else if (op == 6)
    res = a - b;
  else if (op == 3)
    res = a * b;
  else if (op == 4) {
    if (b == 0.0) {
      set_error(vt[top], ve[top], 5);
      return;
    }
    res = a / b;
  } else if (op == 1) {
    long long ib = (long long)b;
    if ((double)ib != b || (a == 0.0 && ib < 0)) {
      set_error(vt[top], ve[top], 6);
      return;
    }
    res = pow_int(a, ib);
  }

  if (abs(res) >= 1e15) {
    set_error(vt[top], ve[top], 6);
    return;
  }

  vt[top] = 1;
  vn[top] = res;
}

bool pop_error_if_any(int base, int last, int vt[], int ve[], int c_type[][26],
                      int c_err[][26], int vr1[], int vc1[], int vr2[],
                      int vc2[], int &top) {
  for (int i = base; i <= last; i++) {
    if (vt[i] == 3) {
      int e = ve[i];
      top = base;
      set_error(vt[top], ve[top], e);
      return true;
    }
    if (vt[i] == -1) {
      int r_lo, r_hi, c_lo, c_hi;
      range_bounds(vr1[i], vc1[i], vr2[i], vc2[i], r_lo, r_hi, c_lo, c_hi);
      for (int r = r_lo; r <= r_hi; r++) {
        for (int c = c_lo; c <= c_hi; c++) {
          if (c_type[r][c] == 3) {
            int e = c_err[r][c];
            top = base;
            set_error(vt[top], ve[top], e);
            return true;
          }
        }
      }
    }
  }
  return false;
}

void eval_list(int fn, int base, int last, int c_type[][26], double c_num[][26],
               char c_str[][26][61], int c_err[][26], int vt[], double vn[],
               char vs[][61], int ve[], int vr1[], int vc1[], int vr2[],
               int vc2[], int &top) {
  if (fn == 7) {
    char joined[61];
    int pos = 0;
    joined[0] = '\0';
    for (int i = base; i <= last; i++) {
      if (vt[i] == -1) {
        int r_lo, r_hi, c_lo, c_hi;
        range_bounds(vr1[i], vc1[i], vr2[i], vc2[i], r_lo, r_hi, c_lo, c_hi);
        for (int r = r_lo; r <= r_hi; r++) {
          for (int c = c_lo; c <= c_hi; c++) {
            char tmp[61];
            value_to_text(c_type[r][c], c_num[r][c], c_str[r][c], c_err[r][c],
                          tmp);
            for (int k = 0; tmp[k] != '\0' && pos < 60; k++)
              joined[pos++] = tmp[k];
          }
        }
      } else {
        char tmp[61];
        value_to_text(vt[i], vn[i], vs[i], ve[i], tmp);
        for (int k = 0; tmp[k] != '\0' && pos < 60; k++)
          joined[pos++] = tmp[k];
      }
    }
    joined[pos] = '\0';
    top = base;
    vt[top] = 2;
    str_copy(vs[top], joined, 61);
    return;
  }

  double list[1400];
  int n_count = 0;
  for (int i = base; i <= last; i++) {
    if (vt[i] == -1) {
      int r_lo, r_hi, c_lo, c_hi;
      range_bounds(vr1[i], vc1[i], vr2[i], vc2[i], r_lo, r_hi, c_lo, c_hi);
      for (int r = r_lo; r <= r_hi; r++) {
        for (int c = c_lo; c <= c_hi; c++) {
          if (c_type[r][c] == 1 && n_count < 1400)
            list[n_count++] = c_num[r][c];
        }
      }
    } else if (vt[i] == 1 && n_count < 1400) {
      list[n_count++] = vn[i];
    }
  }

  top = base;
  if (fn == 5) {
    vt[top] = 1;
    vn[top] = (double)n_count;
    return;
  }

  if (fn == 1 || fn == 2) {
    if (fn == 2 && n_count == 0) {
      set_error(vt[top], ve[top], 5);
      return;
    }
    double s = 0.0;
    for (int k = 0; k < n_count; k++)
      s += list[k];
    if (abs(s) >= 1e15) {
      set_error(vt[top], ve[top], 6);
      return;
    }
    vt[top] = 1;
    vn[top] = (fn == 1) ? s : (s / n_count);
    return;
  }

  if (fn == 3 || fn == 4) {
    if (n_count == 0) {
      vt[top] = 1;
      vn[top] = 0.0;
      return;
    }
    double m = list[0];
    for (int k = 1; k < n_count; k++)
      m = (fn == 3) ? min(m, list[k]) : max(m, list[k]);
    vt[top] = 1;
    vn[top] = m;
    return;
  }

  if (n_count == 0) {
    set_error(vt[top], ve[top], 6);
    return;
  }
  for (int a = 0; a < n_count - 1; a++) {
    for (int b = 0; b < n_count - 1 - a; b++) {
      if (list[b] > list[b + 1]) {
        double tmp = list[b];
        list[b] = list[b + 1];
        list[b + 1] = tmp;
      }
    }
  }
  vt[top] = 1;
  vn[top] = (n_count % 2 == 1)
                ? list[n_count / 2]
                : 0.5 * (list[n_count / 2 - 1] + list[n_count / 2]);
}

void eval_math_func(int fn, int argc, int base, int vt[], double vn[], int ve[],
                    int &top) {
  for (int i = base; i < base + argc; i++) {
    if (vt[i] == 2) {
      top = base;
      set_error(vt[top], ve[top], 4);
      return;
    }
  }

  double x1 = (vt[base] == 0) ? 0.0 : vn[base];
  double x2 = (argc >= 2) ? ((vt[base + 1] == 0) ? 0.0 : vn[base + 1]) : 0.0;
  top = base;

  if (fn == 8) {
    vt[top] = 1;
    vn[top] = abs(x1);
  } else if (fn == 9) {
    int d = (int)x2;
    if ((double)d != x2 || d < 0 || d > 9) {
      set_error(vt[top], ve[top], 4);
      return;
    }
    vt[top] = 1;
    vn[top] = round_val(x1, d);
  } else if (fn == 10) {
    long long n = (long long)x2;
    if ((double)n != x2 || (x1 == 0.0 && n < 0)) {
      set_error(vt[top], ve[top], 6);
      return;
    }
    double res = pow_int(x1, n);
    if (abs(res) >= 1e15) {
      set_error(vt[top], ve[top], 6);
      return;
    }
    vt[top] = 1;
    vn[top] = res;
  } else if (fn == 11) {
    if (x1 < 0.0) {
      set_error(vt[top], ve[top], 6);
      return;
    }
    vt[top] = 1;
    vn[top] = sqrt_val(x1);
  } else if (fn == 12) {
    if (x2 == 0.0) {
      set_error(vt[top], ve[top], 5);
      return;
    }
    vt[top] = 1;
    vn[top] = x1 - x2 * floor_val(x1 / x2 + 1e-12);
  }
}

void run_function(int fn, int argc, int c_type[][26], double c_num[][26],
                  char c_str[][26][61], int c_err[][26], int vt[], double vn[],
                  char vs[][61], int ve[], int vr1[], int vc1[], int vr2[],
                  int vc2[], int &top) {
  int base = top - argc + 1;
  if (argc <= 0 || base < 0) {
    top = max(0, base);
    set_error(vt[top], ve[top], 4);
    return;
  }

  if (pop_error_if_any(base, top, vt, ve, c_type, c_err, vr1, vc1, vr2, vc2,
                       top))
    return;

  if (fn >= 1 && fn <= 7) {
    eval_list(fn, base, top, c_type, c_num, c_str, c_err, vt, vn, vs, ve, vr1,
              vc1, vr2, vc2, top);
    return;
  }

  for (int i = base; i <= top; i++) {
    if (vt[i] == -1) {
      top = base;
      set_error(vt[top], ve[top], 4);
      return;
    }
  }

  int need_args = (fn == 13) ? 3 : ((fn == 9 || fn == 10 || fn == 12) ? 2 : 1);
  if (argc != need_args) {
    top = base;
    set_error(vt[top], ve[top], 4);
    return;
  }

  if (fn == 13) {
    if (vt[base] == 2) {
      top = base;
      set_error(vt[top], ve[top], 4);
      return;
    }
    double cond = (vt[base] == 0) ? 0.0 : vn[base];
    int pick = (cond != 0.0) ? (base + 1) : (base + 2);
    vt[base] = vt[pick];
    vn[base] = vn[pick];
    str_copy(vs[base], vs[pick], 61);
    ve[base] = ve[pick];
    top = base;
    return;
  }

  if (fn == 14 || fn == 15) {
    char tmp[61];
    value_to_text(vt[base], vn[base], vs[base], ve[base], tmp);
    top = base;
    if (fn == 14) {
      vt[top] = 1;
      vn[top] = (double)str_len(tmp);
    } else {
      for (int k = 0; tmp[k] != '\0'; k++)
        tmp[k] = to_upper(tmp[k]);
      vt[top] = 2;
      str_copy(vs[top], tmp, 61);
    }
    return;
  }

  eval_math_func(fn, argc, base, vt, vn, ve, top);
}

void eval_formula(const char expr[], int c_type[][26], double c_num[][26],
                  char c_str[][26][61], int c_err[][26], int &out_t,
                  double &out_n, char out_s[], int &out_e) {
  int kind[125], r1[125], c1[125], r2[125], c2[125], op[125];
  double t_num[125];
  char t_str[125][61];
  int count = 0;

  int lex_err = tokenize(expr, kind, t_num, t_str, r1, c1, r2, c2, op, count);
  if (lex_err != 0) {
    set_error(out_t, out_e, lex_err);
    return;
  }

  int vt[125], ve[125], vr1[125], vc1[125], vr2[125], vc2[125];
  double vn[125];
  char vs[125][61];
  int v_top = -1;

  int op_stack[125], arg_stack[125];
  int o_top = -1;

  for (int i = 0; i < count; i++) {
    int k = kind[i];

    if (k == 1) {
      v_top++;
      vt[v_top] = 1;
      vn[v_top] = t_num[i];
      vs[v_top][0] = '\0';
      ve[v_top] = 0;
    } else if (k == 2) {
      v_top++;
      vt[v_top] = 2;
      str_copy(vs[v_top], t_str[i], 61);
      ve[v_top] = 0;
    } else if (k == 3) {
      int r = r1[i], c = c1[i];
      v_top++;
      vt[v_top] = c_type[r][c];
      vn[v_top] = c_num[r][c];
      str_copy(vs[v_top], c_str[r][c], 61);
      ve[v_top] = c_err[r][c];
    } else if (k == 4) {
      if (o_top < 0 || op_stack[o_top] >= 0) {
        set_error(out_t, out_e, 4);
        return;
      }
      v_top++;
      vt[v_top] = -1;
      vr1[v_top] = r1[i];
      vc1[v_top] = c1[i];
      vr2[v_top] = r2[i];
      vc2[v_top] = c2[i];
      ve[v_top] = 0;
    } else if (k == 5) {
      o_top++;
      op_stack[o_top] = -op[i];
      arg_stack[o_top] = 1;
    } else if (k == 7) {
      if (o_top >= 0 && op_stack[o_top] < 0 && i > 0 && kind[i - 1] == 5) {
        if (i + 1 < count && kind[i + 1] == 8)
          arg_stack[o_top] = 0;
      } else {
        o_top++;
        op_stack[o_top] = 0;
        arg_stack[o_top] = 0;
      }
    } else if (k == 9) {
      while (o_top >= 0 && op_stack[o_top] > 0)
        run_operator(op_stack[o_top--], vt, vn, vs, ve, v_top);
      if (o_top < 0 || op_stack[o_top] >= 0) {
        set_error(out_t, out_e, 1);
        return;
      }
      arg_stack[o_top]++;
    } else if (k == 8) {
      while (o_top >= 0 && op_stack[o_top] > 0)
        run_operator(op_stack[o_top--], vt, vn, vs, ve, v_top);
      if (o_top < 0) {
        set_error(out_t, out_e, 1);
        return;
      }
      if (op_stack[o_top] == 0) {
        o_top--;
      } else if (op_stack[o_top] < 0) {
        int fn = -op_stack[o_top];
        int argc = arg_stack[o_top];
        o_top--;
        run_function(fn, argc, c_type, c_num, c_str, c_err, vt, vn, vs, ve, vr1,
                     vc1, vr2, vc2, v_top);
      }
    } else if (k == 6) {
      int cur = op[i];
      if (cur != 2) {
        while (o_top >= 0 && op_stack[o_top] > 0) {
          int top_op = op_stack[o_top];
          int p1 = precedence(cur);
          int p2 = precedence(top_op);
          if ((!right_assoc(cur) && p1 <= p2) || (right_assoc(cur) && p1 < p2))
            run_operator(op_stack[o_top--], vt, vn, vs, ve, v_top);
          else
            break;
        }
      }
      o_top++;
      op_stack[o_top] = cur;
      arg_stack[o_top] = 0;
    }
  }

  while (o_top >= 0) {
    if (op_stack[o_top] <= 0) {
      set_error(out_t, out_e, 1);
      return;
    }
    run_operator(op_stack[o_top--], vt, vn, vs, ve, v_top);
  }

  if (v_top != 0) {
    set_error(out_t, out_e, 1);
    return;
  }

  out_t = vt[0];
  out_n = vn[0];
  str_copy(out_s, vs[0], 61);
  out_e = ve[0];
}

bool deps_ready(int kind[], int r1[], int c1[], int r2[], int c2[], int count,
                bool done[]) {
  for (int t = 0; t < count; t++) {
    if (kind[t] == 3) {
      if (!done[r1[t] * 26 + c1[t]])
        return false;
    } else if (kind[t] == 4) {
      int r_lo, r_hi, c_lo, c_hi;
      range_bounds(r1[t], c1[t], r2[t], c2[t], r_lo, r_hi, c_lo, c_hi);
      for (int rr = r_lo; rr <= r_hi; rr++) {
        for (int cc = c_lo; cc <= c_hi; cc++) {
          if (!done[rr * 26 + cc])
            return false;
        }
      }
    }
  }
  return true;
}

void recalc_all(char raw[][26][61], int type[][26], double num[][26],
                char text[][26][61], int err[][26], char shown[][26][61]) {
  const int total = 51 * 26;
  bool is_formula[total];
  bool done[total];

  for (int idx = 0; idx < total; idx++) {
    int r = idx / 26;
    int c = idx % 26;
    is_formula[idx] = false;
    done[idx] = true;
    type[r][c] = 0;
    num[r][c] = 0.0;
    text[r][c][0] = '\0';
    err[r][c] = 0;

    if (raw[r][c][0] == '=') {
      is_formula[idx] = true;
      done[idx] = false;
    } else if (raw[r][c][0] != '\0') {
      double val = 0.0;
      if (parse_number(raw[r][c], val)) {
        if (abs(val) >= 1e15) {
          set_error(type[r][c], err[r][c], 6);
        } else {
          type[r][c] = 1;
          num[r][c] = val;
        }
      } else {
        type[r][c] = 2;
        str_copy(text[r][c], raw[r][c], 61);
      }
    }
  }

  bool changed = true;
  while (changed) {
    changed = false;
    for (int idx = 0; idx < total; idx++) {
      if (!is_formula[idx] || done[idx])
        continue;

      int r = idx / 26;
      int c = idx % 26;

      int kind[125], r1[125], c1[125], r2[125], c2[125], op[125];
      double t_num[125];
      char t_str[125][61];
      int count = 0;

      int lex_err = tokenize(raw[r][c] + 1, kind, t_num, t_str, r1, c1, r2, c2,
                             op, count);
      if (lex_err != 0) {
        set_error(type[r][c], err[r][c], lex_err);
        done[idx] = true;
        changed = true;
        continue;
      }

      if (deps_ready(kind, r1, c1, r2, c2, count, done)) {
        eval_formula(raw[r][c] + 1, type, num, text, err, type[r][c], num[r][c],
                     text[r][c], err[r][c]);
        done[idx] = true;
        changed = true;
      }
    }
  }

  for (int idx = 0; idx < total; idx++) {
    if (is_formula[idx] && !done[idx]) {
      int r = idx / 26;
      int c = idx % 26;
      set_error(type[r][c], err[r][c], 7);
    }
  }

  for (int r = 0; r < 51; r++) {
    for (int c = 0; c < 26; c++)
      value_to_text(type[r][c], num[r][c], text[r][c], err[r][c], shown[r][c]);
  }
}

void cell_label(int r, int c, char out[]) {
  out[0] = (char)('A' + c);
  if (r < 10) {
    out[1] = (char)('0' + r);
    out[2] = '\0';
  } else {
    out[1] = (char)('0' + (r / 10));
    out[2] = (char)('0' + (r % 10));
    out[3] = '\0';
  }
}

int col_width(int col, int top_row, int vis_rows, char shown[][26][61],
              int cur_r, int cur_c) {
  int w = 8;
  for (int i = 0; i < vis_rows; i++) {
    int r = top_row + i;
    if (r >= 51)
      break;
    int len = str_len(shown[r][col]) + ((r == cur_r && col == cur_c) ? 2 : 0);
    w = max(w, len);
  }
  return w;
}

int fit_cols(int left_col, int top_row, int vis_rows, char shown[][26][61],
             int cur_r, int cur_c, int cols[], int widths[]) {
  int num_cols = 0, used = 5;
  for (int c = left_col; c < 26; c++) {
    int cw = col_width(c, top_row, vis_rows, shown, cur_r, cur_c);
    if (used + cw + 3 <= 115) {
      cols[num_cols] = c;
      widths[num_cols] = cw;
      num_cols++;
      used += cw + 3;
    } else {
      break;
    }
  }
  return num_cols;
}

void print_hline(int num_cols, int widths[]) {
  cout << "+----";
  for (int i = 0; i < num_cols; i++) {
    cout << "+";
    for (int k = 0; k < widths[i] + 2; k++)
      cout << '-';
  }
  cout << "+\n";
}

void render_sheet(char raw[][26][61], int type[][26], char shown[][26][61],
                  int cur_r, int cur_c, int &top_row, int &left_col,
                  bool editing) {
  const int vis_rows = 27;

  if (cur_r < top_row)
    top_row = cur_r;
  if (cur_r >= top_row + vis_rows)
    top_row = cur_r - vis_rows + 1;

  if (cur_c < left_col)
    left_col = cur_c;

  int cols[26], widths[26];
  int num_cols =
      fit_cols(left_col, top_row, vis_rows, shown, cur_r, cur_c, cols, widths);
  while (left_col < cur_c && (num_cols == 0 || cols[num_cols - 1] < cur_c)) {
    left_col++;
    num_cols = fit_cols(left_col, top_row, vis_rows, shown, cur_r, cur_c, cols,
                        widths);
  }

  char name[8];
  cell_label(cur_r, cur_c, name);

  cout << name << " > " << raw[cur_r][cur_c] << "\n";
  print_hline(num_cols, widths);

  cout << "|    ";
  for (int i = 0; i < num_cols; i++) {
    int w = widths[i];
    int pad_l = (w - 1) / 2;
    int pad_r = w - 1 - pad_l;
    cout << "| ";
    for (int p = 0; p < pad_l; p++)
      cout << ' ';
    cout << (char)('A' + cols[i]);
    for (int p = 0; p < pad_r; p++)
      cout << ' ';
    cout << ' ';
  }
  cout << "|\n";
  print_hline(num_cols, widths);

  for (int i = 0; i < vis_rows; i++) {
    int r = top_row + i;
    cout << "| ";
    if (r < 10)
      cout << ' ' << r << ' ';
    else
      cout << r << ' ';

    for (int j = 0; j < num_cols; j++) {
      int c = cols[j];
      int w = widths[j];
      bool active = (r == cur_r && c == cur_c);

      char buf[65];
      if (active) {
        buf[0] = '[';
        str_copy(buf + 1, shown[r][c], 61);
        int l = str_len(buf);
        buf[l] = ']';
        buf[l + 1] = '\0';
      } else {
        str_copy(buf, shown[r][c], 61);
      }

      int pad = max(0, w - str_len(buf));

      cout << "| ";
      if (type[r][c] == 1) {
        for (int p = 0; p < pad; p++)
          cout << ' ';
        cout << buf;
      } else {
        cout << buf;
        for (int p = 0; p < pad; p++)
          cout << ' ';
      }
      cout << ' ';
    }
    cout << "|\n";
  }

  print_hline(num_cols, widths);

  if (editing)
    cout << name << " > " << flush;
  else
    cout << "Arrows: move   Enter: edit   Delete: clear   Q: quit" << flush;
}

// for question 8

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

// for question 7

void clear_board(char board[][7]) {
  for (int r = 0; r < 6; r++) {
    for (int c = 0; c < 7; c++) {
      board[r][c] = '.';
    }
  }
}

void show_board(char board[][7]) {
  cout << "\n";
  for (int r = 0; r < 6; r++) {
    cout << "| ";
    for (int c = 0; c < 7; c++) {
      cout << board[r][c] << " ";
    }
    cout << "|\n";
  }
  cout << "+---------------+\n";
  cout << "  0 1 2 3 4 5 6\n\n";
}

bool valid_move(char board[][7], int col) {
  return (col >= 0 && col < 7 && board[0][col] == '.');
}

int place_piece(char board[][7], int col, char piece) {
  for (int r = 5; r >= 0; r--) {
    if (board[r][col] == '.') {
      board[r][col] = piece;
      return r;
    }
  }
  return -1;
}

bool board_full(char board[][7]) {
  for (int c = 0; c < 7; c++) {
    if (board[0][c] == '.')
      return false;
  }
  return true;
}

bool has_won(char board[][7], char p) {
  for (int r = 0; r < 6; r++) {
    for (int c = 0; c < 7; c++) {
      if (c + 3 < 7 && board[r][c] == p && board[r][c + 1] == p &&
          board[r][c + 2] == p && board[r][c + 3] == p)
        return true;

      if (r + 3 < 6 && board[r][c] == p && board[r + 1][c] == p &&
          board[r + 2][c] == p && board[r + 3][c] == p)
        return true;

      if (r + 3 < 6 && c + 3 < 7 && board[r][c] == p &&
          board[r + 1][c + 1] == p && board[r + 2][c + 2] == p &&
          board[r + 3][c + 3] == p)
        return true;

      if (r - 3 >= 0 && c + 3 < 7 && board[r][c] == p &&
          board[r - 1][c + 1] == p && board[r - 2][c + 2] == p &&
          board[r - 3][c + 3] == p)
        return true;
    }
  }
  return false;
}

int window_points(char a, char b, char c, char d) {
  int comp = 0, hum = 0, empty = 0;
  char w[4] = {a, b, c, d};

  for (int i = 0; i < 4; i++) {
    if (w[i] == 'O')
      comp++;
    else if (w[i] == 'X')
      hum++;
    else
      empty++;
  }

  if (comp == 3 && empty == 1)
    return 5;
  if (comp == 2 && empty == 2)
    return 2;
  if (hum == 3 && empty == 1)
    return -4;
  return 0;
}

int score_position(char board[][7]) {
  int total = 0;

  for (int r = 0; r < 6; r++) {
    for (int c = 0; c < 7; c++) {
      if (c + 3 < 7)
        total += window_points(board[r][c], board[r][c + 1], board[r][c + 2],
                               board[r][c + 3]);
      if (r + 3 < 6)
        total += window_points(board[r][c], board[r + 1][c], board[r + 2][c],
                               board[r + 3][c]);
      if (r + 3 < 6 && c + 3 < 7)
        total += window_points(board[r][c], board[r + 1][c + 1],
                               board[r + 2][c + 2], board[r + 3][c + 3]);
      if (r - 3 >= 0 && c + 3 < 7)
        total += window_points(board[r][c], board[r - 1][c + 1],
                               board[r - 2][c + 2], board[r - 3][c + 3]);
    }
  }

  for (int r = 0; r < 6; r++) {
    if (board[r][3] == 'O')
      total += 3;
  }

  return total;
}

int best_move(char board[][7]) {
  int order[7] = {3, 2, 4, 1, 5, 0, 6};
  int chosen_col = -1;
  int best_val = -1000000;
  int l1 = -1000000, u1 = 1000000;

  // ply 1: computer
  for (int i = 0; i < 7; i++) {
    int c1 = order[i];
    if (!valid_move(board, c1))
      continue;

    int r1 = place_piece(board, c1, 'O');
    int val1 = 0;

    if (has_won(board, 'O')) {
      val1 = 100002;
    } else if (board_full(board)) {
      val1 = 0;
    } else {
      int min_val2 = 1000000;
      int l2 = l1, u2 = u1;

      // ply 2: human
      for (int j = 0; j < 7; j++) {
        int c2 = order[j];
        if (!valid_move(board, c2))
          continue;

        int r2 = place_piece(board, c2, 'X');
        int val2 = 0;

        if (has_won(board, 'X')) {
          val2 = -100001;
        } else if (board_full(board)) {
          val2 = 0;
        } else {
          int max_val3 = -1000000;
          int l3 = l2, u3 = u2;

          // ply 3: computer
          for (int k = 0; k < 7; k++) {
            int c3 = order[k];
            if (!valid_move(board, c3))
              continue;

            int r3 = place_piece(board, c3, 'O');
            int val3 = 0;

            if (has_won(board, 'O'))
              val3 = 100000;
            else if (board_full(board))
              val3 = 0;
            else
              val3 = score_position(board);

            board[r3][c3] = '.';

            if (val3 > max_val3)
              max_val3 = val3;
            if (max_val3 > l3)
              l3 = max_val3;
            if (l3 >= u3)
              break;
          }
          val2 = max_val3;
        }

        board[r2][c2] = '.';

        if (val2 < min_val2)
          min_val2 = val2;
        if (min_val2 < u2)
          u2 = min_val2;
        if (l2 >= u2)
          break;
      }
      val1 = min_val2;
    }

    board[r1][c1] = '.';

    if (val1 > best_val) {
      best_val = val1;
      chosen_col = c1;
    }
    if (best_val > l1)
      l1 = best_val;
    if (l1 >= u1)
      break;
  }

  return chosen_col;
}

// for question 5

long long power10(int exp) {

  long long position = 1;

  for (int i = 0; i < exp; i++) {
    position *= 10;
  }
  return position;
}

long long &get_row(int r, long long &r0, long long &r1, long long &r2,
                   long long &r3, long long &r4, long long &r5, long long &r6,
                   long long &r7, long long &r8, long long &r9) {
  if (r == 0)
    return r0;
  if (r == 1)
    return r1;
  if (r == 2)
    return r2;
  if (r == 3)
    return r3;
  if (r == 4)
    return r4;
  if (r == 5)
    return r5;
  if (r == 6)
    return r6;
  if (r == 7)
    return r7;
  if (r == 8)
    return r8;
  return r9;
}

int get_cell(int r, int c, long long r0, long long r1, long long r2,
             long long r3, long long r4, long long r5, long long r6,
             long long r7, long long r8, long long r9) {
  long long row = get_row(r, r0, r1, r2, r3, r4, r5, r6, r7, r8, r9);
  return (int)((row / power10(c)) % 10);
}

void set_cell(int r, int c, int new_val, long long &r0, long long &r1,
              long long &r2, long long &r3, long long &r4, long long &r5,
              long long &r6, long long &r7, long long &r8, long long &r9) {
  long long &row = get_row(r, r0, r1, r2, r3, r4, r5, r6, r7, r8, r9);
  int old_val = (int)((row / power10(c)) % 10);
  row += (long long)(new_val - old_val) * power10(c);
}

// for question 4

long long position_value(int x_distance, int y_distance, int seed, int base) {
  int x = abs(x_distance), y = abs(y_distance);
  int current_dominant = max(x, y);
  long long ring = sequence_sum(current_dominant, base);

  long long offset;

  if (x_distance < 0) {

    current_dominant = max(-y_distance, 0);

    offset = 2 * sequence_sum(current_dominant, base) - ring;
  } else {

    current_dominant = max(y_distance, 0);

    offset = ring - 2 * sequence_sum(current_dominant, base);
  }
  return ((seed + offset) % base + base) % base;
}

char display_value(long long a) {
  return ((a < 10) ? static_cast<char>(a + '0')
                   : static_cast<char>((a - 10) + 'A'));
}

long long sequence_sum(int n, int base) {

  long long sum = 0, a = 1, b = 1;

  for (int i = 1; i <= n; i++) {
    sum = (sum + a) % base;
    long long next = (a + b) % base;
    a = b;
    b = next;
  }

  return sum;
}

// for question 3

void row(int i, int n, int correction) {

  int width = 2 * i - 1;

  char characters[4] = {'*', '.', 'o', '-'};

  for (int k = 1; k <= n - i; k++)
    cout << " ";

  for (int j = 0; j < width; j++) {
    int distance = min(j, width - j - 1);

    cout << characters[(distance + correction) % 4];
  }

  cout << "\n";
}

// for question 2

void print_calendar(int month, int year) {
  year--;
  int day_of_week = 0;
  int jan = 31, feb = 28, mar = 31, april = 30, may = 31, june = 30, july = 31,
      aug = 31, sep = 30, oct = 31, nov = 30, dec = 31;
  long long days = (jan + feb + mar + april + may + june + july + aug + sep +
                    oct + nov + dec) *
                       year +
                   year / 4 + year / 400 - year / 100 + 1;

  if ((((year + 1) % 4 == 0) && ((year + 1) % 100 != 0)) || !((year + 1) % 400))
    feb = 29;

  int month_days = jan;

  switch (month) {
  case 1:
    month_days = jan;
    break;
  case 2:
    days += jan;
    month_days = feb;
    break;
  case 3:
    days += jan + feb;
    month_days = mar;
    break;
  case 4:
    days += jan + feb + mar;
    month_days = april;
    break;
  case 5:
    days += jan + feb + mar + april;
    month_days = may;
    break;
  case 6:
    days += jan + feb + mar + april + may;
    month_days = june;
    break;
  case 7:
    days += jan + feb + mar + april + may + june;
    month_days = july;
    break;
  case 8:
    days += jan + feb + mar + april + may + june + july;
    month_days = aug;
    break;
  case 9:
    days += jan + feb + mar + april + may + june + july + aug;
    month_days = sep;
    break;
  case 10:
    days += jan + feb + mar + april + may + june + july + aug + sep;
    month_days = oct;
    break;
  case 11:
    days += jan + feb + mar + april + may + june + july + aug + sep + oct;
    month_days = nov;
    break;
  default:
    days += jan + feb + mar + april + may + june + july + aug + sep + oct + nov;
    month_days = dec;
  }

  cout << "\nSu Mo Tu We Th Fr Sa\n";

  day_of_week = days % 7;
  for (int k = 1; k <= 3 * day_of_week; k++)
    cout << ' ';

  for (int i = 1; i <= month_days; i++) {
    if (i < 10)
      cout << ' ';
    if ((day_of_week + i) % 7 == 0)
      cout << i << '\n';
    else
      cout << i << " ";
  }
}

// for question 6

int find_process(int arr[], int size, int target) {

  for (int i = 0; i < size; i++) {
    if (arr[i] == target)
      return i;
  }
  return -1;
}

int amount_of_free_memory(int arr[], int size) {
  int count = 0;

  for (int i = 0; i < size; i++) {
    if (arr[i] == 0)
      count++;
  }
  return count;
}

int largest_free_consecutive_memory(int arr[], int size) {
  int max_free = 0, current_free = 0;
  for (int i = 0; i < size; i++) {
    if (arr[i] == 0) {
      current_free++;
      max_free = max(max_free, current_free);
    } else {
      current_free = 0;
    }
  }
  return max_free;
}

bool allocate_memory(int arr[], int size, int pid, int memory_requirement) {
  if (memory_requirement <= 0 || memory_requirement > size)
    return false;

  int available_memory = 0;

  for (int i = 0; i < size; i++) {
    if (arr[i] == 0) {
      available_memory++;
      if (available_memory == memory_requirement) {
        for (int j = i - memory_requirement + 1; j <= i; j++)
          arr[j] = pid;
        return true;
      }
    } else {
      available_memory = 0;
    }
  }

  return false;
}

void free_memory(int arr[], int size, int pid) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == pid)
      arr[i] = 0;
  }
}

void display_memory(int arr[], int size) {
  cout << "\nMemory Layout (each symbol is one block):\n";

  for (int i = 0; i < size; i++) {
    if (arr[i] == 0)
      cout << "[ . ]";
    else
      cout << "[" << arr[i] << "]";
    if ((i + 1) % 10 == 0)
      cout << "\n";
  }

  cout << "Free blocks: " << amount_of_free_memory(arr, size) << "\n";
  cout << "Largest contiguous free region: "
       << largest_free_consecutive_memory(arr, size) << "\n";
}

void memory_compaction(int arr[], int size) {
  int position = 0;

  for (int i = 0; i < size; i++) {
    if (arr[i] != 0) {
      arr[position] = arr[i];
      position++;
    }
  }

  while (position < size) {
    arr[position] = 0;
    position++;
  }

  cout << "Memory compaction completed. Relative order of allocated blocks "
          "was preserved.\n";
  display_memory(arr, size);
}

void process_info(int i, int pid[], int arrival_time[], int burst[],
                  int priority[], int memory_requirement[], int status[]) {

  cout << "PID: " << pid[i] << " | Arrival: " << arrival_time[i]
       << " | Burst: " << burst[i] << " | Priority: " << priority[i]
       << " | Mem: " << memory_requirement[i] << " | Status: ";

  if (status[i] == 0)
    cout << "New (NoMemory)\n";
  else if (status[i] == 1)
    cout << "Ready\n";
  else if (status[i] == 2)
    cout << "Running\n";
  else
    cout << "Terminated\n";
}

void process_schedule(int count, int busy_time, int end_time, int pid[],
                      int status[], int completion_time[],
                      int turnaround_time[], int waiting_time[]) {
  cout << "\nPID\tCT\tTAT\tWT\n";
  double total_turnaround_time = 0, total_waiting_time = 0;
  int completed = 0;

  for (int i = 0; i < count; i++) {
    if (status[i] == 1) {
      total_turnaround_time += turnaround_time[i];
      total_waiting_time += waiting_time[i];
      completed++;
      cout << pid[i] << "\t" << completion_time[i] << "\t" << turnaround_time[i]
           << "\t" << waiting_time[i] << "\n";
    }
  }

  double cpu_utilization =
      ((end_time > 0) ? (busy_time * 100.0 / end_time) : 0.0);

  cout << "Completed in this schedule: " << completed << "\n";
  cout << "Average waiting time: " << (total_waiting_time / completed);
  cout << "\nAverage turnaround time: " << (total_turnaround_time / completed);
  cout << "\nCPU utilization: " << cpu_utilization << "%";
  cout << "\nThis is a scheduling analysis; process states and memory "
          "allocations are unchanged.\n";
}

void non_preemptive(int mode, int count, int pid[], int arrival_time[],
                    int burst[], int remaining_burst_time[],
                    int completion_time[], int turnaround_time[],
                    int waiting_time[], int status[]) {
  bool completed[100] = {false};
  int ready_processes = 0;

  for (int i = 0; i < count; i++) {
    if (status[i] == 1) {
      ready_processes++;
      remaining_burst_time[i] = burst[i];
    }
  }

  if (ready_processes == 0) {
    cout << "No Ready processes to schedule.\n";
    return;
  }

  int time = 0;
  int busy_time = 0, finished_processes = 0;

  cout << "Execution order: ";

  while (finished_processes < ready_processes) {
    int current_job = -1;

    for (int i = 0; i < count; i++) {
      if (status[i] != 1 || completed[i])
        continue;
      if (mode == 1) {
        if (current_job == -1 || arrival_time[i] < arrival_time[current_job])
          current_job = i;
      } else {
        if (arrival_time[i] <= time &&
            (current_job == -1 || burst[i] < burst[current_job]))
          current_job = i;
      }
    }

    if (current_job == -1) {
      int next_arrival = 1000000000;
      for (int i = 0; i < count; i++) {
        if (status[i] == 1 && !completed[i])
          next_arrival = min(next_arrival, arrival_time[i]);
      }
      time = next_arrival;
    } else {
      time = max(time, arrival_time[current_job]);

      cout << pid[current_job] << "(" << burst[current_job] << ") ";
      time += burst[current_job];
      busy_time += burst[current_job];

      remaining_burst_time[current_job] = 0;
      completion_time[current_job] = time;
      turnaround_time[current_job] =
          completion_time[current_job] - arrival_time[current_job];
      waiting_time[current_job] =
          turnaround_time[current_job] - burst[current_job];

      completed[current_job] = true;
      finished_processes++;
    }
  }

  cout << "\n";
  process_schedule(count, busy_time, time, pid, status, completion_time,
                   turnaround_time, waiting_time);
}

void round_robin(int count, int pid[], int arrival_time[], int burst[],
                 int remaining_burst_time[], int completion_time[],
                 int turnaround_time[], int waiting_time[], int status[]) {
  int time_quantum;
  cout << "Enter time quantum: ";
  cin >> time_quantum;
  if (time_quantum <= 0) {
    cout << "Invalid quantum.\n";
    return;
  }

  bool queued[100] = {false};
  int ready_processes = 0;

  for (int i = 0; i < count; i++) {
    if (status[i] == 1) {
      remaining_burst_time[i] = burst[i];
      ready_processes++;
    }
  }
  if (ready_processes == 0) {
    cout << "No Ready processes to schedule.\n";
    return;
  }

  const int QSIZE = 10000;
  int queue[QSIZE], front = 0, rear = 0;
  int time = 0, busy_time = 0, completed_processes = 0;

  cout << "Execution order: ";

  while (completed_processes < ready_processes) {

    while (true) {
      int earliest = -1;
      for (int i = 0; i < count; i++) {
        if (status[i] == 1 && !queued[i] && remaining_burst_time[i] > 0 &&
            arrival_time[i] <= time) {
          if (earliest == -1 || arrival_time[i] < arrival_time[earliest])
            earliest = i;
        }
      }
      if (earliest == -1)
        break;
      queue[rear % QSIZE] = earliest;
      rear++;
      queued[earliest] = true;
    }

    if (front == rear) {
      int next_arrival = 1000000000;
      for (int i = 0; i < count; i++) {
        if (status[i] == 1 && !queued[i] && remaining_burst_time[i] > 0)
          next_arrival = min(next_arrival, arrival_time[i]);
      }
      time = next_arrival;
      continue;
    }

    int current = queue[front % QSIZE];
    front++;
    int slice = min(remaining_burst_time[current], time_quantum);

    cout << pid[current] << "(" << slice << ") ";

    remaining_burst_time[current] -= slice;
    time += slice;
    busy_time += slice;

    while (true) {
      int earliest = -1;
      for (int i = 0; i < count; i++) {
        if (status[i] == 1 && !queued[i] && remaining_burst_time[i] > 0 &&
            arrival_time[i] <= time) {
          if (earliest == -1 || arrival_time[i] < arrival_time[earliest])
            earliest = i;
        }
      }
      if (earliest == -1)
        break;
      queue[rear % QSIZE] = earliest;
      rear++;
      queued[earliest] = true;
    }

    if (remaining_burst_time[current] > 0) {
      queue[rear % QSIZE] = current;
      rear++;
    } else {
      completion_time[current] = time;
      turnaround_time[current] =
          completion_time[current] - arrival_time[current];
      waiting_time[current] = turnaround_time[current] - burst[current];
      completed_processes++;
    }
  }
  cout << "\n";

  process_schedule(count, busy_time, time, pid, status, completion_time,
                   turnaround_time, waiting_time);
}

void stats(int count, int status[], int memory[], int size,
           int successful_allocations, int failed_allocations,
           int completion_time[], int turnaround_time[], int waiting_time[]) {
  int states_count[4] = {0};

  for (int i = 0; i < count; i++) {
    states_count[status[i]]++;
  }

  int free_memory = amount_of_free_memory(memory, size);

  cout << "\nRegistered processes: " << count;
  cout << "\nCompleted: " << states_count[3];
  cout << "\nReady: " << states_count[1];
  cout << "\nRunning: " << states_count[2];
  cout << "\nWaiting for memory: " << states_count[0];
  cout << "\nMemory capacity: " << size;
  cout << "\nAllocated memory: " << (size - free_memory);
  cout << "\nFree memory: " << free_memory;
  cout << "\nLargest free region: "
       << largest_free_consecutive_memory(memory, size);
  cout << "\nSuccessful allocations: " << successful_allocations;
  cout << "\nFailed allocations: " << failed_allocations << "\n";

  int scheduled_count = 0;
  double total_tat = 0, total_wt = 0;
  for (int i = 0; i < count; i++) {
    if (completion_time[i] > 0) {
      scheduled_count++;
      total_tat += turnaround_time[i];
      total_wt += waiting_time[i];
    }
  }
  if (scheduled_count > 0) {
    cout << "Scheduled processes: " << scheduled_count;
    cout << "\nAverage turnaround time: " << (total_tat / scheduled_count);
    cout << "\nAverage waiting time: " << (total_wt / scheduled_count) << "\n";
  }
}
