#include <iostream>

using namespace std;

int output1;

int get_number(int end, int next, bool isX) {
  int number = 0;

  if (next == end)
    return 1;

  if (isX == true)
    number = get_number(end, next+1, false);
  else
    number = get_number(end, next+1, true) + get_number(end, next+1, false);

  return number;
}

void StreetPlanning(int input1) {
  int number = 0; 

  number = get_number(input1, 1, true) + get_number(input1, 1, false);

  output1 = number * number;
}

int main() {
  // Input : 3 Ouput : 25
  StreetPlanning(3); 
  cout << "Output(" << output1 << ")" << endl;
}
