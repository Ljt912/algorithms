#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  int total_money;
  cin >> total_money;
  vector<int> prices(n);
  vector<int> pages(n);

  for (int &price : prices) {
    cin >> price;
  }
  for (int &page : pages) {
    cin >> page;
  }

  vector<int> maxmamPages(total_money + 1, 0);
  for (int i = 0; i < n; ++i) {
    for (int money_uesed = total_money; money_uesed >= prices[i]; --money_uesed) {
      maxmamPages[money_uesed] =
          max(maxmamPages[money_uesed - prices[i]] + pages[i],
              maxmamPages[money_uesed]);
    }
  }
  cout << maxmamPages[total_money];
  return 0;
}