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

string n;
int s;
int nums[40];
int sum;
ll ans = 0;
int digits;
ll p[19];

ll sumDigits(string str) {
  ll sum = 0;
  for (int i=0;i<str.length();i++) {
    sum += str[i] - '0';
  }
  return sum;
}

ll power(int num) {
  return p[num];
}

void rec(int dig, int add) {
  nums[dig] += add;
  sum += add;
  if (dig >= digits || sum <= s) {
    return;
  }
  if (nums[dig] == 10) {
    sum -= 10;
    nums[dig] = 0;
    //cout << sum << " " << nums[dig] << " " << dig << endl;
    rec(dig+1, 1);
    return;
  }
  ans += (10 - nums[dig]) * power(dig);
  sum -= nums[dig];
  nums[dig] = 0;
  //cout << sum << " " << ans << " " << dig << endl;
  rec(dig+1, 1);
}

ll solve() {
  sum = sumDigits(n);
  ans = 0;
  p[0] = 1;
  for (int i=1;i<19;i++) {
    p[i] = p[i-1] * 10;
  }
  for (int i=0;i<40;i++) nums[i] = 0;
  if (sum <= s) return 0;
  digits = n.length();
  for (int i=0;i<digits;i++) {
    nums[digits - i - 1] = n[i] - '0';
  }
  if (digits == 1) return 10 - nums[0];
  rec(0, 0);
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> s;
    cout << solve() << endl;
  }
  return 0;
}
