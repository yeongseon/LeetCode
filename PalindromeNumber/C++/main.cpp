#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  Solution();
  ~Solution();
  bool isPalindrome(int x) {
    string s = to_string(x);
    //string s = x.str();
    int size = s.size();

    for (int i = 0; i < size/2; i++) {
      if (s[i] != s[size-1-i]) {
        return false;
      }
    }
    return true;
  }
};

Solution::Solution() {
}

Solution::~Solution() {
}

int main() {
  Solution solution;
  int input;
  cin >> input;
  if (solution.isPalindrome(input))
    cout << "true";
  else
    cout << "false";
  return 0;
}
