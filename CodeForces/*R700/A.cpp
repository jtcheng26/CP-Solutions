#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INF 1000000001
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

string s;

string solve() {
  string res = "";
  int curr = 0;
  for (int i=0;i<s.length();i++) {
    if (curr == 0) {
      if (s[i] != 'a')
        res += 'a';
      else
        res += 'b';
    } else {
      if (s[i] != 'z')
        res += 'z';
      else
        res += 'y';
    }
    curr = !curr;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> s;
    cout << solve() << "\n";
  }
  return 0;
}
