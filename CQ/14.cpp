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
string a;
vector<int> s;
vector<int> d;

string solve() {
  string ans;
  int p1 = 0;
  int p2 = 0;
  ans = a;
  for (int i=0;i<a.length();i++) {
    if (a[i] - 'A' < 26 && a[i] - 'A' >= 0) {
      if (d[p2] == 1) {
        int nxt = (a[i] - 'A' - s[p1] + 26) % 26;
        ans[i] = (char) (nxt + 'a');
      } else {
        int nxt = (a[i] - 'A' + s[p1]) % 26;
        ans[i] = (char) (nxt + 'a');
      }
      p1 = (p1 + 1) % s.size();
      p2 = (p2 + 1) % d.size();
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  string temp;
  getline(cin, temp);
  while (t--) {
    getline(cin, a);
    s.clear();
    d.clear();
    string b;
    getline(cin, b);
    string c;
    for (int i=0;i<b.size();i++) {
      if (b[i] == ' ') {
        s.pb(stoi(c));
        c = "";
      } else {
        c += b[i];
      }
    }
    s.pb(stoi(c));
    c = "";
    getline(cin, b);
    for (int i=0;i<b.size();i++) {
      if (b[i] == ' ') {
        d.pb(stoi(c));
        c = "";
      } else {
        c += b[i];
      }
    }
    d.pb(stoi(c));
    cout << solve() << "\n";
  }
  return 0;
}