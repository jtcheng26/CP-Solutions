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
int arr[7];
int a, b, c;

int solve() {
  sort(arr, arr+7);
  for (int i=0;i<6;i++) {
    for (int j=i+1;j<6;j++) {
      for (int k=j+1;k<6;k++) {
        if (arr[i] + arr[j] + arr[k] == arr[6]) {
          int nums[3];
          nums[0] = arr[i];
          nums[1] = arr[j];
          nums[2] = arr[k];
          sort(nums, nums+3);
          a = nums[0];
          b = nums[1];
          c = nums[2];
          return 0;
        }
      }
    }
  }
  return 0;
}

int main() {
  for (int i=0;i<7;i++) {
    cin >> arr[i];
  }
  solve();
  cout << a << " " << b << " " << c << "\n";
  return 0;
}
