#include <climits>
#include <iomanip>
#include <iostream>

#define PII pair<int, int>

using namespace std;

double avg_temp(const int* arr, const int n) {
  int sum_temps = 0;
  for (int i = 0; i < n; i++) {
    sum_temps += arr[i];
  }
  return 1.0 * sum_temps / n;
}

PII min_max_temp(const int* arr, const int n) {
  int min_temp = INT_MAX, max_temp = INT_MIN;
  for (int i = 0; i < n; i++) {
    min_temp = min(min_temp, arr[i]);
    max_temp = max(max_temp, arr[i]);
  }
  return {min_temp, max_temp};
}

int cnt_neg_temp(const int* arr, const int n) {
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] < 0) {
      ans++;
    }
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  int* arr = new int[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  cout << fixed << setprecision(1) << avg_temp(arr, n) << "\n";
  PII temps = min_max_temp(arr, n);
  cout << temps.first << " " << temps.second << "\n";
  cout << cnt_neg_temp(arr, n) << "\n";
  
  delete[] arr;
  arr = nullptr;

  return 0;
}
