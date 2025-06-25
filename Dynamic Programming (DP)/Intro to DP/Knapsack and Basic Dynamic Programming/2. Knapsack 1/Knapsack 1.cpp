#include <iostream>
#include <vector>
#include <utility>

int main() {
  int n, w;
  std::cin >> n >> w;
  std::vector<std::pair<int, long long>> items(n);
  for (int i = 0; i < n; ++i) {
    int w_i, v_i;
    std::cin >> w_i >> v_i;
    items[i] = {w_i, v_i};
  }
  std::vector<long long> values(w+1, 0);
  for (int i = 0; i < n; ++i) {
    for (int j = w; j >= items[i].first; --j) {
      values[j] = std::max(values[j], values[j-items[i].first] + items[i].second);
    }
  }
  std::cout << values[w];
  return 0;
}
