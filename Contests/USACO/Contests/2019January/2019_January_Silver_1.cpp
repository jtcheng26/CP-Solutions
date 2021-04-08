// Time - 20:47

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

typedef long long ll;

using namespace std;

ll n;
vector<int> edges[100001];

int solve() {
  int res = 0;
  for (int u=0;u<n;u++) {
    res = max(res, (int) edges[u].size());
  }
  return res+1;
}

int main() {
  ofstream cout ("planting.out");
  ifstream cin ("planting.in");
  cin >> n;
  for (int i=0;i<n-1;i++) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  cout << solve() << endl;
  return 0;
}
