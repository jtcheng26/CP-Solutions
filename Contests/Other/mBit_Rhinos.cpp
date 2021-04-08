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

struct rhino {
  int stamina, direction;
};

int LEFT = 0;
int RIGHT = 1;
int n;
rhino rhinos[100001];

vector<int> solve() {
  stack<int> rights; // right-facing rhinos
  for (int i=0;i<n;i++) {
    if (rhinos[i].direction == RIGHT) {
      rights.push(i);
    } else {
      while (rights.size() > 0 && rhinos[i].stamina > 0) {
        int top = rights.top();
        int rem = abs(rhinos[i].stamina - rhinos[top].stamina);
        if (rhinos[top].stamina > rhinos[i].stamina) {
          rhinos[top].stamina = rem;
          rhinos[i].stamina = 0;
        }
        else if (rhinos[i].stamina > rhinos[top].stamina) {
          rhinos[i].stamina = rem;
          rhinos[top].stamina = 0;
          rights.pop();
        } else {
          rhinos[i].stamina = 0;
          rhinos[top].stamina = 0;
          rights.pop();
        }
      }
    }
  }
  vector<int> res;
  for (int i=0;i<n;i++) {
    if (rhinos[i].stamina > 0) {
      res.pb(i);
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  for (int i=0;i<n;i++) {
    cin >> rhinos[i].stamina >> rhinos[i].direction;
  }
  vector<int> ans = solve();
  cout << ans.size() << "\n";
  for (int i=0;i<ans.size();i++) {
    cout << rhinos[ans[i]].stamina << " " << rhinos[ans[i]].direction << "\n";
  }
  return 0;
}
