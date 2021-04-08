#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define mp make_pair
#define pb push_back
#define F first
#define S second

typedef long long ll;

using namespace std;

int n;
int a[100001] = {0};

int solve() {
  int res = 0;
  queue<int> w;
  for (int i=1;i<=2*n;i++) {
    if (a[i] == 1) w.push(i);
    else {
      if (!w.empty()) {
        w.pop();
        res++;
      }
    }
  }
  return res;
}

int main() {
  ofstream cout ("highcard.out");
  ifstream cin ("highcard.in");
  cin >> n;
  for (int i=0;i<n;i++) {
    int j;
    cin >> j;
    a[j] = 1;
  }
  cout << solve() << endl;
  return 0;
}
