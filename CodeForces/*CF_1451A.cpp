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

int solve() {
  int res = 0;
  int moves = n - 1;
  int choice = 0;
  if (n % 2 == 0) choice = 2;
  else choice = 3;
  return min(moves, choice);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    cout << solve() << "\n";
  }
  return 0;
}
