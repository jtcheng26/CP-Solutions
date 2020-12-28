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

pair<pair<int, int>, pair<int, int> > billboard[2];
pair<pair<int, int>, pair<int, int> > rectangle;
int cover[2002][2002];

int solve() {
  int res = 0;
  for (int i=0;i<=2000;i++) {
    for (int j=0;j<=2000;j++) {
      cover[i][j] = 0;
    }
  }
  for (int i=rectangle.F.F;i<rectangle.S.F;i++) {
    for (int j=rectangle.F.S;j<rectangle.S.S;j++) {
      cover[i+1000][j+1000] = 1;
    }
  }
  for (int b=0;b<2;b++) {
    for (int i=billboard[b].F.F;i<billboard[b].S.F;i++) {
      for (int j=billboard[b].F.S;j<billboard[b].S.S;j++) {
        if (cover[i+1000][j+1000] != 1) res++;
      }
    }
  }
  return res;
}

int main() {
  ofstream cout ("billboard.out");
  ifstream cin ("billboard.in");
  for (int i=0;i<2;i++)
    cin >> billboard[i].F.F >> billboard[i].F.S >> billboard[i].S.F >> billboard[i].S.S;
  cin >> rectangle.F.F >> rectangle.F.S >> rectangle.S.F >> rectangle.S.S;
  cout << solve() << endl;
  return 0;
}
