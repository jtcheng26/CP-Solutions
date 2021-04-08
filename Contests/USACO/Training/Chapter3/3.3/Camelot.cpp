/*
   LANG: C++11
   PROG: camelot
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

#define INFI 10000007;
#define mp make_pair
#define pb push_back
#define F first
#define S second

typedef long long ll;

using namespace std;

int nrow, ncol;
vector<pair<int, int> > knights;
int kingRow, kingCol;

int cost[31][27]; // total cost of choosing square
int kingCost[31][27]; // extra cost of picking up king
int dist[31][27][2]; // current knight to square
int kingDist[31][27]; // king to square

// looks for neighbors of current square
int checkSquare(int row, int col, int hasKing) {
  int newDist = 0;
  int d = dist[row][col][hasKing];
  // leftmost and rightmost squares (up)
  if (row > 0) {
    if (col > 1) {
      if (d+1 < dist[row-1][col-2][hasKing]) {
        dist[row-1][col-2][hasKing] = d+1;
        newDist = 1;
      }
    }
    if (col < ncol-2) {
      if (d+1 < dist[row-1][col+2][hasKing]) {
        dist[row-1][col+2][hasKing] = d+1;
        newDist = 1;
      }
    }
  }
  // leftmost and rightmost squares (down)
  if (row < nrow-1) {
    if (col > 1) {
      if (d+1 < dist[row+1][col-2][hasKing]) {
        dist[row+1][col-2][hasKing] = d+1;
        newDist = 1;
      }
    }
    if (col < ncol-2) {
      if (d+1 < dist[row+1][col+2][hasKing]) {
        dist[row+1][col+2][hasKing] = d+1;
        newDist = 1;
      }
    }
  }
  // upmost and bottommost squares (left)
  if (col > 0) {
    if (row > 1) {
      if (d+1 < dist[row-2][col-1][hasKing]) {
        dist[row-2][col-1][hasKing] = d+1;
        newDist = 1;
      }
    }
    if (row < nrow-2) {
      if (d+1 < dist[row+2][col-1][hasKing]) {
        dist[row+2][col-1][hasKing] = d+1;
        newDist = 1;
      }
    }
  }
  // upmost and bottommost squares (right)
  if (col < ncol-1) {
    if (row > 1) {
      if (d+1 < dist[row-2][col+1][hasKing]) {
        dist[row-2][col+1][hasKing] = d+1;
        newDist = 1;
      }
    }
    if (row < nrow-2) {
      if (d+1 < dist[row+2][col+1][hasKing]) {
        dist[row+2][col+1][hasKing] = d+1;
        newDist = 1;
      }
    }
  }
  if (hasKing == 0 && kingDist[row][col] + d < dist[row][col][1]) {
    dist[row][col][1] = kingDist[row][col] + d;
    newDist = max(newDist, kingDist[row][col]); // so that we can compute distance w/ king later
  }
  return newDist;
}
int do_step(int x, int y, int kflag) {
    int f = 0; /* maximum distance added */
    int d = dist[x][y][kflag]; /* distance of current move */

  /* go through all possible moves that a knight can make */
    if (y > 0) {
        if (x > 1)
             if (dist[x-2][y-1][kflag] > d+1) {
                 dist[x-2][y-1][kflag] = d+1;
                 f = 1;
             }
            if (x < nrow-2) {
                if (dist[x+2][y-1][kflag] > d+1) {
	            dist[x+2][y-1][kflag] = d+1;
	            f = 1;
	        }
            }
            if (y > 1) {
                if (x > 0)
	            if (dist[x-1][y-2][kflag] > d+1) {
	                dist[x-1][y-2][kflag] = d+1;
	                f = 1;
	            }
	        if (x < nrow-1)
	            if (dist[x+1][y-2][kflag] > d+1) {
	                dist[x+1][y-2][kflag] = d+1;
	                f = 1;
	            }
            }
    }
    if (y < ncol-1) {
        if (x > 1)
            if (dist[x-2][y+1][kflag] > d+1) {
                dist[x-2][y+1][kflag] = d+1;
                f = 1;
            }
            if (x < nrow-2) {
                if (dist[x+2][y+1][kflag] > d+1) {
                    dist[x+2][y+1][kflag] = d+1;
                    f = 1;
                }
            }
        if (y < ncol-2) {
            if (x > 0)
                if (dist[x-1][y+2][kflag] > d+1) {
                    dist[x-1][y+2][kflag] = d+1;
                    f = 1;
                }
            if (x < nrow-1)
                if (dist[x+1][y+2][kflag] > d+1) {
                    dist[x+1][y+2][kflag] = d+1;
                    f = 1;
                }
        }
    }

/* also check the 'pick up king here' move */
    if (kflag == 0 && dist[x][y][1] > d + kingDist[x][y]) {
        dist[x][y][1] = d + kingDist[x][y];
        if (kingDist[x][y] > f) f = kingDist[x][y];
    }
    return f; /* 1 if simple knight move made, 0 if no new move found */
}

void calcDists(int row, int col) {
  for (int r=0;r<nrow;r++) {
    for (int c=0;c<ncol;c++) {
      dist[r][c][0] = dist[r][c][1] = INFI;
    }
  }
  dist[row][col][0] = 0;
  int maxDist = dist[row][col][1] = kingDist[row][col];
  //maxDist = max(maxDist, 1);
  for (int d=0;d<=maxDist;d++) {
    //cout << d << endl;
    for (int r=0;r<nrow;r++) {
      for (int c=0;c<ncol;c++) {
        if (dist[r][c][0] == d) {
          int hasNeighbors = do_step(r, c, 0);
          maxDist = max(maxDist, d + hasNeighbors);
        }
        // check dist for if knight has king
        if (dist[r][c][1] == d) {
          int hasNeighbors = do_step(r, c, 1);
          maxDist = max(maxDist, d + hasNeighbors);
        }
      }
    }
  }
}

int solve() {
  int res = INFI;
  for (int r=0;r<nrow;r++) {
    for (int c=0;c<ncol;c++) {
      int a = abs(kingRow - r);
      int b = abs(kingCol - c);
      if (a < b) a = b; // since king can go diagonal, dist is max(rowDiff, colDiff)
      kingCost[r][c] = kingDist[r][c] = a;
      cost[r][c] = 0;
    }
  }
  for (int i=0;i<knights.size();i++) {
    //cout << knights[i].S << " " << knights[i].F << endl;
    calcDists(knights[i].F, knights[i].S);
    for (int r=0;r<nrow;r++) {
      for (int c=0;c<ncol;c++) {
        cost[r][c] += dist[r][c][0];
        kingCost[r][c] = min(kingCost[r][c], dist[r][c][1] - dist[r][c][0]);
      }
    }
  }
  for (int r=0;r<nrow;r++) {
    for (int c=0;c<ncol;c++) {
      //cout << cost[r][c] << " " << kingCost[r][c] << endl;
      res = min(res, cost[r][c] + kingCost[r][c]);
    }
  }
  return res;
}

int main() {
  ofstream cout ("camelot.out");
  ifstream cin ("camelot.in");
  string line;
  cin >> nrow >> ncol;
  char a;
  int b;
  cin >> a >> b;
  kingCol = a - 'A';
  kingRow = b - 1; // zero-indexed everything
  getline(cin, line);
  getline(cin, line);
  while (!line.empty()) {
    for (int i=0;i<line.length();i+=4) {
      int col = line[i] - 'A';
      int row = line[i+2] - '0';
      if (i < line.length() - 3) {
        if (line[i+3] != ' ') {
          row *= 10;
          row += line[i+3] - '0';
          i++;
        }
      }
      knights.pb(mp(row - 1, col));
    }
    getline(cin, line);
  }
  cout << solve() << endl;
  return 0;
}
