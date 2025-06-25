#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

// int minimamCost(int position, const vector<int>& stones) {
//   if (position == 0) return 0;
//   if (position == 1) return abs(stones[position] - stones[position-1]);

//   return min((minimamCost(position - 1, stones) + abs(stones[position] - stones[position-1])) % MOD, 
//             (minimamCost(position - 2, stones) + abs(stones[position] - stones[position-2])) % MOD);
// }

int main() {
  int n;
  cin >> n;
  vector<int> stones(n, 0);
  for (int i = 0; i < n; ++i) {
    int stone;
    cin >> stone;
    stones[i] = stone;
  }
  vector<int> minimamCost(3, 0);
  minimamCost[0] = 0;
  minimamCost[1] = abs(stones[1] - stones[0]);
  int i;
  for (i = 2; i < n; ++i) {
    minimamCost[i % 3] = min((minimamCost[(i - 1) % 3] + abs(stones[i] - stones[i-1])) % MOD, 
            (minimamCost[(i - 2) % 3] + abs(stones[i] - stones[i-2])) % MOD);
  }
  cout << minimamCost[(i - 1) % 3];

  return 0;
}