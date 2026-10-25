#include <iostream>

using namespace std;

int question1();

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

int question1() {

  int n;
  cout << "\nEnter n: ";
  cin >> n;
  if (!((n & 1) || (n >= 2)))
    return 1;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << i;
    }
    cout << "\n";
  }

  return 0;
}
