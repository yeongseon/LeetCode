#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

int output1;
vector<int> input_map;

vector<int> make_map(string input2) {
  vector<int> map;

  int size = input2.size();

  string temp;
  for (int i = 0; i < size; i++) {
    if (input2[i] == '(' ||  input2[i] == ',' || input2[i] == ')') {
      int num = atoi(temp.c_str());
      if (num != 0) {
        map.push_back(num);
        temp.erase();
      }
      continue;
    } else {
      //cout << input2[i] << endl;
      temp.push_back(input2[i]);
      
    }
  }
  return map;
}

int get_money(int dest, int y, int x) {
  int money = 0;

  // terminate condition
  if (y == dest-1 && x == dest-1)
    return input_map[15];

  if (y < dest && x < dest) {
    cout << y << " " << x << " " << input_map[dest*y+x]  << endl;
    money = input_map[dest*y+x] + max(get_money(dest, y+1, x), get_money(dest, y, x+1));
  }

  return money;
}

void CollectMoney(int input1, string input2) {
  /*
  cout << "input1(" << input1 << ")" << endl;
  cout << "input2(" << input2 << ")" << endl;
  */
  input_map = make_map(input2); /* 1D array list */
  //cout << input_map.size() << " " <<  input_map[15] << endl;


  cout << get_money(input1, 0, 0) << endl; 

}

int main() {
  CollectMoney(4, "(1,7,5,2),(5,12,3,6),(100,9,23,16),(16,4,5,9)");
  return 0;
}


