#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
		char LUT[9][4] = {
			{},
			{'a','b','c'},
			{'d','e','f'},
			{'g','h','i'},
			{'j','k','l'},
			{'m','n','o'},
			{'p','q','r','s'},
			{'t','u','v'},
			{'w','x','y','z'}
		};
		vector<string> result;
		return combination(digits, digits.size()-1, LUT, result);
    }

	vector<string> combination(string digits, int index, char LUT[][4], vector<string> &vecStr)
	{
		int num = digits[index]-'0';

		int nLetterCandidate;
		if (num==1)
		{
			nLetterCandidate = 0;
		}
		else if (num ==7 || num == 9)
		{
			nLetterCandidate = 4;
		}
		else
		{
			nLetterCandidate =3;
		}

		if (index == 0)
		{
			for (int j = 0; j < nLetterCandidate; j++)
			{
				vecStr.push_back(string(LUT[num-1][j],1));
			}
			return vecStr;
		}

		vecStr = combination(digits, index-1, LUT, vecStr);
		vector<string> copyVecStr(vecStr);
		vecStr.clear();

		for (int i = 0; i < copyVecStr.size(); i++)
		{
			string str = copyVecStr[i];
			for (int j = 0; j < nLetterCandidate; j++)
			{
				vecStr.push_back(str.append(string(LUT[num-1][j], 1)));	
			}
		}
		return vecStr;
	}
};

int main()
{
	string digits("23");
	Solution sln;
	vector<string> result = sln.letterCombinations(digits);
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << endl;
	}
	system("PAUSE");
	return 0;
}
