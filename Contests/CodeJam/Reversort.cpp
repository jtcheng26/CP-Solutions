#include <iostream>

using namespace std;

int n;
int a[101];

int solve() {
    int res = 0;
    for (int i=0;i<n-1;i++) {
        int m = i;
        for (int j=i+1;j<n;j++) {
            if (a[j] < a[m]) {
                m = j;
            }
        }
        for (int k=0;k<(m-i+1)/2;k++) {
            int temp = a[k+i];
            a[k+i] = a[m-k];
            a[m-k] = temp;
        }
        res += m - i + 1;
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    for (int c=1;c<=t;c++) {
        cin >> n;
        for (int i=0;i<n;i++) {
            cin >> a[i];
        }
        cout << "Case #" << c << ": " << solve() << "\n";
    }
}
