#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>

#define INFI 1e18+7
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long ll;

using namespace std;

int n, q;
set<int> piles; // initial piles
multiset<int> gaps;

int remove_position(int p) {
  auto it = piles.find(p);
  if (it != prev(piles.end())) {
    gaps.erase(gaps.find(*next(it) - p));
  }
  if (it != piles.begin()) {
    gaps.erase(gaps.find(p - *prev(it)));
    if (it != prev(piles.end())) {
      gaps.insert(*next(it) - *prev(it));
    }
  }
  piles.erase(it);
  if (piles.size() <= 2 || gaps.size() == 0) return 0;
  return *prev(piles.end()) - *piles.begin() - *prev(gaps.end());
}

int add_position(int p) {
  auto it = piles.insert(p).F;
  if (it != prev(piles.end())) {
    gaps.insert(*next(it) - p);
  }
  if (it != piles.begin()) {
    gaps.insert(p - *prev(it));
    if (it != prev(piles.end())) {
      gaps.erase(gaps.find(*next(it) - *prev(it)));
    }
  }
  if (piles.size() <= 2 || gaps.size() == 0) return 0;
  return *prev(piles.end()) - *piles.begin() - *prev(gaps.end());
}

int solve() {
  for (auto it=next(piles.begin());it!=piles.end();it++) {
    gaps.insert(*it - *prev(it));
  }
  if (piles.size() <= 2 || gaps.size() == 0) return 0;
  return *prev(piles.end()) - *piles.begin() - *prev(gaps.end());
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> q;
  int a;
  for (int i=0;i<n;i++) {
    cin >> a;
    piles.insert(a);
  }
  cout << solve() << "\n";
  for (int i=0;i<q;i++) {
    int t, x;
    cin >> t >> x;
    if (t == 1) cout << add_position(x) << "\n";
    else cout << remove_position(x) << "\n";
  }
  return 0;
}
