#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define pb push_back
#define INFI 100000007

typedef long long ll;

using namespace std;

int n;
int a[100001];
int b[100001];
vector<int> seq;

int solve() {
  int res = 0;
  for (int i=0;i<n-1;i++) {
    if (a[i] != a[i+1]) {
      a[i] = a[i+1];
      seq.pb(i+1);
    }
  }
  vector<int> rev;
  for (int i=0;i<n-1;i++) {
    if (b[i] != b[i+1]) {
      b[i] = b[i+1];
      rev.pb(i+1);
    }
  }
  if (a[n-1] != b[n-1]) seq.pb(n);
  for (int i=rev.size()-1;i>=0;i--) {
    seq.pb(rev[i]);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    seq.clear();
    cin >> n;
    for (int i=0;i<n;i++) {
      char c;
      cin >> c;
      a[i] = c - '0';
    }
    for (int i=0;i<n;i++) {
      char c;
      cin >> c;
      b[i] = c - '0';
    }
    solve();

    cout << seq.size() << " ";
    if (seq.size() != 0) {
      for (int i=0;i<seq.size() - 1;i++) {
        cout << seq[i] << " ";
      }
      cout << seq[seq.size() - 1];
    }
    cout << endl;
  }
  return 0;
}
