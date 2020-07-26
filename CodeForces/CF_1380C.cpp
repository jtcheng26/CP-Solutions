#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

int t; vector<int> ppl; vector<int> team; int x;

int solve() {
  int res = 0;
  sort(ppl.begin(), ppl.end());
  team.clear();
  for (int i=ppl.size()-1;i>=0;i--) {
    team.push_back(ppl[i]);
    if (ppl[i] * team.size() >= x) {
      res++;
      team.clear();
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> t;
  for (int i=0;i<t;i++) {
    ppl.clear();
    int n, a; cin >> n >> x;
    for (int j=0;j<n;j++) {
      cin >> a;
      ppl.push_back(a);
    }
    cout << solve() << endl;
  }
  return 0;
}
