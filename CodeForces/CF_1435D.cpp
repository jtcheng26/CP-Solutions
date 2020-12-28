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

struct event {
  char type;
  int num;
};

int n;
vector<event> events;
int ans[100001];

bool solve() {
  stack<int> left;
  int cnt = 1;
  for (int i=0;i<2*n;i++) {
    if (events[i].type == '+')
      left.push(cnt++);
    else {
      if (left.empty()) return false;
      ans[left.top()] = events[i].num;
      left.pop();
    }
  }
  //for (int i=1;i<=n;i++) cout << ans[i] << (i==n ? "\n" : " ");
  priority_queue<int, vector<int>, greater<int> > minHeap;
  cnt = 1;
  for (int i=0;i<2*n;i++) {
    if (events[i].type == '+')
      minHeap.push(ans[cnt++]);
    else {
      if (minHeap.top() != events[i].num) return false;
      minHeap.pop();
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  for (int i=0;i<2*n;i++) {
    event e;
    cin >> e.type;
    if (e.type == '-') cin >> e.num;
    events.pb(e);
  }
  bool res = solve();
  if (res) {
    cout << "YES" << "\n";
    for (int i=1;i<=n;i++) {
      cout << ans[i] << (i == n ? "\n" : " ");
    }
  } else {
    cout << "NO" << "\n";
  }
  return 0;
}
