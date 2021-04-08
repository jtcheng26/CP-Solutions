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

struct guess {
  int a, b, g;
};

guess arr[101];

int solve() {
  int max_ans = 0;
  for (int g=1;g<=3;g++) {
    int peb = g;
    int correct = 0;
    for (int i=0;i<n;i++) {
      if (arr[i].a == peb) peb = arr[i].b;
      else if (arr[i].b == peb) peb = arr[i].a;
      if (peb == arr[i].g) correct++;
    }
    //cout << correct << endl;
    if (correct > max_ans) {
      max_ans = correct;
    }
  }
  return max_ans;
}

int main() {
  ofstream cout ("shell.out");
  ifstream cin ("shell.in");
  cin >> n;
  for (int i=0;i<n;i++) {
    guess g;
    cin >> g.a >> g.b >> g.g;
    arr[i] = g;
  }
  cout << solve() << endl;
  return 0;
}
