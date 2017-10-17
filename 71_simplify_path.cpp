#include <iostream>
#include <string>
#include <assert.h>
#include <stack>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
       stack<string> stk;
       process(path, 0, stk);
       if(stk.empty())
           return "/";
       else
       {
           string str;
           return stk_to_string(stk, str);
       }
    }

    void process(string path,int i,stack<string> &stk)
    {
        if(i >= path.size() || i == string::npos)
            return;

        size_t s_pos = path.find_first_not_of("/", i);
        if(s_pos == string::npos )
            return;

        size_t e_pos = path.find_first_of("/", s_pos);
        string subs;

        auto add_str_to_stk = [&](){
            if(subs.compare("..") == 0 )
            {
                if(not stk.empty())
                {
                    //cout << "Pop:" << subs <<endl;
                    stk.pop();
                }
            }
            else if(subs.compare(".") == 0)
            {
                //nothing
            }
            else{
                //cout << "Push:" << subs << endl;
                stk.push(subs);
            }
        };

        if(e_pos == string::npos)
        {
            subs = path.substr(s_pos);
            add_str_to_stk();
        }
        else{
            subs = path.substr(s_pos, e_pos-s_pos);
            add_str_to_stk();
        }
        process(path, e_pos, stk);
    }

    string stk_to_string(stack<string> &stk, string &str)
    {
        if(stk.empty())
            return str;
        string s = stk.top();
        stk.pop();
        stk_to_string(stk, str);
        str += "/";
        str += s;
        return str;
    }
};

int main(int argc, char *argv[])
{
    Solution sln;
    string str("/../");
    cout << "Before simplify: " << str << endl;
    cout << "After simplify: ";
    cout << sln.simplifyPath(str) << endl;
    return 0;
}
