#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9+7;


int main() {
  int n, k;
  cin >> n >> k;
  vector<int> stones(n);
  for (int i = 0; i < n; ++i) {
    int stone;
    cin >> stone;
    stones[i] = stone;
  }
  vector<int> minimamCost(n, 0x3f3f3f3f);
  minimamCost[0] = 0;
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j <= k; ++j) {
      if (i - j >= 0) minimamCost[i] = min(minimamCost[i], (minimamCost[i-j] + abs(stones[i] - stones[i-j])) % MOD);
      else break;
    }
  }
  cout << minimamCost[n-1];
  return 0;
}