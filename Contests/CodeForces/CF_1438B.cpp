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
int a[1001];

bool solve() {
  for (int i=0;i<n;i++) {
    for (int j=i+1;j<n;j++) {
      if (a[i] == a[j]) return true;
    }
  }
  return false;
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
    cout << (solve() ? "YES" : "NO") << "\n";
  }
  return 0;
}
