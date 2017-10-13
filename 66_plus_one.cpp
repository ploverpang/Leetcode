#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits.empty())
            return digits;

        int l = digits.size();
        digits[l-1]++;
        for(int i=l-1; i>=0; i--)
        {
            if(digits[i] == 10)
            {
                digits[i] = 0;
                if(i-1>=0)
                {
                    digits[i-1]++;
                }
                else
                {
                    digits.insert(digits.begin(), 1);
                }
            }
            else
                break;
        }
        return digits;
    }


};

int main(int argc, char *argv[])
{
    vector<int> d = {9,9,9,9,9};
    Solution sln;
    auto result = sln.plusOne(d);
    for(int i=0; i<result.size(); i++)
    {
        cout << result[i];
    }
    cout << endl;
    return 0;
}
