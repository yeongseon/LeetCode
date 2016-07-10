#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>

using namespace std;

string output1;

string reverseCharacter(string istring) {
  string ostring;
  int size = istring.size();

  for (int i = 1; i <=  size; i++) {
    if (i == 1) {
      ostring.push_back(toupper(istring[size-i]));
    } else
      ostring.push_back(tolower(istring[size-i]));
  }
  return ostring;
}

void ReverseCharacter(string input1) {
  stringstream ss(input1);
  string buf;

  vector<string> tokens;

  while(ss >> buf)
    tokens.push_back(buf);

  output1.clear();

  int size = tokens.size();
  for (int i = 0; i < size; i++) {
    output1 += reverseCharacter(tokens[i]);
    if (i != size - 1)
      output1 += " ";
  }
    
}

int main() {
  int rc = 0;

  // input : Hello world output : Olleh Dlrow
  // ReverseCharacter("Hello world");
  ReverseCharacter("are you sure you don't want to come for the party?");
  cout << "output1(" << output1 << ")" << endl;
  return rc;
}
