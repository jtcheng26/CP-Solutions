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
#define mp make_pair
#define F first
#define S second

typedef long long ll;

using namespace std;

int n;
int a[50001];

bool solve() {
  deque<int> dq;
  int top = 1;
  int bot = n-1;
  bool flag = true;
  dq.push_front(a[0]);
  while (dq.size() < n) {
    if (a[top] == dq.front() - 1) {
      dq.push_front(a[top]);
      top++;
    } else if (a[top] == dq.back() + 1) {
      dq.push_back(a[top]);
      top++;
    } else {
      if (a[bot] == dq.front() - 1) {
        dq.push_front(a[bot]);
        bot--;
      } else if (a[bot] == dq.back() + 1) {
        dq.push_back(a[bot]);
        bot--;
      } else {
        flag = false;
        break;
      }
    }
  }
  if (flag) return true;
  dq.clear();
  top = 0;
  bot = n-2;
  dq.push_front(a[n-1]);
  while (dq.size() < n) {
    if (a[top] == dq.front() - 1) {
      dq.push_front(a[top]);
      top++;
    } else if (a[top] == dq.back() + 1) {
      dq.push_back(a[top]);
      top++;
    } else {
      if (a[bot] == dq.front() - 1) {
        dq.push_front(a[bot]);
        bot--;
      } else if (a[bot] == dq.back() + 1) {
        dq.push_back(a[bot]);
        bot--;
      } else {
        return false;
      }
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  ifstream cin ("lazy_sort_input.txt");
  ofstream cout ("2015R2A.txt");
  int t;
  cin >> t;//
  for (int i=1;i<=t;i++) {
    cin >> n;
    for (int j=0;j<n;j++) cin >> a[j];
    cout << "Case #" << i << ": " << (solve() ? "yes" : "no") << endl;//
  }
  return 0;
}
