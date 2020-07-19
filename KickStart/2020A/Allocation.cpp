#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve() {
    int n; int b;
    cin >> n;
    cin >> b;
    vector<int> houses;
    for (int i=0;i<n;i++) {
        int cost;
        cin >> cost;
        houses.push_back(cost);
    }
    sort(houses.begin(), houses.end());
    int count = 0;
    for (int i=0;i<houses.size();i++) {
        if (houses[i] <= b) {
            count++;
            b -= houses[i];
        }
    }
    return count;
}

int main()
{
    int t; int n; int b;
    cin >> t;
    for (int i=1;i<=t;i++) {
        int result = solve();
        cout << "Case #"<<i<<": "<<result<<"\n";
    }
    return 0;
}
