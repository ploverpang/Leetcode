#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
	int reverse(int x)
	{
		long long result = 0;
		long long x_tmp = x;
		if (x<0)
			x_tmp = (long long)x*(-1);
		while(x_tmp)
		{
			int rest = x_tmp % 10;
			x_tmp /=10;
			result=result*10+rest;
			if (result >= INT_MAX)
			{
				return 0;
			}
		}
		if (x<0)
		{
			result = -result;
		}
		return (int)result;
		
	}
protected:
private:
};

/*
int main()
{
	Solution sln;
	cout << sln.reverse(-2147483648) << endl;
	system("PAUSE");
	return 0;
}
*/