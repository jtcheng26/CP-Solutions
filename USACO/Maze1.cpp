/*
   LANG: C++14
   PROG: maze1
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

#define INF 1000000007

typedef long long ll;

using namespace std;

int w, h;
vector<int> maze[3801]; // (rowNum * rowLen) + col
vector<int> exits;

void set_maze(string m[202]) {
  for (int i=0;i<2*h+1;i++) { // row: i / 2
    if (m[i][0] == '+') {
      for (int j=1;j<2*w+1;j++) { // col: j / 2
        if (m[i][j] == ' ') {
          if (i == 0) exits.push_back((i / 2) * w + j / 2);
          else if (i == 2 * h) exits.push_back((i / 2 - 1) * w + j / 2);
          else {
            maze[(i / 2) * w + j / 2].push_back(((i - 2) / 2) * w + j / 2);
            maze[((i - 2) / 2) * w + j / 2].push_back((i / 2) * w + j / 2);
          }
        }
      }
    }
    else {
      for (int j=0;j<2*w+1;j+=2) {
        if (m[i][j] == ' ') {
          if (j == 2 * w) exits.push_back((i / 2) * w + w-1);
          else if (j == 0) exits.push_back((i / 2) * w);
          else {
            maze[(i / 2) * w + j / 2 - 1].push_back((i / 2) * w + j / 2);
            maze[(i / 2) * w + j / 2].push_back((i / 2) * w + j / 2 - 1);
          }
        }
      }
    }
  }
}

void print_conn() {
  for (int i=0;i<h;i++) {
    for (int j=0;j<w;j++) {
      cout << "Node " << i*w+j << endl;
      for (int k=0;k<maze[i*w+j].size();k++) {
        cout << maze[i*w+j][k] << endl;
      }
    }
  }
  cout << "Exits" << endl;
  for (int i=0;i<exits.size();i++)
    cout << exits[i] << endl;
}

int solve() {
  //print_conn();
  int dists[2][w*h];
  for (int d=0;d<2;d++) {
    int dist[w*h]; bool visited[w*h]; int visits = 0;
    for (int i=0;i<w*h;i++) {
      dist[i] = INF; visited[i] = false;
    }
    dist[exits[d]] = 0;
    while (visits < w * h) {
      int v = 0; int min_dist = INF;
      for (int i=0;i<w*h;i++) {
        if (!visited[i] && dist[i] < min_dist) {
          min_dist = dist[i];
          v = i;
        }
      }
      //cout << v << endl;
      visited[v] = true; visits++;
      for (int j=0;j<maze[v].size();j++) {
        if (maze[v][j] != v) {
          dist[maze[v][j]] = min(dist[maze[v][j]], dist[v] + 1);
        }
      }
    }
    for (int i=0;i<w*h;i++) {
      dists[d][i] = dist[i];
    }
  }
  int res = 0;
  for (int j=0;j<w*h;j++) {
    int d = min(dists[0][j], dists[1][j]) + 1;
    //cout << dists[0][j] << " " << dists[1][j] << endl;
    res = max(d, res);
  }
  //cout << max_d[0] << " " << max_d[1] << endl;
  return res;
}

int main() {
  ofstream cout ("maze1.out");
  ifstream cin ("maze1.in");
  cin >> w >> h;
  string m[202];
  getline(cin, m[0]);
  for (int i=0;i<2*h+1;i++) {
    getline(cin, m[i]);
    //cout << m[i] << endl;
  }
  set_maze(m);
  cout << solve() << endl;
  return 0;
}
