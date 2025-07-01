#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

const int MOD = 1e9+7;
int main() {
  int n;
  cin >> n;
  vector<vector<char>> map(n, vector<char>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> map[i][j];
    }
  }
  vector<vector<int>> dp(n, vector<int>(n));
  if (map[0][0] != '*')
    dp[0][0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (map[i][j] == '*') {
        dp[i][j] = 0;
        continue;
      }
      if ( i >= 1 && dp[i-1][j] != -1) {
        dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
      }
      if ( j >= 1 && dp[i][j-1] != -1) {
        dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
      }
    }
  }
  cout << dp[n-1][n-1];
  return 0;
}
