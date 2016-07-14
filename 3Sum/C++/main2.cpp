#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector< vector<int> > threeSum(vector<int>& nums) {
      queue< vector<int> > q;
      vector< vector<int> > v;
      vector<int> *s = new vector<int>(4);  // step, sum
      vector<int> *tp;
      int end = nums.size();

      (*s).push_back(1);
      (*s).push_back(nums[0]);

      q.push(*s);
      while(!q.empty()) {

        int size = q.size();
        for(int i = 0; i < size; i++) {

          tp = &(q.front());
          q.pop();

          if((*tp).size() == 4) {
            if (isZeroSum((*tp)[1], (*tp)[2], (*tp)[3]))
              v.push_back((*tp));
          } else {
            if((*tp)[0] == end) {

            } else {
              vector<int> *nv = new vector<int>(4);
              int next = (*tp)[0];
              cout << "1" << endl;
              for (int i = 0; i < (*tp).size(); i++)
                (*nv).push_back((*tp)[i]);
              cout << "2" << " " << (*nv).size() << " " << (*tp)[0] << " " << (*tp)[1] << endl;

              (*nv).push_back(nums[next]);
              cout << "3" << endl;
              (*nv)[0] = (*nv)[0] + 1;

              cout << "4" << endl;
              q.push(*tp);
              cout << "5" << endl;
              q.push(*nv);
              cout << "6" << endl;
              cout << "qsize" << q.size() << endl;
            }
          }
        }
      }
      return v;
    }

    bool isZeroSum(int a, int b, int c) {
      if ( (a + b + c) == 0)
        return true;
      else
        return false;
    }
};

int main() {
  Solution s;
  vector<int> v;
  // -1, 0, 1, 2, -1, -4
  v.push_back(-1);
  v.push_back(0);
  v.push_back(1);
  v.push_back(2);
  v.push_back(-1);
  v.push_back(-4);

  s.threeSum(v);
  /*
  queue< vector<int> > q;
  q.push(v);
  vector<int> *t;
  t = &q.front();
  cout << (*t)[5] << endl;
  */
  return 0;
}
