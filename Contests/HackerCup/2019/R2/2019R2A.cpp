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
#define mp make_pair
#define F first
#define S second

typedef long long ll;

using namespace std;

int n, m, k;
int x[2];
int haha[2][2]; // row/col

bool solve() {
  if (k == 1) return false;
  if ((abs(haha[0][0] - x[0]) + abs(haha[0][1] - x[1])) % 2 == 0 &&
      abs((haha[1][0] - x[0]) + abs(haha[1][1] - x[1])) % 2 == 0
  ) return true;
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  ifstream cin ("on_the_run_input.txt");
  ofstream cout ("2019R2A.txt");
  int t;
  cin >> t;//
  for (int i=1;i<=t;i++) {
    cin >> n >> m >> k;
    cin >> x[0] >> x[1];
    for (int i=0;i<k;i++) {
      cin >> haha[i][0] >> haha[i][1];
    }
    cout << "Case #" << i << ": " << (solve() ? "Y" : "N") << endl;//
  }
  return 0;
}
