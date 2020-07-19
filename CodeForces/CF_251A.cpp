#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
 
typedef long long ll;
 
using namespace std;
 
vector<ll> pts;
 
ll binSearch(ll i, ll d) {
    ll l = i+1; ll r = pts.size()-1;
    int b;
    while (l < r) {
        b = (r + l) / 2;
        if (pts[b] - pts[i] < d)
            l = b+1;
        else if (pts[b] - pts[i] > d)
            r = b;
        else {
            l = b;
            break;
        }
    }
    while (pts[l] - pts[i] > d)
        l -= 1;
    return l - i;
}
 
ll solve(ll d) {
    ll n = pts.size();
    if (n < 3)
        return 0;
    ll count=0;
    for (ll i=0;i<n-2;i++) {
        ll nbtw = binSearch(i, d) - 1;
        if (nbtw < 1)
            continue;
        count += (((1 + nbtw) * nbtw) / 2);
    }
    return count;
}
 
int main()
{
   ll n, d, x;
   cin >> n; cin >> d;
   for (ll i=0;i<n;i++) {
       cin >> x;
       pts.push_back(x);
   }
   cout << solve(d);
}
