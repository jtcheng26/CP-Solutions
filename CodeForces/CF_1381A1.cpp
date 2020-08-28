#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 100000007

typedef long long ll;

using namespace std;

int n;
int a[1001];
int b[1001];
vector<int> seq;

int solve() {
  int res = 0;
  if (a[0] != b[0]) seq.push_back(1);
  for (int i=1;i<n;i++) {
    if (a[i] != b[i]) {
      seq.push_back(i+1);
      seq.push_back(1);
      seq.push_back(i+1);
    }
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
