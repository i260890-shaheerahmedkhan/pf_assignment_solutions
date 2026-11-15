#include "helperCells.h"
#include <iostream>
using namespace std;

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

    int key = readKey();
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
      return 0;
    }
  }
}

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
