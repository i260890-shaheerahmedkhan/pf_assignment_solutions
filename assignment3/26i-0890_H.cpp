#include <iostream>

using namespace std;

void question1();
void question2();
void question3();

int main() {

  int choice;

  cout << "\nEnter the question you want to run (1-8), 9 for bonus : ";
  cin >> choice;

  switch (choice) {

  case 1:
    question1();
    break;
  case 2:
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

void question1() {

  int n;
  cout << "\nEnter n: ";
  cin >> n;
  if (!((n & 1) || (n < 2)))
    return;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << i;
    }
    cout << "\n";
  }
}

void question3() {

  int n;
  cout << "\nEnter n: ";
  cin >> n;
  if (!(n & 1) || (n < 2))
    return;

  for (int i = 1; i <= n; i++) {
    int stars = 2 * i - 1;
    int spaces = n - i;

    for (int j = 1; j <= spaces; j++)
      cout << " ";
    for (int k = 1; k <= stars; k++) {

      int distance = min(k - 1, stars - k);

      bool isStar = ((k == 1) || (k == stars) || (distance % 4 == 0));
      bool isDot = ((distance % 4 == 3));
      bool isDash = ((distance % 4 == 1));
      bool isO = (distance % 4 == 2);

      if (isStar)
        cout << "*";
      else if (isDot)
        cout << ".";
      else if (isDash)
        cout << "-";
      else if (isO)
        cout << "o";
    }

    cout << "\n";
  }

  for (int i = n - 1; i >= 1; i--) {
    int stars = 2 * i - 1;
    int spaces = n - i;

    for (int j = 1; j <= spaces; j++)
      cout << " ";
    for (int k = 1; k <= stars; k++) {
      int distance = min(k - 1, stars - k);

      bool isStar = ((k == 1) || (k == stars) || (distance % 4 == 0));
      bool isDot = ((distance % 4 == 3));
      bool isDash = ((distance % 4 == 1));
      bool isO = (distance % 4 == 2);

      if (isStar)
        cout << "*";
      else if (isDot)
        cout << ".";
      else if (isDash)
        cout << "-";
      else if (isO)
        cout << "o";
    }
    cout << "\n";
  }
}
