#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Solution
{
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> result;
		if (s.empty() || words.empty())
		{
			return result;
		}

		map<string, int> wordsMap;
		int wordsTotalAsc = 0;
		map<char, int> wordsLetterHists;
		int wordLetterLength = analyzeWords(words, wordsMap, wordsTotalAsc, wordsLetterHists);

		if (wordLetterLength > s.length())
		{
			return result;
		}
		int totalAsc = 0;
		map<char, int> letterHists;
		for (int i = 0; i < wordLetterLength; i++)
		{
				totalAsc += s[i];
				letterHists[s[i]] ++;
		}

		for (int i = 0; i <= s.size()-wordLetterLength; i++)
		{
			if(totalAsc == wordsTotalAsc) //&&passHistsTest(wordsLetterHists, letterHists))
			{
				string subString = s.substr(i, wordLetterLength);
				if (lastTest(subString, wordsMap))
				{
					result.push_back(i);						
				}
			}
			else
			{
				totalAsc = totalAsc - s[i] + s[i+wordLetterLength];
				letterHists[s[i]]--;
				letterHists[s[i+wordLetterLength]]++;
			}
		}
		return result;
    }

	int analyzeWords(vector<string> &words, map<string, int> &wordsMap, int &totalAsc, map<char, int> &letterHists)
	{
		int wordsTotalLetter = 0;
		for(string word : words)
		{
			wordsMap[word]++;
			for (int i = 0; i < word.size(); i++)
			{
				wordsTotalLetter++;
				totalAsc += word[i];
				letterHists[word[i]] ++;
			}
		}
		return wordsTotalLetter;
	}

	bool passHistsTest(map<char, int> &wordsHists, map<char, int> &substrHists)
	{
		auto wIt = wordsHists.begin();
		auto sIt = substrHists.begin();
		for(;sIt != wordsHists.end(); wIt++, sIt++)
		{
			if (wIt->second != sIt->second)
			{
				return false;
			}
		}
		return true;
	}

	bool lastTest(string &s, map<string, int> words)
	{
		int wordsLength = words.begin()->first.size();
		
		for (int i = 0; i < s.size(); i+=wordsLength)
		{
			string wordInStr = s.substr(i, wordsLength);
			if(words.count(wordInStr) == 0)
			{
				return false;
			}
			else if (words[wordInStr] == 1)
			{
				words.erase(wordInStr);
			}		
			else
			{
				words[wordInStr]--;
			}
		}
		if (words.empty())
		{
			return true;
		}
		return false;
	}
};
/*
int main()
{
	string wordsArray[5] =  {"fooo","barr","wing","ding","wing"};
	string s("lingmindraboofooowingdingbarrwingmonkeypoundcake");
	vector<string> words(wordsArray, wordsArray+5);
	
	Solution sln;
	vector<int> result = sln.findSubstring(s, words);
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
	cout << endl;
	system("PAUSE");
	return 0;
}
*/