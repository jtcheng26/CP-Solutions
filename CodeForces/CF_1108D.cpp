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
char lamps[200001];

int solve() {
  int res = 0;
  if (n == 1) return 0;
  for (int i=1;i<n-1;i++) {
    if (lamps[i] == lamps[i-1]) {
      res++;
      if (lamps[i-1] == 'R') {
        if (lamps[i+1] == 'B' || lamps[i+1] == 'R') lamps[i] = 'G';
        else if (lamps[i+1] == 'G') lamps[i] = 'B';
      } else if (lamps[i-1] == 'B') {
        if (lamps[i+1] == 'R' || lamps[i+1] == 'B') lamps[i] = 'G';
        else if (lamps[i+1] == 'G') lamps[i] = 'R';
      } else {
        if (lamps[i+1] == 'R' || lamps[i+1] == 'G') lamps[i] = 'B';
        else if (lamps[i+1] == 'B') lamps[i] = 'R';
      }
    }
  }
  if (n >= 2) {
    if (lamps[n-1] == lamps[n-2]) {
      res++;
      if (lamps[n-2] == 'R') lamps[n-1] = 'B';
      else if (lamps[n-2] == 'B') lamps[n-1] = 'G';
      else lamps[n-1] = 'R';
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  for (int i=0;i<n;i++) {
    cin >> lamps[i];
  }
  cout << solve() << endl;
  for (int i=0;i<n;i++) cout << lamps[i] << (i == n-1 ? "\n" : "");
  return 0;
}
