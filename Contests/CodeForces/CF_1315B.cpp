#include <iostream>
#include <string>
 
typedef long long ll;
 
using namespace std;
 
ll solve() {
    ll a, b, p; string str;
    cin >> a; cin >> b; cin >> p; cin >> str;
    const ll l = str.length();
    ll dp[l] = {0};
    dp[l-1] = 0;
    string last = str.substr(l-2, 1);
    dp[l-2] = (str.substr(l-2, 1) == "A") ? a : b;
    ll cost = dp[l-2];
    for (ll i=l-3;i>=0;i--) {
        string t = str.substr(i, 1);
        if (t != last) {
            dp[i] = (t == "A") ? a : b;
            dp[i] += cost;
        } else {
            dp[i] += cost;
        }
        last = t;
        cost = dp[i];
    }
    for (ll i=0;i<str.length();i++) {
        if (dp[i] <= p)
            return i+1;
    }
}
 
int main() {
    int n; string str;
    cin >> n;
    for (int i=0;i<n;i++) {
        cout << solve() << "\n";
    }
}
