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
int a[200001];

int solve() {
  int res = 1;
  int curr = 1;
  int nxt = 0;
  int nxtUsed = 1;
  for (int i=1;i<n;i++) {
    if (a[i] < a[i-1]) {
      if (nxtUsed == curr) {
        curr = nxt;
        nxt = 0;
        nxtUsed = 0;
        res++;
      }
      nxtUsed++;
    }
    nxt++;
    //cout << curr << " " << nxt << " " << nxtUsed << "\n";
  }
  if (nxtUsed > curr) res++;
  return max(1, res);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    cout << solve() << "\n";
  }
  return 0;
}
