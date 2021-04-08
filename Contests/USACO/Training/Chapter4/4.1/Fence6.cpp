/*
   LANG: C++11
   PROG: fence6
*/

/*
  It was a little tricky turning a list of adjacent edges into nodes
  for this one, so my main function could've been less messy.
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

int n;
vector<int> edge[101][2];
int node[101][2];
int adj[202][202];
int visited[202][2] = {false};
const int INFI = 1000000;

int floyd(int start, int end) {
  int dist[n][n];
  for (int i=1;i<n;i++)
  for (int j=1;j<n;j++)
    dist[i][j] = adj[i][j];
  for (int k=1;k<n;k++)
  for (int i=1;i<n;i++)
  for (int j=1;j<n;j++)
    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
  return dist[start][end];
}

int solve() {
/*
  for (int i=1;i<n;i++) {
    for (int j=1;j<n;j++) {
      cout << adj[i][j] << " ";
    }
    cout << endl;
  }
*/
  int ans = INFI;
  for (int i=1;i<n;i++)
  for (int j=1;j<n;j++) {
    if (i == j) adj[i][j] = 0;
    else if (adj[i][j] == 0) adj[i][j] = INFI;
  }
  for (int i=1;i<n;i++) {
    for (int j=i+1;j<n;j++) {
      if (adj[i][j] == INFI) continue;
      int len = adj[i][j];
      adj[i][j] = INFI;
      adj[j][i] = INFI;
      ans = min(ans, floyd(i, j) + len);
    }
  }
  return ans;
}

int findNode(int parent, int child) {
  int i;
  for (i=0;i<edge[parent][0].size();i++)
    if (edge[parent][0][i] == child) break;
  if (i != edge[parent][0].size()) return 0;
  for (i=0;i<edge[parent][1].size();i++)
    if (edge[parent][1][i] == child) break;
  if (i != edge[parent][1].size()) return 1;
  return 2;
}

int main() {
  ofstream cout ("fence6.out");
  ifstream cin ("fence6.in");
  cin >> n;
  int curr = 1;
  int node1 = 1; int node2 = 2;
  for (int i=0;i<n;i++) {
    int s, l, n1, n2;
    cin >> s >> l >> n1 >> n2;
    int s2[101];
    int j;
    int flag = 2;
    for (j=0;j<n1;j++) {
      cin >> s2[j];
      for (int k=0;k<2;k++) {
        if (flag == 2 && visited[s2[j]][k]) {
          int side = findNode(s2[j], s);
          if (side == 2) continue;
          node1 = node[s2[j]][side];
          //cout << "node with " << s2[j] << " on side " << side << endl;
          flag = k;
        }
      }
    }
    if (flag == 2) {
      node1 = curr++;
      for (int k=0;k<n1;k++) edge[s][0].pb(s2[k]);
      visited[s][0] = true;
      //cout << s << " node1: " << node1 << endl;
    }
    flag = 2;
    node[s][0] = node1;
    for (j=0;j<n2;j++) {
      cin >> s2[j];
      for (int k=0;k<2;k++) {
        if (flag == 2 && visited[s2[j]][k]) {
          int side = findNode(s2[j], s);
          if (side == 2) continue;
          node2 = node[s2[j]][side];
          flag = k;
        }
      }
    }
    if (flag == 2) {
      node2 = curr++;
      for (int k=0;k<n2;k++) edge[s][1].pb(s2[k]);
      visited[s][1] = true;
      //cout << s << " node2: " << node2 << endl;
    }
    //cout << " nodes " << node1 << " " << node2 << " length " << l << endl;
    node[s][1] = node2;
    adj[node1][node2] = l;
    adj[node2][node1] = l;
  }
  n = curr;
  cout << solve() << endl;
  return 0;
}
/*
10
1 1 2 2
2 7
6 10
2 2 2 2
1 7
3 8
3 3 2 1
2 8
4
4 4 1 3
3
9 5 10
5 5 3 1
4 9 10
6
6 6 1 2
5
1 10
7 7 2 2
1 2
8 9
8 8 2 2
2 3
7 9
9 9 2 3
7 8
4 5 10
10 10 3 2
4 5 9
1 6
*/
