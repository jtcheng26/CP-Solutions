#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

#define mp make_pair
#define pb push_back
#define F first
#define S second

typedef long long ll;

using namespace std;

int n;
int a[101];

int solve() {
  int res = 0;
  for (int i=0;i<n;i++) {
    int exists[1001] = {0};
    int sum = a[i];
    exists[a[i]] = 1;
    for (int j=i+1;j<n;j++) {
      exists[a[j]]++;
      sum += a[j];
      if (sum % (j - i + 1) == 0) {
        if (exists[sum / (j - i + 1)])
          res++;
      }
    }
  }
  return res + n;
}

int main() {
  cin >> n;
  for (int i=0;i<n;i++) {
    cin >> a[i];
  }
  cout << solve() << endl;
  return 0;
}
