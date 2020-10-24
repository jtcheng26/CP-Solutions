#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 1000000007
#define pb push_back
#define F first
#define S second

typedef long long ll;

using namespace std;

int n;
char a[100001];
char b[100001];

int solve() {
  int diffp[n+1]; // cost to draw prefix ending at diffp[i] for empty boomerang
  int diffs[n+1]; // cost to draw suffix ending at diffs[i] for empty boomerang
  int res = 1e9+7;
  char curr = b[0];
  int costp[n]; // cost to make prefix ending at costp[i] correct
  int costs[n]; // cost to make suffix ending at costs[i] correct
  diffp[0] = 1; diffs[n-1] = 1;
  diffp[n] = 0; diffs[0] = 0;
  for (int i=1;i<n;i++) {
    if (b[i] != curr) {
      diffp[i] = diffp[i-1] + 1;
      curr = b[i];
    } else diffp[i] = diffp[i-1];
  }
  curr = b[n-1];
  for (int i=n-2;i>=0;i--) {
    if (b[i] != curr) {
      diffs[i] = diffs[i+1] + 1;
      curr = b[i];
    } else diffs[i] = diffs[i+1];
  }
  int sim = 0;
  for (int i=0;i<n;i++) {
    if (a[i] == b[i]) {
      if (!(i > 0 && b[i] == b[i-1]))
        sim++;
      costp[i] = diffp[i] - sim;
    } else {
      sim = 0;
      costp[i] = diffp[i];
    }
  }
  sim = 0;
  for (int i=n-1;i>=0;i--) {
    if (a[i] == b[i]) {
      if (!(i < n-1 && b[i] == b[i+1]))
        sim++;
      costs[i] = diffs[i] - sim;
    } else {
      sim = 0;
      costs[i] = diffs[i];
    }
  }
  for (int i=0;i<n;i++) {
    //cout << "cost " << costp[i] << endl;
    res = min(res, max(costp[i], costs[i+1]));
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  ifstream cin ("boomerang_decoration_input.txt");
  ofstream cout ("2016R2A.txt");
  int t;
  cin >> t;//
  for (int i=1;i<=t;i++) {
    cin >> n;
    for (int k=0;k<n;k++) {
      cin >> a[k];
    }
    for (int k=0;k<n;k++) {
      cin >> b[k];
    }
    cout << "Case #" << i << ": " << solve() << endl;//
  }
  return 0;
}
