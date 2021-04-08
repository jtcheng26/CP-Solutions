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

int n, k;
vector<pair<int, int> > edges;
vector<int> weights;

int solve() {
  int res = 0;
  edges.pb(make_pair(1, n));
  weights.pb(k);
  if (k <= 2 || n <= 2) return 0;
  for (int i=1;i<n;i++) {
    if (k - i == 1) {
      edges.pb(make_pair(i, n));
      weights.pb(k - i);
      res += (k - i);
      break;
    }
    edges.pb(make_pair(i, i+1));
    weights.pb(k - i);
    res += k - i;
  }
  return max(res - k, 0);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  ifstream cin ("ethan_finds_the_shortest_path_input.txt");
  ofstream cout ("2018R2A.txt");
  int t;
  cin >> t;//
  for (int i=1;i<=t;i++) {
    edges.clear();
    weights.clear();
    cin >> n >> k;
    cout << "Case #" << i << ": " << solve() << endl;//
    cout << edges.size() << endl;
    for (int i=0;i<edges.size();i++) {
      cout << edges[i].F << " " << edges[i].S << " " << weights[i] << endl;
    }
  }
  return 0;
}
