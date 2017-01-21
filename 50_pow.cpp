#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
		if(x==1) return 1;
        if(x==-1) 
		{
			if (n&1)
			{
				return -1;
			}
			else
			{
				return 1;
			}
		}
		if (n == 0)
		{
			return 1;
		}
		else if (n < 0)
		{
			return (1/myPow(x, -1*n));
		}
		else
		{
			double tmp = myPow(x, n/2);
			if (n&1)
			{
				return tmp*tmp*x;
			}
			else
			{
				return tmp*tmp;
			}
		}
    }
};

/*
int main()
{
	Solution sln;
	cout << sln.myPow(-1,-2147483647) << endl;
	system("PAUSE");
	return 0;
}
*/