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
int stones[101];

int solve() {
  int res = 0; // 1 = T 0 = HL
  int sum = 0;
  int mx = 0;
  for (int i=0;i<n;i++) {
    sum += stones[i];
    mx = max(mx, stones[i]);
  }
  if (mx > sum - mx) return 1;
  else if (sum % 2 == 0) return 0;
  return 1;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=0;i<n;i++) {
      cin >> stones[i];
    }
    cout << (solve() ? "T" : "HL") << endl;
  }
  return 0;
}
