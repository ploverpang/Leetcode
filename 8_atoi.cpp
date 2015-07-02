#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
	bool my_atoi(const string str, int &result)
	{
		//非法字符
		if (str.find_first_not_of("-+1234567890.") != str.npos)
		{
			return false;
		}
		//减号位置
		if (str.find("-")!=str.npos && str.rfind("-")!=0)
			return false;
		//加号位置
		if (str.find("+")!=str.npos && str.rfind("+")!=0)
		{
			return false;
		}
		//小数点
		if(str.find(".") != str.rfind("."))
		{
			return false;
		}

		string str_tmp(str);
		result = 0;

		//舍弃小数点后面的
		size_t loc=str_tmp.find(".");
		if(loc!=str_tmp.npos)
		{
			str_tmp=str_tmp.substr(0, loc);
			if (str_tmp.empty())
			{
				return true;
			}
		}

		//舍弃正负号
		bool positive = true;
		if (str_tmp.find("-")!=str_tmp.npos)
		{
			positive = false;
			str_tmp = str_tmp.substr(1, str_tmp.length());
		}
		if (str_tmp.find("+")!=str_tmp.npos)
		{
			str_tmp = str_tmp.substr(1, str_tmp.length());
		}

		//舍弃有效位之前的0
		while(str_tmp.find("0")==0)
		{
			str_tmp = str_tmp.substr(1, str_tmp.length());
		}
		
		for (int i = 0; i < str_tmp.length(); ++i)
		{
			result = result*10 +str_tmp[i]-'0';
		}
		if (!positive)
		{
			result = -result;
		}
		return true;
	}
protected:
private:
};

/*
int main()
{
	Solution sln;
	string test_1;
	int result;
	while (cin)
	{
		cin >> test_1;
		if (sln.my_atoi(test_1, result))
		{
			cout << result << endl;
		}
		else
		{
			cout << "Not a number" << endl;
		}
	}
	system("PAUSE");
}
*/