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

int solve() {
  int best = 0;
  string num = "";
  for (int i=0;i<s.length();i++) {
    if (s[i] != ' ') {
      num += s[i];
    } else {
      best = max(best, stoi(num));
      num = "";
    }
  }
  best = max(best, stoi(num));
  return best;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  getline(cin, s);
  for (int i=0;i<n;i++) {
    getline(cin, s);
    cout << solve() << "\n";
  }
  return 0;
}