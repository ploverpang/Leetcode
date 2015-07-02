#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatchWrongAnswer(string s, string p) {
		int it_s = s.length()-1;
		int it_p = p.length()-1;
		while (it_s >= 0)
		{
			if (p[it_p] == '*')
			{
				if (p[it_p-1] == '.')
				{
					s.replace(0, it_s+1, string(1, '.')+string("*"));
					it_s = -1;
				}
				else
				{
					int replacedLen=0;
					while (it_s >=0 && s[it_s] == p[it_p-1] )
					{
						replacedLen++;
						it_s--;
					}
					s.replace(it_s+1, replacedLen, string(1, p[it_p-1])+string("*"));
				}
				it_p -= 2;
			}
			else 
			{
				if (p[it_p] == '.') 
					s[it_s] = '.';
				it_p--;
				it_s--;
			}
		}
		while(it_p >= 0)
		{
			if (p[it_p] != '*')
			{
				return false;	
			}
			else
			{
				s.insert(0, string(1, p[it_p-1])+string("*"));
			}
			it_p-=2;
		}
		return (s.compare(p)==0 ? true : false);
    }

    bool isMatch(string s, string p) {

		size_t pos = 0;
		int starCount = 0;
		while(1)
		{
			pos = p.find('*', pos+1);	
			if (pos != string::npos)
			{
				starCount++;
			}
			else
				break;
		}
/*
		for (int i = 0; i < length; i++)
		{

		}
	*/
		return true;
	}
};

void fun(vector<char> person, int personIndex, int remainApple)
{
	if (remainApple == 0 || personIndex == person.size())
	{
		cout << endl;
		return;
	}
	
	for (int i = 0; i <= remainApple; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << person[personIndex] << " "; 
		}
		fun(person, personIndex+1, remainApple-i);
	}
}
/*
void main()
{
	vector<char> person;
	person.push_back('a');
	person.push_back('b');
	person.push_back('c');
	fun(person, 0, 3);


	Solution sln;
	cout << sln.isMatch("aaa", "ab*a*c*a") << endl;
	system("PAUSE");
}
*/