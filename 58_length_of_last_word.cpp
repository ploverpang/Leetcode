#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:

    int lengthOfLastWord(string s) {
        if(s.empty())
            return 0;
        while(*(s.end()-1) == ' ')
        {
            s.erase(s.end()-1);
        }
        std::size_t found = s.find_last_of(" ");
        if(found == string::npos)
            return s.length();
        return s.length() - found -1;
    }
};

int main(int argc, char *argv[])
{
    Solution sln;
    string str("Helloworld   ");
    cout << sln.lengthOfLastWord(str) << endl;
    return 0;
}

