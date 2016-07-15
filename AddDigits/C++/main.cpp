#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:
  int addDigits(int num) {

    string strnum;

    strnum = to_string(num);
    int size = strnum.size();
    int sum;

    if(size == 1)
      return num;

    while(size != 1) {
      sum = 0;
      for (int i = 0 ; i < size; i++) {
        char s = strnum.at(i);
        sum += stoi(&s);;

          // sum += stoi(strnum[i]);
          // sum += atoi((strnum[i]).c_str());
          //sum += stoi(strnum.at(i));
      }
      strnum = to_string(sum);
      size = strnum.size();
    }

    return sum;
  }
};

int main() {
  Solution s;

  cout << s.addDigits(38) << endl;
  cout << s.addDigits(123) << endl;

  return 0;
}
