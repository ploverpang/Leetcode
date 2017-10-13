#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > matrix(n);
        if(n==0)
        {
            return matrix;
        }
        for(int i=0; i<n; i++) {
            matrix[i].resize(n);
        }
        const int rows = n;
        const int cols = n;

        int l = 0;
        int r = cols-1;
        int t = 0;
        int b = rows-1;

        int idx = 1;
        int total_num = n*n;

        while(1)
        {
            for(int x=l; x<=r; x++)
            {
                matrix[t][x]=idx;
                idx++;

            }
            t++;
            if(t>b) break;

            for(int y=t; y<=b; y++)
            {
                matrix[y][r]=idx;
                idx++;
            }
            r--;
            if(r<l) break;

            for(int x=r; x>=l; x--)
            {
                matrix[b][x] = idx;
                idx++;
            }
            b--;
            if(t>b) break;

            for(int y=b; y>=t; y--)
            {
                matrix[y][l] = idx;
                idx++;
            }
            l++;
            if(r<l) break;
        }
        assert(idx == total_num+1);
        return matrix;
    }
};

int main(int argc, char *argv[])
{
    Solution sln;
    auto m = sln.generateMatrix(4);
    for(int i=0; i<m.size(); i++)
    {
        for(int j=0; j<m[i].size(); j++)
        {
            cout << m[i][j] << '\t';
        }
        cout << endl;
    }
    return 0;
}
