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
string digits;
int m;

string solve() {
  m = n;
  string res = digits.substr(0, k);
  for (int i=k;i<n;i++) res += res[i-k];
  if (res >= digits) return res;
  int dig = k-1;
  while (res[dig] == '9' && dig > 0) dig--;
  res[dig] = (char) (res[dig]+1);
  for (int j=dig+1;j<k;j++) res[j] = '0';
  for (int i=k;i<n;i++)
    res[i] = res[i-k];
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> k;
  cin >> digits;
  string ans = solve();
  cout << m << "\n";
  cout << ans << "\n";
  //for (int i=0;i<n;i++) cout << digits[i] << (i == n-1 ? "\n" : "");
  return 0;
}
