#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <stack>

#define INFI 1e18+7
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long ll;

using namespace std;

int n;
int hits[100010];
vector<pair<int, int> > ans;

int solve() {
  int res = 0;
  int currY = 1;
  priority_queue<pair<int, int> > ones;
  priority_queue<pair<int, int> > twosQ;
  vector<int> threes;
  stack<pair<int, int> > oneS;
  for (int i=n;i>=1;i--) {
    if (hits[i] == 1) {
      ans.pb(mp(i, currY));
      oneS.push(mp(i, currY++));
    } else if (hits[i] == 2) {
      if (oneS.size() == 0) return -1;
      ans.pb(mp(i, oneS.top().S));
      twosQ.push(mp(i, oneS.top().S));
      oneS.pop();
    } else if (hits[i] == 3) threes.pb(i);
  }
  while (oneS.size() > 0) {
    ones.push(oneS.top());
    oneS.pop();
  }
  for (int i=0;i<threes.size();i++) {
    if (currY > n || (ones.size() == 0 && twosQ.size() == 0)) {
      return -1;
    }
    if (ones.size() > 0 && ones.top().F > threes[i]) {
      ans.pb(mp(threes[i], currY));
      ans.pb(mp(ones.top().F, currY));
      twosQ.push(mp(threes[i], currY++));
      ones.pop();
    } else if (twosQ.size() > 0 && twosQ.top().F > threes[i]) {
        ans.pb(mp(threes[i], currY));
        ans.pb(mp(twosQ.top().F, currY));
        twosQ.pop();
        twosQ.push(mp(threes[i], currY++));
    } else return -1;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  for (int i=1;i<=n;i++) cin >> hits[i];
  int a = solve();
  if (a == -1) {
    cout << "-1\n";
  } else {
    cout << ans.size() << "\n";
    for (int i=0;i<ans.size();i++)
      cout << (n + 1 - ans[i].S) << " " << ans[i].F << "\n";
  }
  return 0;
}
