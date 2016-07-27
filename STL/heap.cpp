#include <iostream>   // std::cout 
#include <algorithm>  // std::make_heap, std::pop_heap std::push_head std::sort_heap
#include <vector>     // std::vector

using namespace std;
int main() {
  int list[] = {10, 20, 30, 5, 15};
  vector<int> v(list, list+5);

  make_heap(v.begin(), v.end());
  cout << "initail max heap : " << v.front() << endl;

  pop_heap(v.begin(), v.end());
  v.pop_back();
  cout << "make heap after pop : " << v.front() << endl;

  v.push_back(99);
  push_heap(v.begin(), v.end());
  cout << "make heap after push : " << v.front() << endl;

  sort_heap(v.begin(), v.end());

  cout << "final sorted range : ";

  for (int i = 0; i < v.size(); i++) 
    cout << " " <<  v[i];
  cout << endl;
  return 0;
}
