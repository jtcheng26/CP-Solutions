#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

int n;
int order[101];

int solve() {
  int cnt = 1;
  for (int i=n-2;i>=0;i--) {
    if (order[i] < order[i+1]) cnt++;
    else break;
  }
  return n - cnt;
}

int main() {
  ofstream cout ("sleepy.out");
  ifstream cin ("sleepy.in");
  cin >> n;
  for (int i=0;i<n;i++) {
    cin >> order[i];
  }
  cout << solve() << endl;
  return 0;
}
