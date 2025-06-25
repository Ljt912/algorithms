#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long MOD = 1e9 + 7;

//dp[money] = dp[money] + dp[money-coins[i]];
// int dp(int money, const vector<int>& coins) {
//   if (money < 0) return 0;
//   if (money == 0) return 1;
//   int res = 0;
//   int n = coins.size();
//   for (int i = 0; i < n; ++i) {
//     res = (res + dp(money - coins[i], coins)) % MOD;
//   }
//   return res;
// }

int main() {
  int n;
  cin >> n;
  vector<int> coins(n);
  int total_points;
  cin >> total_points;
  for (int i = 0; i < n; ++i) {
    int coin;
    cin >> coin;
    coins[i] = coin;
  }
  sort(coins.begin(), coins.end());
  vector<long long> combinations(total_points + 1, 0);

  combinations[0] = 1;
  for (int i = 1; i <= total_points; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i - coins[j] >= 0) combinations[i] = (combinations[i] + combinations[i - coins[j]]) % MOD;
      else break;
    }
  }
  cout << combinations[total_points];
  return 0;
}