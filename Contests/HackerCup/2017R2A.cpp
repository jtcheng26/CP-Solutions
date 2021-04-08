#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 1e18+7
#define pb push_back
#define F first
#define S second

typedef long long ll;

using namespace std;

int n, m, k;

int solve() {
  int res = 0;
  int rparts = (n + k - 1) / k;
  int cparts = (m + k - 1) / k;
  int mx = k == 1 ? 5 : 4;
  if (rparts <= 1 || cparts <= 1) return -1;
  if (m - 2 * k < 3 && n - 2 * k < 3) return -1;
  return min(mx, min(rparts, cparts));
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  ifstream cin ("subtle_sabotage_input.txt");
  ofstream cout ("2017R2A.txt");
  int t;
  cin >> t;//
  for (int i=1;i<=t;i++) {
    cin >> n >> m >> k;
    cout << "Case #" << i << ": " << solve() << endl;//
  }
  return 0;
}
