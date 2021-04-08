#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

#define mp make_pair
#define pb push_back
#define F first
#define S second

typedef long long ll;

using namespace std;

int n, q;
int a[5001];
ll res[5001][5001];

ll query(int l, int r) {
  if (r - l < 2) return 0;
  return res[l-1][r-1];
}

int solve() {
  if (n < 3) return 0;
  int cnt[2000001] = {0};
  for (int i=2;i<n;i++) {
    for (int j=i-1;j>=0;j--) {
      int sum = a[i] + a[j];
      if (abs(sum) <= 1000000)
        res[j][i] = cnt[1000000 + -1 * sum];
      else
        res[j][i] = 0;
      cnt[1000000 + a[j]]++;
    }
    for (int j=0;j<i;j++) {
      cnt[1000000 + a[j]]--;
    }
  }
  /*
  for (int i=0;i<n;i++)
  for (int j=0;j<n;j++)
    cout << i << " " << j << " " << res[i][j] << "\n";
  */
  for (int i=n-1;i>=0;i--)
	for (int j=i+1;j<n;j++)
		res[i][j] += res[i+1][j] + res[i][j-1] - res[i+1][j-1];
  return 0;
}

int main() {
  ofstream cout ("threesum.out");
  ifstream cin ("threesum.in");
  cin >> n >> q;
  for (int i=0;i<n;i++) cin >> a[i];
  solve();
  for (int i=0;i<q;i++) {
    int l, r;
    cin >> l >> r;
    cout << query(l, r) << "\n";
  }
  return 0;
}
