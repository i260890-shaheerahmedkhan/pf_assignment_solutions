#include <iomanip>
#include <iostream>

using namespace std;

// Questions

void question1();
void question2();
void question3();

// utilities

void row(int, int, int);
void print_calendar(int, int);

int main() {

  int choice;

  cout << "\nEnter the question you want to run (1-8), 9 for bonus : ";
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
    break;
  case 5:
    break;
  case 6:
    break;
  case 7:
    break;
  case 8:
    break;
  case 9:
    break;
  default:
    cout << "\nInvalid choice!";
  }

  return 0;
}

// Answers to questions 1-9

void question1() {

  int n;
  cout << "\nEnter n: ";
  cin >> n;
  if (!((n & 1) || (n < 2)))
    return;

  int bound = 2 * n - 1;
  int c = n;

  for (int i = 1; i <= bound; i++) {
    for (int j = 1; j <= bound; j++) {
      int d = min(min(i, min(j, bound - j + 1)), bound - i + 1);
      cout << (d) % 10 << " ";
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

void question4() {}

// utility functions

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

  cout << "\nSu Mo Tu We Th Fr Sa\n";

  switch (month) {
  case 1:
    day_of_week = days % 7;
    for (int k = 1; k <= 3 * day_of_week; k++)
      cout << ' ';
    for (int i = 1; i <= jan; i++) {
      if ((day_of_week + i) % 7 == 0)
        cout << setw(2) << i << '\n';
      else
        cout << setw(2) << i << " ";
    }
    break;
  case 2:
    days += jan;
    day_of_week = days % 7;
    for (int k = 1; k <= 3 * day_of_week; k++)
      cout << ' ';
    for (int i = 1; i <= feb; i++) {
      if ((day_of_week + i) % 7 == 0)
        cout << setw(2) << i << '\n';
      else
        cout << setw(2) << i << " ";
    }
    break;
  case 3:
    days += jan + feb;
    day_of_week = days % 7;
    for (int k = 1; k <= 3 * day_of_week; k++)
      cout << ' ';
    for (int i = 1; i <= mar; i++) {
      if ((day_of_week + i) % 7 == 0)
        cout << setw(2) << i << '\n';
      else
        cout << setw(2) << i << " ";
    }
    break;
  case 4:
    days += jan + feb + mar;
    day_of_week = days % 7;
    for (int k = 1; k <= 3 * day_of_week; k++)
      cout << ' ';
    for (int i = 1; i <= april; i++) {
      if ((day_of_week + i) % 7 == 0)
        cout << setw(2) << i << '\n';
      else
        cout << setw(2) << i << " ";
    }
    break;
  case 5:
    days += jan + feb + mar + april;
    day_of_week = days % 7;
    for (int k = 1; k <= 3 * day_of_week; k++)
      cout << ' ';
    for (int i = 1; i <= may; i++) {
      if ((day_of_week + i) % 7 == 0)
        cout << setw(2) << i << '\n';
      else
        cout << setw(2) << i << " ";
    }
    break;
  case 6:
    days += jan + feb + mar + april + may;
    day_of_week = days % 7;
    for (int k = 1; k <= 3 * day_of_week; k++)
      cout << ' ';
    for (int i = 1; i <= june; i++) {
      if ((day_of_week + i) % 7 == 0)
        cout << setw(2) << i << '\n';
      else
        cout << setw(2) << i << " ";
    }
    break;
  case 7:
    days += jan + feb + mar + april + may + june;
    day_of_week = days % 7;
    for (int k = 1; k <= 3 * day_of_week; k++)
      cout << ' ';
    for (int i = 1; i <= july; i++) {
      if ((day_of_week + i) % 7 == 0)
        cout << setw(2) << i << '\n';
      else
        cout << setw(2) << i << " ";
    }
    break;
  case 8:
    days += jan + feb + mar + april + may + june + july;
    day_of_week = days % 7;
    for (int k = 1; k <= 3 * day_of_week; k++)
      cout << ' ';
    for (int i = 1; i <= aug; i++) {
      if ((day_of_week + i) % 7 == 0)
        cout << setw(2) << i << '\n';
      else
        cout << setw(2) << i << " ";
    }
    break;
  case 9:
    days += jan + feb + mar + april + may + june + july + aug;
    day_of_week = days % 7;
    for (int k = 1; k <= 3 * day_of_week; k++)
      cout << ' ';
    for (int i = 1; i <= sep; i++) {
      if ((day_of_week + i) % 7 == 0)
        cout << setw(2) << i << '\n';
      else
        cout << setw(2) << i << " ";
    }
    break;
  case 10:
    days += jan + feb + mar + april + may + june + july + aug + sep;
    day_of_week = days % 7;
    for (int k = 1; k <= 3 * day_of_week; k++)
      cout << ' ';
    for (int i = 1; i <= oct; i++) {
      if ((day_of_week + i) % 7 == 0)
        cout << setw(2) << i << '\n';
      else
        cout << setw(2) << i << " ";
    }
    break;
  case 11:
    days += jan + feb + mar + april + may + june + july + aug + sep + oct;
    day_of_week = days % 7;
    for (int k = 1; k <= 3 * day_of_week; k++)
      cout << ' ';
    for (int i = 1; i <= nov; i++) {
      if ((day_of_week + i) % 7 == 0)
        cout << setw(2) << i << '\n';
      else
        cout << setw(2) << i << " ";
    }
    break;
  default:
    days += jan + feb + mar + april + may + june + july + aug + sep + oct + nov;
    day_of_week = days % 7;
    for (int k = 1; k <= 3 * day_of_week; k++)
      cout << ' ';
    for (int i = 1; i <= dec; i++) {
      if ((day_of_week + i) % 7 == 0)
        cout << setw(2) << i << '\n';
      else
        cout << setw(2) << i << " ";
    }
  }
}
