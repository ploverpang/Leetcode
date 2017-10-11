#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        int max_tmp = nums[0];
        int max_num = max_tmp;
        for(int i=1; i<nums.size(); i++)
        {
            max_tmp = max(max_tmp + nums[i], nums[i]);
            if(max_tmp > max_num)
            {
                max_num = max_tmp;
            }
        }
        return max_num;
    }
};

int main(int argc, char *argv[])
{
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    Solution sln;
    cout << sln.maxSubArray(nums) << endl;
    return 0;
}
