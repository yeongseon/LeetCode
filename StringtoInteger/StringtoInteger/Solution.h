#pragma once
#include <iostream>
#include <string>

using namespace std;
class Solution
{
public:
	Solution();
	~Solution();
	int myAtoi(string str) {
		bool sign = true;
		string input;
		double output = 0;

		int flag = 0;
		for (uint32_t i = 0; i < str.length(); ++i) {
			if (str[i] == '-') {
				sign = false;
				flag++;
			}
			else if (str[i] == '+') {
				sign = true;
				flag++;
			}
		}
		if (flag > 1)
			return 0;

		flag = 0;
		int flag2 = 0;
		for (uint32_t i = 0; i < str.length(); ++i) {
			if (str[i] >= 48 && str[i] <= 57) {
				input.push_back(str[i]);
				if (flag == 0)
					flag = 1;
			}
			else {
				if (str[i] == '-' || str[i] == ' ' || str[i] == '+') {
					if (flag == 1)
						break;

					if (str[i] == '-')
						flag2 = 1;
					else if (str[i] == '+')
						flag2 = 1;
					else if (str[i] == ' ')
						if (flag2 == 1)
							flag2 = 2;
					continue;
				}
				else
					break;
			}
		}

		if (flag2 > 1)
			return 0;
		
		if (input.length() == 0)
			return 0;

		double multiply = 1;
		output = 0;
		for (int i = input.length()-1; i >= 0; --i) {			
			cout << input[i] << " " << (int)(input[i] - '0') << endl;
			output += (int)(input[i] - '0') * multiply;
			multiply = multiply * 10;			
		}		
		cout << output << endl;
		if (!sign)
			output = output * -1;

		if (output < INT_MIN)
			output = INT_MIN;
		if (output > INT_MAX)
			output = INT_MAX;
		
		return (int)output;
	}
};

