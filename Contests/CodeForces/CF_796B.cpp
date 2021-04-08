#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 1e18+7
#define pb push_back
#define F first
#define S second

typedef long long ll;

using namespace std;

int n, m, k;
bool holes[1000001];
int loc = 1;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> m >> k;
  for (int i=0;i<m;i++) {
    int a;
    cin >> a;
    holes[a] = true;
  }
  bool fall = false;
  if (holes[1]) fall = true;
  for (int i=0;i<k;i++) {
    int u, v;
    cin >> u >> v;
    if (!fall && u == loc) loc = v;
    else if (!fall && v == loc) loc = u;
    if (holes[loc]) fall = true;
  }
  cout << loc << endl;
  return 0;
}
