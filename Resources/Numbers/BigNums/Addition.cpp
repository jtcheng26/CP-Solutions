/* addition with (very) large numbers!
*/

// Simple, 1 digit in each array indice.
// Works reasonably well up to around 1000 digits.
struct bigNum {
  vector<int> digits;
  int numDigits = 1;
  void init() {
    digits.resize(500);
    digits[0] = 0;
  }
  void initAs(int num) {
    digits.resize(500);
    numDigits = 1; int dig;
    while (num > 0) {
      numDigits++;
      dig = num % 10;
      num /= 10;
      digits[numDigits-2] = dig;
    }
    numDigits-=1;
  }
  void add(bigNum b) {
    int carry = 0;
    int mxDig = max(numDigits, b.numDigits);
    for (int i=0;i<mxDig;i++) {
      int temp = digits[i];
      digits[i] = (digits[i] + b.digits[i] + carry) % 10;
      carry = (temp + b.digits[i] + carry) / 10;
    }
    if (carry > 0) {
      digits[mxDig] = carry;
      numDigits = mxDig + 1;
    } else numDigits = mxDig;
  }
  void setTo(bigNum b) {
    for (int i=0;i<b.numDigits;i++) digits[i] = b.digits[i];
    for (int i=b.numDigits;i<numDigits;i++) digits[i] = 0;
    numDigits = b.numDigits;
  }
  string toString() {
    string s = "";
    for (int i=numDigits-1;i>=0;i--) s += to_string(digits[i]);
    return s;
  }
};
