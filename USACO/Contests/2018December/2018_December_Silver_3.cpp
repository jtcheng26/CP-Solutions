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

int n, k;
int board[101][11];
int component[1001];
int compsz[1001] = {0};
vector<int> adj[1001];

void dfs(int comp, int node) {
  component[node] = comp;
  compsz[comp]++;
  for (int i=0;i<adj[node].size();i++) {
    int child = adj[node][i];
    if (component[child] != comp) // add an && clause here depending on problem
      dfs(comp, child);
  }
}

void ff() {
  int comp = 1;
  for (int i=0;i<10*n;i++) {
    compsz[i] = 0; component[i] = -1;
  }
  for (int i=0;i<10*n;i++) {
    if (component[i] == -1)
      dfs(comp++, i);
  }
}

void setEdges() {
  for (int i=0;i<10*n;i++) adj[i].clear();
  for (int i=0;i<n;i++) {
    for (int j=0;j<10;j++) {
      if (i > 0 && board[i-1][j] == board[i][j] && board[i][j] != 0) {
        adj[10*i+j].pb(10*(i-1)+j);
        adj[10*(i-1)+j].pb(10*i+j);
      }
      if (j > 0 && board[i][j-1] == board[i][j] && board[i][j] != 0) {
        adj[10*i+j].pb(10*i+j-1);
        adj[10*i+j-1].pb(10*i+j);
      }
    }
  }
}

void updateGraph() {
  for (int j=0;j<10;j++) {
    int base = n-1;
    for (int i=n-1;i>=0;i--) {
      if (board[i][j] != 0 && i != base) {
        board[base][j] = board[i][j];
        board[i][j] = 0;
        base--;
      } else if (board[i][j] != 0) base--;
    }
  }
}

int solve() {
  int cnt = 1;
  while (cnt > 0) {
    cnt = 0;
    setEdges();
    ff();
    for (int i=0;i<10*n;i++) {
      //cout << compsz[component[i]] << endl;
      if (compsz[component[i]] >= k) {
        cnt++;
        board[i / 10][i % 10] = 0;
      }
    }
    if (cnt > 0) updateGraph();
  }
  return 0;
}

int main() {
  ofstream cout ("mooyomooyo.out");
  ifstream cin ("mooyomooyo.in");
  cin >> n >> k;
  for (int i=0;i<n;i++) {
    for (int j=0;j<10;j++) {
      char a;
      cin >> a;
      board[i][j] = a - '0';
    }
  }
  solve();
  for (int i=0;i<n;i++) {
    for (int j=0;j<10;j++) {
      cout << board[i][j] << (j == 9 ? "\n" : "");
    }
  }
  return 0;
}
