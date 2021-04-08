#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 1e18+7
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long ll;

using namespace std;

struct node {
  bool isGood = false;
  bool isBad = false;
  vector<node*> neighbors;
  bool deleted = false;
  bool visited = false;
  void add_neighbor(node* n) {
    neighbors.pb(n);
  }
};

int n, m, goal;
node nodes[2505];
int good;
int bad;

void setNeighbors() {
  for (int i=0;i<n;i++) {
    for (int j=0;j<m;j++) {
      if (i > 0) {
        nodes[i*m+j].add_neighbor(&nodes[(i-1)*m+j]);
        nodes[(i-1)*m+j].add_neighbor(&nodes[i*m+j]);
      }
      if (j > 0) {
        nodes[i*m+j].add_neighbor(&nodes[i*m+j-1]);
        nodes[i*m+j-1].add_neighbor(&nodes[i*m+j]);
      }
    }
  }
}

pair<int, int> validDelete() {
  queue<node*> q;
  pair<int, int> cnt = mp(0, 0); // good, bad
  for (int i=0;i<goal;i++) {
    nodes[i].visited = false;
  }
  q.push(&nodes[goal]);
  nodes[goal].visited = true;
  if (nodes[goal].deleted) return cnt;
  while (q.size() > 0) {
    node *root = q.front();
    q.pop();
    if (root->isBad)
      cnt.S++;
    else if (root->isGood)
      cnt.F++;
    for (auto neighbor : root->neighbors) {
      if (!neighbor->visited && !neighbor->deleted) {
        q.push(neighbor);
        neighbor->visited = true;
      }
    }
  }
  return cnt;
}

void printNode(node n) {
  cout << "bad: " << (n.isBad ? "Yes" : "No") << "\n";
  cout << "good: " << (n.isGood ? "Yes" : "No") << "\n";
  cout << "del: " << (n.deleted ? "Yes" : "No") << "\n";
}

bool solve() {
  int b = bad;
  goal = n*m-1;
  setNeighbors();
  bool foundGood = false;
  nodes[goal+1].isGood = nodes[goal+1].isBad = nodes[goal+1].deleted = false;
  for (int i=0;i<=goal+1;i++) {
    //printNode(nodes[i]);
    if (!nodes[i].isBad) continue;
    for (auto neighbor : nodes[i].neighbors) {
      neighbor->deleted = true;
    }
  }
  pair<int, int> cnt = validDelete();
  //cout << cnt.F <<" " << cnt.S << "\n";
  if (cnt.F != good) {
    return false;
  } else {
    b = min(b, cnt.S);
    return b == 0;
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    good = 0;
    bad = 0;
    cin >> n >> m;
    for (int i=0;i<n;i++) {
      for (int j=0;j<m;j++) {
        nodes[i*m+j].isGood = nodes[i*m+j].isBad = nodes[i*m+j].deleted = false;
        nodes[i*m+j].neighbors.clear();
        char type;
        cin >> type;
        if (type == '#') {
          nodes[i*m+j].deleted = true;
        } else if (type == 'G') {
          nodes[i*m+j].isGood = true;
          good++;
        } else if (type == 'B') {
          nodes[i*m+j].isBad = true;
          bad++;
        }
      }
    }
    cout << (solve() ? "Yes" : "No") << "\n";
  }
  return 0;
}
