#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
	int multiply_char(char a, char b)
	{
		return (a-'0')*(b-'0');
	}

    string multiply(string num1, string num2) {
		string result;

		bool positive = true;
		if(num1[0] == '-')
		{
			positive = !positive;
			num1 = num1.substr(1);
		}
		if (num2[0] == '-')
		{
			positive = !positive;
			num2 = num2.substr(1);
		}

		result.resize(num1.size()+num2.size());
		int remain = 0;
		for (int i = result.size()-1; i >= 0 ; i--)
		{
			int sum = 0;
			for (int j = num1.size()-1; j >= 0; j--)
			{
				int k = i - j -1;
				if (k >= 0 && k < num2.size())
				{
					sum += multiply_char(num1[j], num2[k]);
				}
			}
			sum += remain;
			result[i] = (sum % 10)+'0';
			remain = (int) (sum / 10); 
		}
		int pos = result.find_first_not_of('0');
		if (pos == -1)
		{
			return "0";
		}
		else
		{
			result = result.substr(pos);
		}
		if (!positive)
		{
			result.insert(result.begin(), '-');
		}
		return result;
    }
};
/*
int main()
{
	string num1("123");
	string num2("0");
	Solution sln;
	cout << sln.multiply(num1, num2) << endl;
	system("PAUSE");
	return 0;
}
*/