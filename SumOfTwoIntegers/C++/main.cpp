#include <iostream>
#include <string>
#include <bitset>

using namespace std;

class Solution {
public:
  int getSum(int a, int b) {
    bitset<32> bita(a);
    bitset<32> bitb(b);
    bitset<32> bitc;

    // cout << bita.to_string() << endl;
    // cout << bitb.to_string() << endl;

    bool carry = false;
    bitc.reset();

    for(int i = 0; i < 32; i++) {
      if (carry && !bita.test(i) && !bitb.test(i)) {
        bitc.set(i);
        carry = false;
      } else if (carry && bita.test(i) && bitb.test(i)) {
        bitc.set(i);
        carry = true;
      } else if (carry && (bita.test(i) || bitb.test(i))) {
        carry = true;
      } else if (bita.test(i) && bitb.test(i)) {
        carry = true;
      } else if(bita.test(i) || bitb.test(i)) {
        bitc.set(i);
        carry = false;
      }
    }
    // cout << bitc.to_string() << endl;
    int c = bitc.to_ulong();
    return c;
  }
};

int main() {
  Solution s;
  // cout << (true && !false && !false) << endl;
  // cout << (true && (false || true)) << endl;
  // cout << (true && (false || false)) << endl;
  cout << s.getSum(3, 3) << endl;
  cout << s.getSum(20, 30) << endl;
  return 0;
}
