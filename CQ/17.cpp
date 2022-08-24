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
int r, c;
vector<vector<string> > a;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> r >> c;
    a.clear();
    a.resize(r);
    string temp;
    getline(cin, temp);
    for (int i=0;i<r;i++) {
      string c = "";
      string line;
      getline(cin, line);
      for (int j=0;j<line.length();j++) {
        if (line[j] == ',') {
          a[i].pb(c);
          c = "";
        } else {
          c += line[j];
        }
      }
      a[i].pb(c);
    }
    for (int i=0;i<c;i++) {
      for (int j=0;j<r;j++) {
        cout << a[j][i] << (j == r-1 ? "\n" : ",");
      }
    }
  }
  return 0;
}