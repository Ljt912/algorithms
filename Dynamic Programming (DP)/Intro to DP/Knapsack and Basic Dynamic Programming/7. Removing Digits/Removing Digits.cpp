#include <iostream>
#include <vector>

using namespace std;

vector<int> allDigits(int target) {
  vector<int> digits;
  while (target) {
    digits.emplace_back(target % 10);
    target = target / 10;
  }
  return digits;
}

int main() {
  int target;
  cin >> target;

  vector<int> minimam(target+1, 0x3f3f3f3f);
  minimam[0] = 0;
  for(int i = 1; i < target + 1; ++i) {
    vector<int> digits = allDigits(i);
    for (int digit : digits) {
      minimam[i] = min(minimam[i], minimam[i-digit] + 1);
    }
  }
  cout << minimam[target];
  return 0;
}