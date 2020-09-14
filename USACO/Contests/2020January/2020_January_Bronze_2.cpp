#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

ll n;
int c[100000];
bool u[100000] = {false};
int ans[100000] = {0};

bool dfs(int prev, int c_i) {
  if (c_i > n-2) return true;
  if (c[c_i] - prev <= 0 || c[c_i] - prev > n || u[c[c_i] - prev]) return false;
  u[c[c_i] - prev] = true;
  ans[c_i+1] = c[c_i] - prev;
  bool res = dfs(c[c_i] - prev, c_i+1);
  if (res) return true;
  u[c[c_i] - prev] = false;
  return res;
}

int solve() {
  for (int i=1;i<c[0];i++) {
    if (c[0] - i == i) continue;
    u[i] = true; u[c[0]-i] = true;
    ans[0] = i; ans[1] = c[0] - i;
    if (dfs(ans[1], 1)) return 1;
    u[i] = false; u[c[0]-i] = false;
  }
  return 0;
}

int main() {
  ofstream fout ("photo.out");
  ifstream fin ("photo.in");
  fin >> n;
  for (int i=0;i<n-1;i++) {
    fin >> c[i];
  }
  solve();
  for (int i=0;i<n-1;i++) {
    fout << ans[i] << " ";
  }
  fout << ans[n-1] << endl;
  return 0;
}
