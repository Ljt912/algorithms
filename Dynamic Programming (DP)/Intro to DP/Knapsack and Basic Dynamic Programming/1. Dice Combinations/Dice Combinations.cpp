#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

int main() {
  int n;
  std::cin >> n;
  std::vector<long long> dp(n+1);
  dp[0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= 6; ++j) {
      if (i - j >= 0) dp[i] = (dp[i] + dp[i-j]) % MOD;
      else break;
    }
  }
  std::cout << dp[n];
  return 0;
}