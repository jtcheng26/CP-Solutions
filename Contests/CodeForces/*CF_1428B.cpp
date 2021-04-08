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
char edges[300001];

int solve() {
  int res = 0;
  edges[n] = edges[0];
  int j;
  char sym = '?';
  for (j=0;j<n;j++) {
    if (sym == '?' && edges[j] != '-') sym = edges[j];
    if (edges[j] != sym && edges[j] != '-') break;
  }
  if (j == n) return n;
  for (int i=0;i<n;i++) {
    if (edges[i] == '-' || edges[i+1] == '-') {
      res++;
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=0;i<n;i++) {
      cin >> edges[i];
    }
    cout << solve() << endl;
  }
  return 0;
}
