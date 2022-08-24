#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>

#define INF 1000000001
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

struct Node {
  Node* child;
  ll data;
};

int n;
int a[100001];

/* make sure l.size() is even */
ll ans(Node* head, int k) {
  int orig = k;
  Node* h = new Node();
  h->data = head->data;
  h->child = head->child;
  Node* prev;
  int del = 0;
  int c = 1;
  while (true) {
    prev = h;
    int cnt = 0;
    for (int i=0;i<k;i+=2) {
      cnt++;
      if (prev->child != nullptr) {
        //cout << i << " " << (prev->data) << "\n";
        prev->data = prev->data - prev->child->data;
        //cout << (prev->data) << "\n";
        
        if (prev->child->child != nullptr) {
          Node* temp = prev->child->child;
          if (k != orig) {
            del++;
            delete prev->child;
          }
          c++;
          prev->child = new Node();
          prev->child->data = temp->data;
          prev->child->child = temp->child;
          prev = prev->child;
        }
      }
    }
   // cout << c - del - orig / 2 << "\n";
    if (cnt <= 1) {
      ll ret = h->data;
      if (h->child != nullptr) {
        del++;
        delete h->child;
      }
      del++;
      delete h;
      return ret;
    }
    k = cnt;
  }
}

void printList(Node* n){
    while (n != NULL) {
        cout << n->data << " ";
        n = n->child;
    }
}
/*
void popList(Node* k, int i) {
    if (i < n) {
      Node* nxt = new Node();
      k->child = nxt;
      nxt->data = a[i];
      popList(nxt, i+1);
    }
}*/

ll solve() {
  Node* head = new Node();
  Node* tail = head;
  head->data = a[0];
  //popList(&head, 1);
  for (int i=1;i<n;i++) {
    tail->child = new Node();
    tail->child->data = a[i];
    tail = tail->child;
  }
  //printList(&head);
  //cout << "\n";
  //cout << (prev->data) << "\n";
  //return 0;
  ll res = ans(head, n);
  for (int i=1;i<n;i++) {
    tail->child = head;
    head = head->child;
    tail->child->child = NULL;
    tail = tail->child;
    res = max(res, ans(head, n));
    //cout << i << "\n";
    //printList(head);
    //cout << "\n";
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  //ifstream cin ("rabbit_subtraction_4.txt");
  cin >> n;
  for (int i=0;i<n;i++) {
    cin >> a[i];
  }
  cout << solve() << "\n";
  return 0;
}