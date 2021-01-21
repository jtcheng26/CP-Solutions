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
char res[1000001];

bool solve() {
  map<char, int> cnt;
  vector<char> characters;
  for (int i=0;i<s.length();i++) {
    cnt[s[i]]++;
    if (cnt[s[i]] == 1) characters.pb(s[i]);
  }
  int l = 0;
  int r = s.length() - 1;
  int bad = 0;
  for (int i=0;i<characters.size();i++) {
    if (cnt[characters[i]] % 2 != 0) bad++;
  }
  if (bad > 1 || (bad == 1 && s.length() % 2 == 0)) return false;
  for (int i=0;i<characters.size();i++) {
    if (cnt[characters[i]] % 2 == 1) {
      res[s.length() / 2] = characters[i];
      cnt[characters[i]]--;
    }
    for (int j=0;j<cnt[characters[i]] / 2;j++) {
      res[l++] = characters[i];
      res[r--] = characters[i];
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> s;
  if (!solve()) {
    cout << "NO SOLUTION" << "\n";
  } else {
    for (int i=0;i<s.length();i++) {
      cout << res[i] << (i == s.length() - 1 ? "\n" : "");
    }
  }
  return 0;
}
