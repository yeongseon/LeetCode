#include "Solution.h"

int main() {
	Solution solution;
	vector<int> v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);

	solution.rotate(v, 2);
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";

	return 0;
}