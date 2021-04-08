#include <iostream>
#include <fstream>

using namespace std;

int main() {
  //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  ofstream fout ("2020Q3_GEN3.txt");
  fout << 90 << endl;
  for (int i=1;i<=87;i++) {
    fout << 18300 << endl;
    for (int j=-9150;j<9150;j++) {
      fout << j << " " << 100000000 << endl;
    }
  }
  for (int i=1;i<=3;i++) {
    fout << 800000 << endl;
    for (int j=-400000;j<400000;j++) {
      fout << j << " " << 100000000 << endl;
    }
  }
  return 0;
}
