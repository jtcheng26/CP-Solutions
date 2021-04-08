// Example program
//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int n, k;
vector<int> a;

int solve() {
    int ans = 0;
    for (int i=0;i<n;i++) {
        int temp = 0;
        for (int j=0;j<n;j++) {
          if (a[j] >= a[i] && a[j] - a[i] <= k) {
              temp++;
          }
        }
        ans = max(ans, temp);
    }
    return ans;
}

int main()
{
    ifstream cin ("diamond.in");
    ofstream cout ("diamond.out");
    cin >> n >> k;
    a.resize(n);
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    cout << solve() << "\n";
    return 0;
}
