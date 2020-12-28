#include <iostream>
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
char a[200001];

int solve() {
  int cnt[2] = {0};
  for (int i=0;i<n;i++) {
    cnt[a[i] - '0']++;
  }
  return max(cnt[0], cnt[1]) - min(cnt[0], cnt[1]);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  for (int i=0;i<n;i++) cin >> a[i];
  cout << solve() << "\n";
  return 0;
}
