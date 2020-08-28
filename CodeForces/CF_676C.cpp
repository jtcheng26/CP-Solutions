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

int n, k;
char s[100001];

int solve() {
  int res = 0;
  int i = 0;
  int j = 0;
  int wrong[2] = {0};
  wrong[s[0] - 'a']++;
  while (j < n) {
    if (min(wrong[0], wrong[1]) > k) {
      res = max(res, j - i);
      //cout << i << " " << j << endl;
      wrong[s[i] - 'a']--;
      i++;
    }
    else {
      res = max(res, j - i + 1);
      j++;
      if (j < n) wrong[s[j] - 'a']++;
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> k;
  for (int i=0;i<n;i++) cin >> s[i];
  cout << solve() << endl;
  return 0;
}
