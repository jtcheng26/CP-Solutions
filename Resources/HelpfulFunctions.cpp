/*
  List of helpful C++ functions/algorithms/data for CP problems.
*/

// increase stack size for 10m+ recursive calls
g++ -std=c++17 -Wl,-stack_size -Wl,0x10000000 main.cpp

// all required includes, structs, and typedefs for functions
#include <vector>
#include <algorithm>
#include <cmath>
typedef long long ll;

// Alphabet for letter-to-number conversions
string decode = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

// Whether or not an int/long long is a palindrome.
// Changing input type makes it work for strings as well.
bool isPalindrome(ll num) {
  string temp = to_string(num);
  for (int i=0;i<temp.size()/2;i++) {
    if (!(temp[i] == temp[temp.size()-i-1]))
      return false;
  }
  return true;
}

// Converts base 10 number to any base from 2 to 10.
ll base_convert(int num, int nbase) {
  if (nbase == 10 || num == 0)
    return num;
  ll temp = num;
  ll res = 0;
  for (int i=0;temp>0;i++) {
    int digit = temp % nbase;
    temp /= nbase;
    res += (digit * (pow(10, i)));
  }
  return res;
}

// Converts a binary string to a base 10 integer of equal value
int bin_to_int(string a) {
  int res = 0;
  for (int i=a.length()-1;i>=0;i--) {
    if (a.substr(i, 1) == "1")
      res += (pow(2, a.length()-i-1));
  }
  return res;
}

// Returns a 90 degree CCW rotation of a 2d vector.
vector<vector<char> > sqrotate(vector<vector<char> > sqr) {
  vector<vector<char> > rtres;
  for (int i=0;i<n;i++) {
    vector<char> row (n, 0);
    rtres.push_back(row);
  }
  for (int i=0;i<n;i++) {
    for (int j=n-1;j>=0;j--) {
      rtres[j][i] = sqr[i][n - j - 1];
    }
  }
  return rtres;
}

// Returns a horizontal reflection (around vertical line) of a 2d vector.
vector<vector<char> > reflect(vector<vector<char> > sqr) {
  vector<vector<char> > rfres;
  for (int i=0;i<n;i++) {
    vector<char> row (n, 0);
    rfres.push_back(row);
  }
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      rfres[i][j] = sqr[i][n-j-1];
    }
  }
  return rfres;
}

// gcd of 2 integers
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
