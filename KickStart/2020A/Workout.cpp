#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

ll n;

bool check(vector<int> differences, int d_opt, int k) {
  int req_k = 0;
  for (int i=0;i<differences.size();i++) {
    req_k += (ceil((double)differences[i] / (double)d_opt) - 1);
  }
  return req_k <= k;
}

int binSearch(vector<int> differences, int k) {
  int start = 1;
  int end = differences[differences.size()-1];
  while (start < end) {
    int d_opt = (start + end) / 2;
    bool possible = check(differences, d_opt, k);
    if (possible)
      end = d_opt;
    else
      start = d_opt + 1;
  }
  return start;
}

int solve(vector<int> minutes, int k) {
  vector<int> differences;
  for (int i=1;i<minutes.size();i++) {
    int diff = minutes[i] - minutes[i-1];
    differences.push_back(diff);
  }
  int last_i = differences.size() - 1;
  sort(differences.begin(), differences.end());
  if (k == 1) {
    int greatest = differences[last_i];
    differences[last_i] =  greatest / 2;
    differences.push_back(greatest - differences[last_i]);
    sort(differences.begin(), differences.end());
    return differences[last_i+1];
  }
  int result = binSearch(differences, k);
  return result;
}

int main() {
  int t, n, k;
  cin >> t;
  for (int c=1;c<=t;c++) {
    cin >> n >> k;
    vector<int> minutes;
    for (int i=0;i<n;i++) {
      int x;
      cin >> x;
      minutes.push_back(x);
    }
    int result = solve(minutes, k);
    cout << "Case #" << c << ": " << result << endl;
  }
}
