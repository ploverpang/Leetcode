#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
		string result;
		int ary[4];
		parseNum(num, ary);
		processOneBit(result, string(), string(), string("M"), (ary[0]));
		processOneBit(result, string("M"), string("D"), string("C"), (ary[1]));
		processOneBit(result, string("C"), string("L"), string("X"), (ary[2]));
		processOneBit(result, string("X"), string("V"), string("I"), (ary[3]));
		return result;
    }

	void parseNum(int num, int ary[4])
	{
		ary[3] = num %10;
		num /= 10;
		ary[2] = num %10;
		num /= 10;
		ary[1] = num %10;
		num /=10;
		ary[0] = num %10;
	}

	// 如果当前位的下一位为9，当前位当做+1来处理
	void processOneBit(string &str, string ten, string five, string one, int oneBit)
	{
		if (oneBit >= 5)
		{
			oneBit -= 5;
			if (oneBit == 4)
			{
				str = str + one + ten;
			}
			else
			{
				str += five;
				while (oneBit > 0)
				{
					str += one;
					oneBit--;
				}
			}
		}
		else
		{
			if (oneBit == 4)
			{
				str = str + one + five;
			}
			else
			{
				while (oneBit > 0)
				{
					str += one;
					oneBit--;
				}
			}
		}
	}
};
/*
int main()
{
	Solution sln;
	cout << sln.intToRoman(19) << endl;
	system("PAUSE");
	return 0;
}
*/