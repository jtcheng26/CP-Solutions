#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 1e18+7
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long ll;

using namespace std;

int n, k;

string solve() {
  string res = "";
  for (int i=0;i<n / 3;i++) {
    res += "abc";
  }
  string letters[3] = {"a", "b", "c"};
  for (int i=0;i<n%3;i++) {
    res += letters[i];
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    cout << solve() << "\n";
  }
  return 0;
}
