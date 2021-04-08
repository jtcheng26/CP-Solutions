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

int n, q;
int a[100002];
int pfx[100002];
int sfx[100002];

int query(int l, int r) {
  return pfx[l-1] + sfx[r+1];
}

void solve() {/*
  pfx[0] = 0;
  int low = 27;
  for (int i=1;i<=n;i++) {
    pfx[i] += pfx[i-1];
    if (i == 1 || a[i] > a[i-1] || a[i] < low) {
      pfx[i]++;
    }
    low = min(low, a[i]);
  }
  sfx[n+1] = 0;
  low = 27;
  for (int i=n;i>=0;i--) {
    sfx[i] += sfx[i+1];
    if (i == n || a[i] > a[i+1] || a[i] < low) {
      sfx[i]++;
    }
    low = min(low, a[i]);
  }*/
  pfx[0] = 0;
  sfx[n+1] = 0;
  for (int i=0;i<26;i++) {
    bool flag = false;
    for (int j=1;j<=n;j++) {
      if (!flag && a[j] == i) {
        flag = true;
        pfx[j]++;
      } else if (a[j] < i) {
        flag = false;
      }
    }
    flag = false;
    for (int j=n;j>=1;j--) {
      if (!flag && a[j] == i) {
        flag = true;
        sfx[j]++;
      } else if (a[j] < i){
        flag = false;
      }
    }
  }
  //pfx[1]++;
  for (int i=1;i<=n;i++) {
    pfx[i] += pfx[i-1];
  }
  //sfx[n]++;
  for (int i=n;i>=1;i--) {
    sfx[i] += sfx[i+1];
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> q;
  for (int i=1;i<=n;i++) {
    char c;
    cin >> c;
    a[i] = c - 'A';
  }
  solve();
  for (int i=0;i<q;i++) {
    int l, r;
    cin >> l >> r;
    cout << query(l, r) << "\n";
  }
  return 0;
}
