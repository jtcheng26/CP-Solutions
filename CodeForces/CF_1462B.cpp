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

int n;
string s;

bool solve() {
  if (s.substr(0, 2) == "20" && s.substr(s.length()-2, s.length()) == "20") return true;
  if (s.substr(0, 1) == "2" && s.substr(s.length()-3, s.length()) == "020") return true;
  if (s.substr(s.length()-1, s.length()) == "0" && s.substr(0, 3) == "202") return true;
  if (s.substr(0, 4) == "2020") return true;
  if (s.substr(s.length()-4, s.length()) == "2020") return true;
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> s;
    cout << (solve() ? "YES" : "NO") << "\n";
  }
  return 0;
}
