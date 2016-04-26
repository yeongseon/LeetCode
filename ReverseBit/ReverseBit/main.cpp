#include <iostream>
#include "Solution.h"

using namespace std;
int main() {
	Solution solution;
	cout << solution.reverseBits(43261596) << endl;
	cout << solution.reverseBits(00000000000000000000000000000000) << endl;
	
	return 0;
}