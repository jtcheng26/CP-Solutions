#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INF 1000000001
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int n;
int a[101];

int solve() {
  int res = 0;
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=0;i<n;i++) {
      cin >> a[i];
    }
    sort(a, a+n);
    bool seen[101] = {false};
    bool used[101] = {false};
    for (int i=0;i<n;i++) {
      if (!seen[a[i]]) {
        cout << a[i] << " ";
        used[i] = true;
        seen[a[i]] = true;
      }
    }
    for (int i=0;i<n;i++) {
      if (!used[i]) {
        cout << a[i] << " ";
      }
    }
    cout << "\n";
  }
  return 0;
}
