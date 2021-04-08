#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INF 1000000001
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int n;
int a[50001];
int b[50001];

int solve() {
  vector<int> b1;
  vector<int> b2;
  bool fnd[2*n+1];
  for (int i=1;i<=2*n;i++) fnd[i] = false;
  for (int i=0;i<n/2;i++) {
    b1.pb(b[i]);
    fnd[b[i]] = true;
  }
  for (int i=n/2;i<n;i++) {
    b2.pb(b[i]);
    fnd[b[i]] = true;
  }
  deque<int> a1;
  queue<int> a2;
  int cnt = 0;
  for (int i=1;i<=2*n;i++) {
    if (!fnd[i]) {
      cnt++;
      if (cnt <= n / 2) {
        //cout << "a1 " << i << "\n";
        a1.push_front(i);
      } else {
        a2.push(i);
        //cout << "a2 " << i << "\n";
      }
    }
  }
  sort(b1.begin(), b1.end());
  sort(b2.rbegin(), b2.rend());
  int res = 0;
  for (int i=0;i<b1.size();i++) {
    while (!a2.empty() && a2.front() < b1[i]) {
      a2.pop();
    }
    if (!a2.empty()) {
      a2.pop();
      res++;
    } else {
      break;
    }
  }
  for (int i=0;i<b2.size();i++) {
    while (!a1.empty() && a1.front() > b2[i]) {
      a1.pop_front();
    }
    if (!a1.empty()) {
      a1.pop_front();
      res++;
    } else {
      break;
    }
  }
  return res;
}

int main() {
  ofstream cout ("cardgame.out");
  ifstream cin ("cardgame.in");
  cin >> n;
  for (int i=0;i<n;i++) {
    cin >> b[i];
  }
  cout << solve() << endl;
  return 0;
}
