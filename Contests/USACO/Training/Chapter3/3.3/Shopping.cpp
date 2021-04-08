/*
   LANG: C++11
   PROG: shopping
*/

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

int s;
int origCost[6];
int toBuy[6];

int b;
map<int, int> idx;
vector<pair<int, int> > offers[101];
int offerPrice[101];

int solve() {
  int dp[6][6][6][6][6]; // cost to buy a combination of the five items
  for (int ia=0;ia<=5;ia++) {
    for (int ib=0;ib<=5;ib++) {
      for (int ic=0;ic<=5;ic++) {
        for (int id=0;id<=5;id++) {
          for (int ie=0;ie<=5;ie++) {
            dp[ia][ib][ic][id][ie] = ia * origCost[1] + ib * origCost[2] + ic * origCost[3]
              + id * origCost[4] + ie * origCost[5];
            //cout << ia << " " << ib << " " << ic << " " << id << " " << ie << " " << dp[ia][ib][ic][id][ie] << endl;
          }
        }
      }
    }
  }

  for (int i=0;i<s;i++) {
    int offerCost = offerPrice[i];
    int offerCnt[6] = {0};
    for (int j=0;j<offers[i].size();j++) {
      offerCnt[offers[i][j].F] = offers[i][j].S;
    }
    for (int ia=0;ia<=5;ia++) {
      if (ia < offerCnt[1]) continue;
      for (int ib=0;ib<=5;ib++) {
        if (ib < offerCnt[2]) continue;
        for (int ic=0;ic<=5;ic++) {
          if (ic < offerCnt[3]) continue;
          for (int id=0;id<=5;id++) {
            if (id < offerCnt[4]) continue;
            for (int ie=0;ie<=5;ie++) {
              if (ie < offerCnt[5]) continue;
              dp[ia][ib][ic][id][ie] = min(dp[ia][ib][ic][id][ie],
                dp[ia-offerCnt[1]][ib-offerCnt[2]][ic-offerCnt[3]][id-offerCnt[4]][ie-offerCnt[5]]
                + offerCost
              );
              //cout << offerCost << endl;
            }
          }
        }
      }
    }
  }

  //cout << origCost[1] << " " << origCost[2 ]<< endl;
  //cout << toBuy[1] << " " << toBuy[2] << " " << toBuy[3] << " " << toBuy[4] << " " << toBuy[5] << endl;
  return dp[toBuy[1]][toBuy[2]][toBuy[3]][toBuy[4]][toBuy[5]];
}

int main() {
  ofstream cout ("shopping.out");
  ifstream cin ("shopping.in");
  cin >> s;
  int n, c, k, p;
  int ind = 1;
  for (int i=0;i<s;i++) {
    cin >> n;
    for (int j=0;j<n;j++) {
      cin >> c >> k;
      if (idx[c] == 0) idx[c] = ind++;
      offers[i].pb(mp(idx[c], k));
    }
    cin >> p;
    offerPrice[i] = p;
  }
  cin >> b;
  for (int i=0;i<b;i++) {
    cin >> c >> k >> p;
    if (idx[c] == 0) idx[c] = ind++;
    origCost[idx[c]] = p;
    toBuy[idx[c]] = k;
  }
  cout << solve() << endl;
  return 0;
}
