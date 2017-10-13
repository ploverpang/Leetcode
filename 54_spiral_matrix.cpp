#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.empty())
        {
            return result;
        }
        const int rows = matrix.size();
        const int cols = matrix[0].size();

        int l = 0;
        int r = cols-1;
        int t = 0;
        int b = rows-1;

        while(1)
        {
            for(int x=l; x<=r; x++)
            {
                result.push_back(matrix[t][x]);
            }
            t++;
            if(t>b) break;

            for(int y=t; y<=b; y++)
            {
                result.push_back(matrix[y][r]);
            }
            r--;
            if(r<l) break;

            for(int x=r; x>=l; x--)
            {
                result.push_back(matrix[b][x]);
            }
            b++;
            if(t>b) break;

            for(int y=b; y>=t; y--)
            {
                result.push_back(matrix[y][l]);
            }
            l++;
            if(r<l) break;
        }
        return result;
    }
};

int main(int argc, char *argv[])
{
    Solution sln;

    vector<vector<int>> nums = {{1,2,3},
        {4,5,6},
        {7,8,9}};

    vector<int> result = sln.spiralOrder(nums);
    for(int i=0; i<result.size(); i++)
    {
        cout << result[i] << '\t';
    }
    cout << endl;
    return 0;
}
