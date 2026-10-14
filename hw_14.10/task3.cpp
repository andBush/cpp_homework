#include <iostream>
#include <string>

using namespace std;

void clear(char table[][10]) {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 10; j++) {
      table[i][j] = ' ';
    }
  }
}

bool check(int x, int y) {
  return (x >= 0) && (x <= 9) && (y >= 0) && (y <= 4);
}

bool put(char table[][10], int x, int y, char c) {
  if (!check(x, y)) {
    return false;
  }

  table[y][x] = c;
  return true;
}

bool text(char table[][10], int x, int y, string word) {
  if (!check(x, y) || !check(x + word.length() - 1, y)) {
    return false;
  }

  for (int i = 0; i < word.size(); i++) {
    put(table, x + i, y, word[i]);
  }

  return true;
}

void print(char table[][10]) {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 10; j++) {
      cout << table[i][j];
    }
    cout << endl;
  }
}

int main() {
  char table[5][10];
  clear(table);

  string cmd;
  cin >> cmd;

  while (cmd != "quit") {
    if (cmd == "clear") {
      clear(table);
    } else if (cmd == "put") {
      int x, y;
      char c;
      cin >> x >> y >> c;

      if (!put(table, x, y, c)) {
        cout << "error" << endl;
      }
    } else if (cmd == "text") {
      int x, y;
      string word;
      cin >> x >> y >> word;

      if (!text(table, x, y, word)) {
        cout << "error" << endl;
      }
    } else if (cmd == "print") {
      print(table);
    }

    cin >> cmd;
  }

  return 0;
}
