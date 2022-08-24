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

string s;
char l[4] = {'A', 'O', 'N', 'T'};

string solve() {
  string res = "";
  ll inv[4][4];
  int cnt[26] = {0};
  for (int i=0;i<4;i++) {
    for (int j=0;j<4;j++) {
      inv[i][j] = 0;
    }
  }
  for (int i=0;i<s.length();i++) {
    cnt[s[i] - 'A']++;
  }
  for (int i=0;i<4;i++) {
    for (int j=0;j<4;j++) {
      if (i == j) continue;
      int c = 0;
      for (int k=0;k<s.length();k++) {
        if (s[k] == l[i]) c++;
        else if (s[k] == l[j]) inv[i][j] += c;
      }
    }
  } 
  int used[4] = {0, 1, 2, 3};
  ll b = 0;
  int best[4] = {0, 1, 2, 3};
  do {
    ll cnt = 0;
    for (int i=0;i<4;i++) {
      for (int j=i+1;j<4;j++) {
        cnt += inv[used[j]][used[i]];
      }
    }
    if (cnt > b) {
      b = cnt;
      for (int i=0;i<4;i++) {
        best[i] = used[i];
      }
    }
  } while (next_permutation(used, used+4));
  for (int i=0;i<4;i++) {
    for (int j=0;j<cnt[l[best[i]] - 'A'];j++)
      res += l[best[i]];
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