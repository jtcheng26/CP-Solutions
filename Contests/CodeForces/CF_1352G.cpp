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
int perm[1001];

int solve() {
  int res = 0;
  if (n <= 3) return -1;
  if (n == 4) {
    perm[0] = 3; perm[1] = 1; perm[2] = 4; perm[3] = 2;
    return 0;
  }
  int cnt = 0;
  for (int i=1;i<=n;i+=2) {
    perm[cnt++] = i;
  }
  int start;
  if (n % 2 == 0) {
    perm[cnt++] = n - 4;
    perm[cnt++] = n;
    perm[cnt++] = n - 2;
    start = n - 6;
  } else {
    perm[cnt++] = n - 3;
    perm[cnt++] = n - 1;
    start = n - 5;
  }
  for (int i=start;i>=2;i-=2) {
    perm[cnt++] = i;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    if (solve() == -1) {
      cout << "-1 \n";
      continue;
    }
    for (int i=0;i<n;i++) cout << perm[i] << (i == n-1 ? "\n" : " ");
  }
  return 0;
}
