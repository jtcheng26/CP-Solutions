#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

ll t, n;
int nums[4];

bool solve() {
  if (n > 30) {
    nums[0] = 6; nums[1] = 10; nums[2] = 14; nums[3] = n - (nums[0] + nums[1] + nums[2]);
    if (n - 30 == 6) {
      nums[2] = 15; nums[3] = 5;
    } else if (n - 30 == 10) {
      nums[0] = 15; nums[3] = 1;
    }
    else if (n - 30 == 14) {
      nums[0] = 15; nums[3] = 5;
    }
    return true;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> t;
  for (int i=0;i<t;i++) {
    cin >> n;
    bool res = solve();
    string r = res ? "YES" : "NO";
    cout << r << "\n";
    if (res) {
      for (int i=0;i<3;i++) {
        cout << nums[i] << " ";
      }
      cout << nums[3] << endl;
    }
  }
  return 0;
}
