#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

#define mp make_pair
#define pb push_back
#define F first
#define S second

typedef long long ll;

using namespace std;

int n;
int shuffleOrder[101];
int order[101];

void solve() {
  int prev[101];
  for (int k=0;k<3;k++) {
    for (int i=0;i<n;i++) {
      prev[i] = order[shuffleOrder[i]-1];
    }
    for (int i=0;i<n;i++) {
      order[i] = prev[i];
    }
  }
}

int main() {
  ofstream cout ("shuffle.out");
  ifstream cin ("shuffle.in");
  cin >> n;
  for (int i=0;i<n;i++) cin >> shuffleOrder[i];
  for (int i=0;i<n;i++) {
    cin >> order[i];
  }
  solve();
  for (int i=0;i<n;i++) {
    cout << order[i] << "\n";
  }
  return 0;
}
