#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
		if (n == 1)
		{
			return "1";
		}	
		string str("1");
		for (int i = 1; i < n; i++)
		{
			str = process(str);	
		}
		return str;
    }

	string int2string(int n)
	{
		ostringstream oss;
		oss << n; 
		return oss.str();
	}

	string process(string &str)
	{
		

		int index = 0;
		string result;
		while(index < str.size()) 
		{
			int cnt = 1;
			int repeatIndex = index;
			while(repeatIndex < str.size()-1 && str[repeatIndex] == str[repeatIndex+1])
			{
				cnt++;
				repeatIndex++;
			}
			//result+= process(int2string(cnt));
			result+= int2string(cnt);
			result+= str[index];
			index += cnt;
		}
		return result;
	}
};

/*
int main()
{
	Solution sln;
	cout <<sln.countAndSay(5) << endl;
	system("PAUSE");
	return 0;
}
*/