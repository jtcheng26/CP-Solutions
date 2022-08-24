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

int n, m;
string s;
string t;

int solve() {
  int res = 0;
  vector<int> left(m, n);
  vector<int> right(m, 0);
  int j = 0;
  for (int i=0;i<m;i++) {
    while (s[j] != t[i]) {
      j++;
    }
    left[i] = j;
    j++;
  }
  j = n - 1;
  for (int i=m-1;i>=0;i--) {
    while (s[j] != t[i]) {
      j--;
    }
    right[i] = j;
    j--;
  }
  for (int i=0;i<m-1;i++) {
    res = max(res, right[i+1] - left[i]);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> m;
  cin >> s;
  cin >> t;
  cout << solve() << "\n";
  return 0;
}