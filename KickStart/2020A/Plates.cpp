#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int n; int k;
ll solve(int p) {
    int stacks[n][k];
    for (int i=0;i<n;i++) {
        for (int j=0;j<k;j++) {
            int x;
            cin >> x;
            stacks[i][j] = x;
        }
    }
    ll cumHeights[n+1][k+1];
    for (int i=0;i<=k;i++) {
      cumHeights[0][i] = 0;
    }
    for (int i=1;i<=n;i++) {
        ll cumHeight = 0;
        cumHeights[i][0] = 0;
        for (int j=1;j<=k;j++) {
            cumHeight += stacks[i-1][j-1];
            cumHeights[i][j] = cumHeight;
        }
    }
    ll dp[n+1][p+1];
    for (int k=0;k<=p;k++) {
      dp[0][k] = 0;
    }
    for (int i=1;i<=n;i++) {
      for (int k=0;k<=p;k++) {
        dp[i][k] = 0;
      }
      for (int j=0;j<=p;j++) {
        for (int m=0;m<=min(j, k);m++) {
          dp[i][j] = max(dp[i][j], cumHeights[i][m] + dp[i-1][j-m]);
        }
      }
    }
    return dp[n][p];
}

int main() {
    int t, p;
    cin >> t;
    for (int c=1;c<=t;c++) {
        cin >> n; cin >> k; cin >> p;
        ll result = solve(p);
        cout << "Case #"<<c<<": "<<result<<"\n";
    }
    return 0;
}
