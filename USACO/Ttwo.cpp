/*
   LANG: C++14
   PROG: ttwo
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

struct farmer {
  int r; int c; int d; // NWSE -> 0123
};

ll n;
string arr[10];
int board[101][101];
pair<int, int> cow_start;
pair<int, int> john_start;
farmer john;
farmer cow;

void setBoard() {
  for (int i=0;i<10;i++) {
    for (int j=0;j<10;j++) {
      if (arr[i][j] == '.') board[i][j] = 0;
      else if (arr[i][j] == '*') board[i][j] = 1;
      else if (arr[i][j] == 'C') {
        board[i][j] = 2;
        cow.r = i; cow.c = j; cow.d = 0;
        pair<int, int> p(i, j);
        cow_start = p;
      }
      else {
        board[i][j] = 3;
        john.r = i; john.c = j; john.d = 0;
        pair<int, int> p(i, j);
        john_start = p;
      }
    }
  }
}

void farmer_move() {
  if (john.d == 0) {
    if (john.r == 0 || board[john.r-1][john.c] == 1) john.d = 1;
    else {
      john.r--;
    }
  } else if (john.d == 1) {
    if (john.c == 9 || board[john.r][john.c+1] == 1) john.d = 2;
    else {
      john.c++;
    }
  } else if (john.d == 2) {
    if (john.r == 9 || board[john.r+1][john.c] == 1) john.d = 3;
    else {
      john.r++;
    }
  } else {
    if (john.c == 0 || board[john.r][john.c-1] == 1) john.d = 0;
    else {
      john.c--;
    }
  }
}

void cow_move() {
  if (cow.d == 0) {
    if (cow.r == 0 || board[cow.r-1][cow.c] == 1) cow.d = 1;
    else {
      cow.r--;
    }
  } else if (cow.d == 1) {
    if (cow.c == 9 || board[cow.r][cow.c+1] == 1) cow.d = 2;
    else {
      cow.c++;
    }
  } else if (cow.d == 2) {
    if (cow.r == 9 || board[cow.r+1][cow.c] == 1) cow.d = 3;
    else {
      cow.r++;
    }
  } else {
    if (cow.c == 0 || board[cow.r][cow.c-1] == 1) cow.d = 0;
    else {
      cow.c--;
    }
  }
}

int solve() {
  int res = 0;
  setBoard();
  while (!(john.r == cow.r && john.c == cow.c) && res < 160001) {
    farmer_move();
    cow_move();
    //cout << john.r << " " << john.c << endl;
    //cout << cow.r << " " << cow.c << endl;
    //cout << res << endl;
    res++;
  }
  if (john.r == cow.r && john.c == cow.c) return res;
  else return 0;
}

int main() {
  ofstream fout ("ttwo.out");
  ifstream fin ("ttwo.in");
  for (int i=0;i<10;i++) {
    fin >> arr[i];
  }
  fout << solve() << endl;
  return 0;
}
