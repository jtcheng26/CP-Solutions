#include <iostream>
#include <string>
#include <vector>
#include <cmath>

typedef long long ll;

using namespace std;

int main() {
    int n, k;
    cin >> n; cin >> k;
    if (k == 0 || n == 1) {
        cout << n << "\n";
        for (int i=0;i<n;i++)
            cout << i+1 << " ";
        return 0;
    }
    if (2 * k + 1 >= n) {
        cout << 1 << "\n";
        cout << n / 2 + 1;
        return 0;
    }
    vector<int> ans; int size = 1001;
    for (int be=1;be<=k+1;be++) {
        vector<int> nums;
        for (int i=be;i<=n;i+=(2*k+1)) {
            nums.push_back(i);
        }
        if (n - nums[nums.size()-1] <= k && nums.size() < size) {
            ans.clear();
            size = nums.size();
            for (int j=0;j<size;j++)
                ans.push_back(nums[j]);
        }
    }
    cout << size << "\n";
    for (int i=0;i<size;i++) {
        cout << ans[i] << " ";
    }
}
