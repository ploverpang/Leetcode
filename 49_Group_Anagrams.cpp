#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string> > result;
		if (strs.empty())
		{
			return result;
		}
		vector<pair<string, int>> strMap;

		for (int i = 0; i < strs.size(); i++)
		{
			strMap.push_back(make_pair(strs[i], i));
		}

		for(vector<pair<string, int> >::iterator it = strMap.begin();
			it != strMap.end(); it++)
		{
			sort(it->first.begin(), it->first.end());
		}

		sort(strMap.begin(), strMap.end(), comparer);
		
		string beforeStr("ejaifjiafjdsajf;ajfiejijfia;jfiajf;jasd;fjak;fkasjfk;jk;jk");
		for(vector<pair<string, int> >::iterator it = strMap.begin();
			it != strMap.end(); it++)
		{
			if (it->first.compare(beforeStr)==0)
			{
				(result.end()-1)->push_back(strs[it->second]);	
			}	
			else
			{
				vector<string> newStrs;
				newStrs.push_back(strs[it->second]);
				result.push_back(newStrs);
				beforeStr = it->first;
			}
		}	

		for (int i = 0; i < result.size(); i++)
		{
			sort(result[i].begin(), result[i].end());
		}

		return result;
    }

	static bool comparer(pair<string, int> &p1, pair<string, int> &p2)
	{
		return (p1.first < p2.first);
	}
};

/*
int main()
{
	vector<string> data;
	data.push_back("ate");
	data.push_back("eat");
	data.push_back("tea");
	data.push_back("nat");
	data.push_back("tan");
	data.push_back("bat");
	Solution sln;
	vector<vector<string> > result = sln.groupAnagrams(data);

	for (int i = 0; i < result.size(); i++) 
	{
		for (int j = 0; j < result[i].size(); j++)
		{
			cout << result[i][j] << " ";
		}
		cout << endl;
	}

	system("PAUSE");
	return 0;
}
*/