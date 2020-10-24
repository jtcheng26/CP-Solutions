#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 1e18+7
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long ll;

using namespace std;

int n;
int digits[1001];
int marked[1001];

int solve() {
  int turn = 1;
  int left = n;
  for (int i=1;i<=n;i++) marked[i] = false;
  while (left > 1) {
    int choose = -1;
    for (int i=1;i<=n;i++) {
      if (i % 2 == turn && digits[i] % 2 == !turn && !marked[i]) choose = i;
      if (choose == -1 && i % 2 == turn && digits[i] % 2 == turn && !marked[i]) choose = i;
    }
    marked[choose] = true;
    turn = !turn;
    left--;
  }
  for (int i=1;i<=n;i++) {
    if (!marked[i]) return digits[i] % 2 == 0 ? 2 : 1;
  }
  return 1;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=1;i<=n;i++) {
      char a;
      cin >> a;
      digits[i] = a - '0';
    }
    cout << solve() << endl;
  }
  return 0;
}
