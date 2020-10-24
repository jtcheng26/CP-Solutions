#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

struct timb {
  ll loc, len;
};

vector<timb> trees;
map<ll, vector<ll> > tree_locs;
//vector<pair<ll, ll> > links;
ll n;

bool cmp(timb a, timb b) {
  return a.loc < b.loc;
}

void set_connections() {
  for (ll i=0;i<n;i++) {
    vector<ll> lrmax;
    lrmax.resize(2);
    lrmax[0] = 0; lrmax[1] = 0;
    vector<ll> lmax;
    lmax.resize(2);
    lmax[0] = 0; lmax[1] = 0;
    vector<ll> rmax;
    rmax.resize(2);
    rmax[0] = 0; rmax[1] = 0;
    tree_locs[trees[i].loc] = lrmax;
    tree_locs[trees[i].loc+trees[i].len] = rmax;
    tree_locs[trees[i].loc-trees[i].len] = lmax;
  }
}

ll solve() {
  ll res = 0;
  sort(trees.begin(), trees.end(), cmp); // sort by location
  set_connections(); // create map of locs
  for (ll i=0;i<trees.size();i++) {
    // L -> R
    //cout << trees[i].loc+trees[i].len << " " << tree_locs[trees[i].loc][0] + trees[i].len << endl;
    tree_locs[trees[i].loc+trees[i].len][0] = max(tree_locs[trees[i].loc+trees[i].len][0], tree_locs[trees[i].loc][0] + trees[i].len);
  }
    //cout << trees[i].rmax << endl;
  for (ll i=trees.size()-1;i>=0;i--) {
    //cout << trees[i].loc-trees[i].len << " " << tree_locs[trees[i].loc][1] + trees[i].len << endl;
    tree_locs[trees[i].loc-trees[i].len][1] = max(tree_locs[trees[i].loc-trees[i].len][1], tree_locs[trees[i].loc][1] + trees[i].len);
    //cout << trees[i].lmax << endl;
  }
  for (ll i=0;i<trees.size();i++) {
    ll ma = max(max(tree_locs[trees[i].loc][0] + tree_locs[trees[i].loc][1], tree_locs[trees[i].loc+trees[i].len][0] + tree_locs[trees[i].loc+trees[i].len][1]), tree_locs[trees[i].loc-trees[i].len][0] + tree_locs[trees[i].loc-trees[i].len][1]);
    if (ma > res)
      res = ma;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  ifstream fin ("Timber_final.txt");
  ofstream fout ("2020Q3_final.txt");
  int t;
  fin >> t;//
  for (int i=1;i<=t;i++) {
    trees.clear();
    tree_locs.clear();
    fin >> n; timb ti;
    for (ll j=0;j<n;j++) {
      fin >> ti.loc >> ti.len;
      trees.push_back(ti);
    }
    cout << "Case #" << i << ": " << solve() << endl;//
  }
  return 0;
}
