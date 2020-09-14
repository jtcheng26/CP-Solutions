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

string a[1001];
int n;

bool solve() {
  int letters[26] = {0};
  for (int i=0;i<n;i++) {
    for (int j=0;j<a[i].length();j++) {
      letters[a[i][j] - 'a']++;
    }
  }
  for (int i=0;i<26;i++) {
    if (letters[i] > 0 && letters[i] % n != 0) return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=0;i<n;i++) {
      cin >> a[i];
    }
    cout << (solve() ? "YES" : "NO") << endl;
  }
  return 0;
}
