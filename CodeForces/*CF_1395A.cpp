#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 100000007

typedef long long ll;

using namespace std;

int w;
int rgb[3];

bool solve() {
  int odds = 0; int empty = 0;
  for (int i=0;i<3;i++) {
    if (rgb[i] % 2 == 1) odds++;
    else if (rgb[i] == 0) empty++;
  }
  if (odds == 0) return true;
  if (odds == 3) return true;
  if (empty >= 2 && w % 2 == 0) return true;
  if (odds == 2 && empty == 0 && w % 2 == 1) return true;
  if (odds == 1 && w % 2 == 0) return true;
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    for (int i=0;i<3;i++)
      cin >> rgb[i];
    cin >> w;
    cout << (solve() ? "Yes" : "No") << endl;
  }
  return 0;
}
