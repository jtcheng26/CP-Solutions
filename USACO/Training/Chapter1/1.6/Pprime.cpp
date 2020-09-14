/*
   LANG: C++14
   PROG: pprime
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

ll a, b, p;
int digitsLim;
int digits;

vector<ll> pals;

bool isPalindrome(ll num) {
  string temp = to_string(num);
  for (int i=0;i<temp.size()/2;i++) {
    if (!(temp[i] == temp[temp.size()-i-1]))
      return false;
  }
  return true;
}

bool isPrime(ll n) {
  if (n <= 3)
    return n > 1;
  else if (n % 2 == 0 || n % 3 == 0)
    return false;
  for (int i=5;i*i<=n;i+=6) {
    if (n % i == 0 || n % (i+2) == 0)
      return false;
  }
  return true;
}

// d: current digit
void make_palindromes(ll d) {
  if (d==-1) {
    for (int i=1;i<=digitsLim;i++) {
      digits = i;
      p = 0;
      make_palindromes(0);
    }
  } else if (d >= digits) {
    pals.push_back(p);
  }
  else {
    if (d == 0) {
      for (int i=1;i<10;i+=2) {
        p += (i * pow(10, digits - d - 1));
        make_palindromes(d+1);
        p -= (i * pow(10, digits - d - 1));
      }
    } else if (d >= ceil((double)digits / 2.0)) {
      p += ((int)(p / (pow(10, d))) % 10) * pow(10, digits - d - 1);
      make_palindromes(d+1);
      p -= ((int)(p / (pow(10, d))) % 10) * pow(10, digits - d - 1);
    }
    else {
      for (int i=0;i<10;i++) {
        p += (i * pow(10, digits - d - 1));
        make_palindromes(d+1);
        p -= (i * pow(10, digits - d - 1));
      }
    }
  }
}

int main() {
  ofstream fout ("pprime.out");
  ifstream fin ("pprime.in");
  fin >> a >> b;//
  digitsLim = to_string(b).size();
  make_palindromes(-1);
  for (int i=0;i<pals.size();i++) {
    if (pals[i] >= a && pals[i] <= b && isPrime(pals[i]))
      fout << pals[i] << endl;//
  }
  return 0;
}
