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
int n;

vector<string> solve() {
  vector<string> ans;
  vector<string> empty;
  int i = 0;
  string beforeDot = "";
  string afterDot = "";
  while (i < n) {
    if (beforeDot.size() > 8) return empty;
    //cout << i << " " << beforeDot << "\n";
    if (s[i] == '.') {
      if (beforeDot.length() > 0) {
        int lim = i+3;
        i++;
        for (;i<=lim&&i<n&&s[i]!='.'&&(i==n-1 || s[i+1] != '.');i++) {
          afterDot += s[i];
        }
        if (afterDot.length() > 0 && (i == n || s[i] != '.')) {
          ans.pb(beforeDot + "." + afterDot);
          if (i == n)
            beforeDot = "";
          else
            beforeDot = s[i];
          afterDot = "";
        } else {
          return empty;
        }
      } else {
        return empty;
      }
    } else {
      beforeDot += s[i];
    }
    i++;
  }
  if (beforeDot.length() == 0)
    return ans;
  return empty;
}

int main() {
  cin >> s;
  n = s.length();
  vector<string> ans = solve();
  if (ans.size() > 0) {
    cout << "YES" << "\n";
    for (string& str : ans) {
      cout << str << "\n";
    }
  } else {
    cout << "NO" << "\n";
  }
  return 0;
}
