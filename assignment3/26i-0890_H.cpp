#include <iostream>

using namespace std;

// questions

void question1();
void question2();
void question3();
void question4();
void question5();
void question6();
void question7();

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

int main() {

  int choice;

  cout << "\nEnter the question you want to run (1-7): ";
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
  if ((n <= 2) || !(n & 1))
    return;

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

// utility functions

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

  int queue[1000], front = 0, rear = 0;
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
      queue[rear % 1000] = earliest;
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

    int current = queue[front % 1000];
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
      queue[rear % 1000] = earliest;
      rear++;
      queued[earliest] = true;
    }

    if (remaining_burst_time[current] > 0) {
      queue[rear % 1000] = current;
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
