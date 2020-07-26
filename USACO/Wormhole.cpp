/*
   LANG: C++14
   PROG: wormhole
*/
/*
total pairings t, infinite loop points p, holes h
arrange into vector of rows x columns for each wormhole
for each row where colmumns > 2:
  go towards each hole and append h and follow loop until exited or return to initial
  if at initial, add factorial (n - h) / p
  p += h
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

typedef long long ll;

struct hole {
  ll x, y;
  int next_in_row;
  int next;
  bool last_in_row;
};

using namespace std;

ll n;
vector<hole> h;

bool cmp_holes(hole a, hole b) {
  return (a.x == b.x && a.y == b.y);
}

bool cmph(hole a, hole b) {
  return a.x < b.x;
}

//  if a configuration results in a loop, regardless of how many loops possible.
bool isLoop() {
  for (int i=0; i<n; i++) {
    int pos = i;
    for (int j=0; j<n; j++) {
      if (!h[h[pos].next].last_in_row)
        pos = h[h[pos].next].next_in_row;
      else {
        pos = -1;
        break;
      }
    }
    if (pos != -1) return true;
  }
  return false;
  /*
  return false;
  for (int i=0;i<rows.size();i++) {  // for each row
    if (rows[i].size() > 1) {
      for (int j=0;j<rows[i].size()-1;j++) {   // for each item start cow
        bool walk = false;
        hole orig = rows[i][j]; hole curr = h[orig.next_in_row]; // orig = hole before cow (cow must be after a hole for a loop)
         cout << "orig" << orig.x << " " << orig.y << " next " << orig.next << endl;
        do {
           cout << curr.x << " " << curr.y << " next " << curr.next << endl;
          if (!curr.last_in_row && walk) {
            curr = h[curr.next_in_row];
          } else if (!walk)
            curr = h[curr.next];
          walk = !walk;
          if (cmp_holes(orig, curr)) {
             cout << "T" <<endl;
            return true;
          } else if (walk && curr.last_in_row) {
            break;
          }
        } while (true);  // stop if at orig or end row
      }
    }
  }
  return false;
  */
}

ll make_pairs() {
  ll res=0; int i;
  for (i=0;i<n;i++) {
    if (h[i].next == -1) break;
  }

  if (i == n) {
    if (isLoop()) {
      return 1;
    } else {
      return 0;
    }
  }
  for (int j=i+1;j<n;j++) {
    if (h[j].next == -1) {
      h[i].next = j;
      h[j].next = i;
      //cout << "pair " << i << " " << j << endl;
      /*
      for (int a=0;a<rows.size();a++) {
        for (int b=0;b<rows[a].size();b++) {
          if (cmp_holes(rows[a][b], h[i])) {
            rows[a][b].next = h[i].next;
            rows[a][b].next_in_row = h[i].next_in_row;
          }
          else if (cmp_holes(rows[a][b], h[j])) {
            rows[a][b].next = h[j].next;
            rows[a][b].next_in_row = h[j].next_in_row;
          }
        }
      }
      */
      res += make_pairs();
      h[i].next = h[j].next = -1;
    }
  }
  return res;
}

ll solve() {
  map<ll, vector<hole> > rows;
  for (int i=0;i<h.size();i++) {
    if (rows.find(h[i].y)!=rows.end()) {
      continue;
    }
    vector<hole> row;
    row.push_back(h[i]);
    for (int j=i+1;j<h.size();j++) {
      if (h[i].y == h[j].y)
        row.push_back(h[j]);
    }
    sort(row.begin(), row.end(), cmph);
    for (int k=0;k<row.size()-1;k++) {
      row[k].next_in_row = k+1;
      row[k].last_in_row = false;
      row[k].next = -1;
    }
    row[row.size()-1].next = -1;
    row[row.size()-1].next_in_row = -1;
    row[row.size()-1].last_in_row = true;
    for (int c=0;c<row.size();c++) {
      int j;
      for (j=0;j<n;j++)
        if (cmp_holes(row[c], h[j])) break;
      int next_row = row[c].next_in_row;
      if (next_row != -1) {
        for (int z=0;z<n;z++) {
          if (cmp_holes(row[next_row], h[z])) {
            h[j].next_in_row = z;
            row[c].next_in_row = z;
            break;
          }
        }
      } else {
        h[j].next_in_row = -1;
      }
      h[j].last_in_row = row[c].last_in_row;
      h[j].next = row[c].next;
    }
    rows[h[i].y] = row;
  }
  /*
  vector<vector<hole> > rowsvec;
  map<ll, vector<hole> >::iterator j;
  for (j=rows.begin();j!=rows.end();j++) {
    vector<hole> row;
    for (int k=0;k<j->second.size();k++) {
      int i; hole ahole = j->second[k];
      for (i=0;i<n;i++)
        if (cmp_holes(ahole, h[i])) break;
      int next_row = ahole.next_in_row;
      if (next_row != -1) {
        for (int z=0;z<n;z++) {
          if (cmp_holes(j->second[next_row], h[z])) {
            h[i].next_in_row = z;
            ahole.next_in_row = z;
            break;
          }
        }
      } else {
        h[i].next_in_row = -1;
      }
      h[i].last_in_row = ahole.last_in_row;
      h[i].next = ahole.next;
      row.push_back(ahole);
    }
    rowsvec.push_back(row);
  }
  */
  return make_pairs();
}

int main() {
  ofstream fout ("wormhole.out");
  ifstream fin ("wormhole.in");
  fin >> n;
  for (int i=0;i<n;i++) {
    ll x, y; hole p;
    fin >> x >> y;
    p.x = x; p.y = y;
    h.push_back(p);
  }
  fout << solve() << endl;
  return 0;
}
