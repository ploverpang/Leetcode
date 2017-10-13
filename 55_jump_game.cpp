#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
   bool canJump(vector<int>& nums) {
       if(nums.empty())
           return false;

       int n = nums.size();
       int reach = 0;
       for(int i=0; i<n && i<=reach; i++)
       {
           reach = max(reach, i+nums[i]);
           if(reach >= n-1)
               return true;
       }
       return false;
       //vector<bool> table(nums.size(), false);
       //table[0] = true;
       //for(size_t i=0; i<nums.size(); i++)
       //{
            //if(table[i])
            //{
                //int max_reach = i+nums[i];
                //if(max_reach >= nums.size()-1){
                    //return true;
                //}
                //else{
                    //table[max_reach] = true;
                //}
            //}
       //}
       //return false;
   }
};

int main(int argc, char *argv[])
{
    //vector<int> nums = {3,2,1,1,4};
    vector<int> nums = {2,5,0,0};
    Solution sln;
    bool can_jump = sln.canJump(nums);
    if(can_jump)
        cout << "Can jump"  << endl;
    else
        cout <<  "Can't jump" <<endl;
    return 0;
}
