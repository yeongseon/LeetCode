#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  Solution();
  ~Solution();
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> set;
    int size = nums.size();
    vector<int> sum;


    findThreeSum(size, 0, 0, nums, true, sum, set);
    
    findThreeSum(size, 0, 0, nums, false, sum, set);

    cout << set.size() << endl;

    return set;
  }

  int findThreeSum(int end, int step, bool flag, vector<int> nums, int count,
    vector<int> sum, vector<vector<int>>& set) {

    if (step == end) {
      if (count == 2 && flag == true) {
        if (isZeroSum(sum[0], sum[1], nums[step])) {
          sum.push_back(nums[step]);
          set.push_back(sum);
          count++;
        }
      }
      return 0;
    }

    if (count == 3) {
      if (isZeroSum(sum[0], sum[1], sum[2]))
        set.push_back(sum);
      return 0;
    }

    if (flag == true) {
      sum.push_back(nums[step]);
      count++;
    }

    findThreeSum(end, step+1, true, nums, count, sum, set);
    findThreeSum(end, step+1, false, nums, count, sum, set);


    return 0;
  }

  bool isZeroSum(int a, int b, int c) {

    if ((a + b + c) == 0) {
      // cout << a << " " << b << " " << c << endl;
      return true;
    } else
      return false;
  }
};

Solution::Solution() {
}

Solution::~Solution() {
}

int main() {
  Solution solution;
  vector<int> v;
  v.push_back(-1);
  v.push_back(0);
  v.push_back(1);
  v.push_back(2);
  v.push_back(-1);
  v.push_back(-4);

  solution.threeSum(v);

}
