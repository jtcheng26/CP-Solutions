#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 1e18+7
#define pb push_back
#define F first
#define S second

typedef long long ll;

using namespace std;

int n;
int a[100001];
int b[100001];
bool seen[100001];

int solve() {
  int res = 0;
  for (int i=0;i<=n;i++) seen[i] = false;
  int j = 0;
  int i = 0;
  int cnt = 0;
  while (i < n) {
    if (seen[a[i]]) {
      i++;
      continue;
    }
    if (a[i] == b[j]) {
      seen[a[i]] = true;
      j++;
      i++;
      cnt++;
    } else {
      res++;
      seen[b[j]] = true;
      j++;
      cnt++;
    }
    //cout << i << " " << j << endl;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> n;
  for (int i=0;i<n;i++) {
    cin >> a[i];
  }
  for (int i=0;i<n;i++) {
    cin >> b[i];
  }
  cout << solve() << endl;
  return 0;
}
