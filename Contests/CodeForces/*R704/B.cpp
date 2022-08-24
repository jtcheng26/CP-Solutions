#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>

#define INF 1000000001
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int n;
string s;
int len = 1;
string c;
string best = "";
map<string, bool> exists;
void gen(int k) {
  if (k == len) {
    if (exists[c]) return;
    best = c;
    return;
  }
  for (int i=0;i<26;i++) {
    c[k] = (char) ('a' + i);
    gen(k+1);
    if (best != "") {
      return;
    }
  }
}

string solve() {
  exists.clear();
  best = "";
  for (int l=0;l<n;l++) {
    for (int r=l;r<n;r++) {
      exists[s.substr(l, r-l+1)] = true;
    }
  }
  for (len=1;len<=5;len++) {
    c = "";
    for (int i=0;i<len;i++) {
      c += " ";
    }
    gen(0);
    if (best != "") return best;
  }
  return best;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> s;
    cout << solve() << "\n";
  }
  return 0;
}