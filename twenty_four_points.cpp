// 24点游戏

#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<int> getSolutionOfAnyNumber(vector<int> nums, int target, vector<char> &operatorArray)
{
	if(nums.size() == 1)
	{
		if(target == nums[0]) return nums;
		else return (vector<int>());
	}
	else {
		vector<int> result;
		for (int i = 0; i < nums.size(); i++)
		{
			vector<int> numsRemoveIth(nums);
			numsRemoveIth.erase(numsRemoveIth.begin()+i);
			//加减乘除四种运算
			
			//加
			result = getSolutionOfAnyNumber(numsRemoveIth, target-nums[i], operatorArray);
			if(!result.empty()) {
				result.push_back(nums[i]);
				operatorArray.push_back('+');
				return result;
			}
			else
			{
				//减
				result = getSolutionOfAnyNumber(numsRemoveIth, target+nums[i], operatorArray);
				if(!result.empty()) {
					result.push_back(nums[i]);
					operatorArray.push_back('-');
					return result;
				}
				else
				{
					//乘，需要判断能否整除
					if(target%nums[i]==0 && nums[i]!=0)
						result = getSolutionOfAnyNumber(numsRemoveIth, target/nums[i], operatorArray);
					if (!result.empty())
					{
						result.push_back(nums[i]);
						operatorArray.push_back('*');
						return result;	
					}
					else
					{
						//除
						result = getSolutionOfAnyNumber(numsRemoveIth, target*nums[i], operatorArray);
						if(!result.empty()) {
							result.push_back(nums[i]);
							operatorArray.push_back('/');
							return result;
						}
						else
						{
							//此数字无解，返回空结果
							return vector<int>();
						}
					}
				}
			}
		}
	}
}
//计算两个数的除
int devide(int first, int second)
{
	if(first==0 || second==0)
		return 0;
	if (first>second && first%second == 0)
	{
		return first/second;
	}
	else if(second > first && second%first == 0)
	{
		return second/first;
	}
	else
	{
		return 0;	
	}
	
}

char transNum2operator(int i)
{
	switch(i)
	{
		case 0 : return '+';
		case 1 : return '-';
		case 2 : return '*';
		case 3 : return '/';
	}
}

// 单独处理两个两个数组合的情况
vector<char> processTwoTwoCombine(const vector<int> &nums, bool &revert)
{
	vector<char> operatorArr(3); //3个运算符
	revert = false;  //1、2两个数是否和3、4两个数颠倒

	int firstAndSecondCalResult[4];
	int ThirdAndFouthCalResult[4];
	firstAndSecondCalResult[0] = nums[0]+nums[1];
	firstAndSecondCalResult[1] = nums[0]-nums[1];
	firstAndSecondCalResult[2] = nums[0]*nums[1];
	firstAndSecondCalResult[3] = devide(nums[0], nums[1]); 

	ThirdAndFouthCalResult[0] = nums[2]+nums[3];
	ThirdAndFouthCalResult[1] = nums[2]-nums[3];
	ThirdAndFouthCalResult[2] = nums[2]*nums[3];
	ThirdAndFouthCalResult[3] = devide(nums[2], nums[3]); 

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if ((i==3&&firstAndSecondCalResult[i]==0) ||
				(j==3&&ThirdAndFouthCalResult[j]==0))
				continue;
			if (firstAndSecondCalResult[i]+ThirdAndFouthCalResult[j] == 24)
			{
				operatorArr[1] = '+';		
			}
			else if (firstAndSecondCalResult[i]-ThirdAndFouthCalResult[j] == 24)
			{
				operatorArr[1] = '-';		
			}
			else if (ThirdAndFouthCalResult[j]-firstAndSecondCalResult[i] == 24)
			{
				operatorArr[1] = '-';		
				revert = true;
			}
			else if (firstAndSecondCalResult[i]*ThirdAndFouthCalResult[j] == 24)
			{
				operatorArr[1] = '*';		
			}
			else if (ThirdAndFouthCalResult[j]!=0 && firstAndSecondCalResult[i]/ThirdAndFouthCalResult[j] == 24)
			{
				operatorArr[1] = '/';		
			}
			else if (firstAndSecondCalResult[i]!= 0 && ThirdAndFouthCalResult[j]/firstAndSecondCalResult[i] == 24)
			{
				operatorArr[1] = '/';		
				revert = true;
			}
			else
				continue;
			operatorArr[0] = transNum2operator(i);
			operatorArr[2] = transNum2operator(j);
			return operatorArr;
		}
	}
	return vector<char>();
}

//为运算结果加上括号
void addbracket(string &str)
{
	//string resultWithBracket(str);
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i]=='+' || str[i] == '-')
		{
			str.insert(str.begin(), '(');
			str.insert(str.begin()+i+3, ')');
			i++;
		}
	}	
}

string getSolutionOf24points(vector<int> nums)
{
	vector<char> operatorArray;
	vector<int> resultNum = getSolutionOfAnyNumber(nums, 24, operatorArray);
	string result;
	if (!resultNum.empty())
	{
		result.push_back('0'+resultNum[0]);
		for (int i = 0; i < 3; i++)
		{
			result.push_back(operatorArray[i]);
			result.push_back('0'+resultNum[i+1]);
		}
	}
	if (!result.empty())
	{
		addbracket(result);
		return result;
	}
	else
	{
		bool revert;
		vector<char> oper = processTwoTwoCombine(nums, revert);
		if (oper.empty())
		{
			return string();
		}
		if(revert)
		{
			result.push_back('('); 
			result.push_back('0'+nums[2]);
			result.push_back(oper[2]);
			result.push_back('0'+nums[3]);  
			result.push_back(')'); 
			result.push_back(oper[1]); 
			result.push_back('('); 
			result.push_back('0'+nums[0]);
			result.push_back(oper[0]);
			result.push_back('0'+nums[1]);  
			result.push_back(')'); 
		}
		else
		{
			result.push_back('('); 
			result.push_back('0'+nums[0]);
			result.push_back(oper[0]);
			result.push_back('0'+nums[1]);  
			result.push_back(')'); 
			result.push_back(oper[1]); 
			result.push_back('('); 
			result.push_back('0'+nums[2]);
			result.push_back(oper[2]);
			result.push_back('0'+nums[3]);  
			result.push_back(')'); 
		}
		return result;
	}
}

int main()
{
	int numArray[4] = {1,5,5,5};
	vector<int> numVec(numArray, numArray+4);
	string result = getSolutionOf24points(numVec);
	cout << (result.empty()? "No answer" : result)<< endl;
	system("PAUSE");
	return 0;
}
