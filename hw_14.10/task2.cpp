#include <algorithm>
#include <iostream>

using namespace std;

void withdraw(int& bank) {
  int k;
  cin >> k;
  if (k <= 0 || bank < k) {
    cout << "error" << "\n";
  } else {
    bank -= k;
  }
}

void deposit(int& bank) {
  int k;
  cin >> k;
  if (k <= 0) {
    cout << "error" << "\n";
  } else {
    bank += k;
  }
}

void balance(int& bank) { cout << bank << "\n"; }

void reset(int& bank) { bank = 0; }

void triple(int& bank) { bank *= 3; }

int main() {
  int bank = 0;
  string commands[] = {"deposit", "withdraw", "balance", "reset", "triple"};
  void (*ptrs[])(int&) = {deposit, withdraw, balance, reset, triple};

  int n_cmds = sizeof(commands) / sizeof(commands[0]);

  string cmd = "";
  cin >> cmd;
  while (cmd != "stop") {
    int ind = find(commands, commands + n_cmds, cmd) - commands;
    if (ind == n_cmds) {
      cout << "error" << "\n";
    } else {
      ptrs[ind](bank);
    }
    cin >> cmd;
  }
}
