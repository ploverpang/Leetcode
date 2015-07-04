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
		return true;
	}

	vector<string> removeStar(string p, int star_pos, int remain, vector<string> &vecStr)
	{
		if (star_pos == -1)
		{
			return vecStr;
		}
		if (star_pos == 0)
		{
			star_pos = p.rfind('*');
		}

		int pos; 
		if (string::npos == p.rfind('*', star_pos-1))
		{
			pos = -1;
		}
		else
		{
			pos = p.rfind('*', star_pos-1);	
		}

		vector<string> copyedVec;
		for (int k = 0; k <= remain; k++)
		{
			vecStr = removeStar(p, pos, remain-k, vecStr);
			//vecStr.clear();

			string replacedLetter(k, p[star_pos-1]);
			for (int i = 0; i < vecStr.size(); i++)
			{
				string clonedStr = vecStr[i];
				copyedVec.push_back(clonedStr.replace(star_pos, 1, replacedLetter));
			}
		}
		vecStr.swap(copyedVec);
		return vecStr;
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
	Solution sln;
	vector<string> result;
	string p("a*b*c");
	result.push_back(p);

	string q(0, '1');
	cout << q << endl;
	result  = sln.removeStar(p, 0, 2, result);
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << endl;
	}
	cout << sln.isMatch("aaa", "ab*a*c*a") << endl;
	system("PAUSE");
}
*/