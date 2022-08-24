#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

int n;
int arr[100001];

int solve() {
  int res = 0;
  for (int i=0;i<n;i++) {
    int prev = arr[i];
    i++;
    for (int j=0;j<3;j++) {
      if (i >= n || arr[i] <= prev) {
        res++;
        continue;
      }
      if (arr[i] - prev > 10) {
        res++;
        prev += 10;
        continue;
      }
      prev = arr[i];
      i++;
    }
    i--;
  }
  //cout << cnt << endl;
  //res += 4 - (n + res) % 4;
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  ifstream cin ("coding_contest_creation_input.txt");
  ofstream cout ("2016R1A.txt");
  int t;
  cin >> t;//
  for (int i=1;i<=t;i++) {
    cin >> n;
    for (int j=0;j<n;j++) {
      cin >> arr[j];
    }
    cout << "Case #" << i << ": " << solve() << endl;//
  }
  return 0;
}
