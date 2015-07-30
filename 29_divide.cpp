#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
		if (divisor == 0)
		{
			return INT_MAX;
		}
		if(dividend == 0)
			return 0;

		bool addNegitive = false;

		long long douDividend = dividend;
		long long douDivisor = divisor;

		if (douDividend<0 && douDivisor>0)
		{
			douDividend = 0 - douDividend;
			addNegitive = true;
		}
		else if (douDividend>0 && douDivisor<0)
		{
			
			douDivisor = 0 - douDivisor;
			addNegitive = true;
		}
		else if(douDividend < 0 && douDivisor<0)
		{
			
			douDividend = 0 - douDividend;
			douDivisor = 0 - douDivisor;
		}

		double result = 0;
		int stepIdx = 0;
		vector<long long> step;
		vector<int> resultStep;
		step.push_back(douDivisor);
		resultStep.push_back(1);

		while (douDividend >= step[stepIdx] )
		{
			douDividend -= step[stepIdx];
			result += resultStep[stepIdx];
			step.push_back(step[stepIdx]+step[stepIdx]);
			resultStep.push_back(resultStep[stepIdx]+resultStep[stepIdx]);
			stepIdx++;
		}

		stepIdx--;
		while (stepIdx >= 0)
		{
			while (douDividend-step[stepIdx] >= 0)
			{
				douDividend -= step[stepIdx];
				result += resultStep[stepIdx];
			}
			stepIdx--;
		}
		
		result = addNegitive ? (0-result):result ;
		return result > INT_MAX ? INT_MAX : result;
    }
};
/*
int main()
{
	Solution sln;
	cout << sln.divide(-2147483648, -1) << endl;
	system("PAUSE");
	return 0;
}
*/
