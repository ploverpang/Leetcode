#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.empty())
            return result;
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

        result = combination(digits, digits.size()-1, LUT);
        return result;
    }

	vector<string> combination(string digits, int index, char LUT[9][4])
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

        vector<string> vecStr;
		if (index == 0)
		{
			for (int j = 0; j < nLetterCandidate; j++)
			{
				vecStr.push_back(string(1,LUT[num-1][j]));
            }
			return vecStr;
		}

		vecStr = combination(digits, index-1, LUT);
		vector<string> copyVecStr(vecStr);
		vecStr.clear();

		for (int i = 0; i < copyVecStr.size(); i++)
		{
			string str = copyVecStr[i];
			for (int j = 0; j < nLetterCandidate; j++)
			{
                string strTmp = str + string(1, LUT[num-1][j]);
				vecStr.push_back(strTmp);	
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
