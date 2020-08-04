#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

ll q, n;
string pipes[2];


bool solve() {
  int row = 0; int col = 0;
  int prev_row = 0; int prev_col = 0;
  for (int i=0;col<n;i++) {
    int val = stoi(pipes[row].substr(col, 1));
    int rtemp = row; int ctemp = col;
    if (val <= 2) {
      col++;
    } else {
      if (prev_row == row) {
        row = prev_row == 0 ? 1 : 0;
        if (stoi(pipes[row].substr(col, 1)) <= 2) return false;
      }
      else col++;
    }
    prev_row = rtemp; prev_col = ctemp;
  }
  return col == n && row == 1;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> q;
  for (int i=0;i<q;i++) {
    cin >> n; cin >> pipes[0]; cin >> pipes[1];
    bool res = solve();
    if (res) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
