#include <iostream>
#include <string>

using namespace std;

int main() {
  // Симулятор банка с историей балансов.
  // int*** хранит балансы: клиент -> счет -> момент.
  // void* хранит данные событий разных типов:
  // int для сумм и string для уведомлений.

  const int MAX = 100;

  int clients, accounts;
  cin >> clients >> accounts;

  if (clients <= 0 || accounts <= 0) {
    return 0;
  }

  int*** history = new int**[clients];

  for (int i = 0; i < clients; i++) {
    history[i] = new int*[accounts];

    for (int j = 0; j < accounts; j++) {
      history[i][j] = new int[MAX + 1]();
    }
  }

  void* events[MAX + 1] = {};
  char kind[MAX + 1] = {};

  int moment = 0;
  string cmd;

  while (cin >> cmd && cmd != "quit") {
    if (cmd == "deposit" || cmd == "withdraw") {
      int client, account, amount;
      cin >> client >> account >> amount;

      if (client < 0 || client >= clients || account < 0 ||
          account >= accounts || amount <= 0 || moment == MAX ||
          (cmd == "withdraw" && history[client][account][moment] < amount)) {
        cout << "error" << endl;
        continue;
      }

      for (int i = 0; i < clients; i++) {
        for (int j = 0; j < accounts; j++) {
          history[i][j][moment + 1] = history[i][j][moment];
        }
      }

      if (cmd == "deposit") {
        history[client][account][moment + 1] += amount;
      } else {
        history[client][account][moment + 1] -= amount;
      }

      moment++;

      events[moment] = new int(amount);
      kind[moment] = (cmd == "deposit") ? 'D' : 'W';

      cout << "moment " << moment << endl;
    }

    else if (cmd == "message") {
      string msg;
      cin >> msg;

      if (moment == MAX) {
        cout << "error" << endl;
        continue;
      }


      for (int i = 0; i < clients; i++) {
        for (int j = 0; j < accounts; j++) {
          history[i][j][moment + 1] = history[i][j][moment];
        }
      }

      moment++;

      events[moment] = new string(msg);
      kind[moment] = 'M';

      cout << "moment " << moment << endl;
    }

    else if (cmd == "balance") {
      int client, account, t;
      cin >> client >> account >> t;

      if (client < 0 || client >= clients || account < 0 ||
          account >= accounts || t < 0 || t > moment) {
        cout << "error" << endl;
      } else {
        cout << history[client][account][t] << endl;
      }
    }

    else if (cmd == "event") {
      int t;
      cin >> t;

      if (t < 1 || t > moment) {
        cout << "error" << endl;
      } else if (kind[t] == 'M') {
        cout << "message: " << *static_cast<string*>(events[t]) << endl;
      } else if (kind[t] == 'D') {
        cout << "deposit: " << *static_cast<int*>(events[t]) << endl;
      } else {
        cout << "withdraw: " << *static_cast<int*>(events[t]) << endl;
      }
    }
  }

  for (int t = 1; t <= moment; t++) {
    if (kind[t] == 'M') {
      delete static_cast<string*>(events[t]);
    } else {
      delete static_cast<int*>(events[t]);
    }
  }

  for (int i = 0; i < clients; i++) {
    for (int j = 0; j < accounts; j++) {
      delete[] history[i][j];
    }
    delete[] history[i];
  }

  delete[] history;

  return 0;
}
