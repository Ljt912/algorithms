#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  int target;
  cin >> target;

  vector<int> coins(n);
  for (int i = 0; i < n; ++i) {
    int coin;
    cin >> coin;
    coins[i] = coin;
  }
  vector<int> minimamCoins(target+1, 0x3f3f3f3f);
  minimamCoins[0] = 0;
  for (int i = 1; i < target+1; ++i) {
    for (int coin : coins) {
      if (i - coin >= 0) minimamCoins[i] = min(minimamCoins[i], minimamCoins[i - coin] + 1);
    }
  }
  if (minimamCoins[target] == 0x3f3f3f3f) {
    cout << -1;
  } else {
    cout << minimamCoins[target];
  }
  return 0;
}
