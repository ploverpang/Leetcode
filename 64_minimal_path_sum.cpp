#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;
class Solution {
public:

    void print_table(vector<vector<int> > &m)
    {
        for(int i=0; i<m.size(); i++)
        {
            for(int j=0; j<m[i].size(); j++)
            {
                cout << m[i][j] << '\t';
            }
            cout << endl;
        }
    }

    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty())
            return 0;

        int m = grid.size();
        int n = grid[0].size();

        if(m <=0 || n<= 0)
            return 0;

        vector<vector<int> > table(m);
        for(int i=0; i<m; i++)
        {
            table[i].resize(n);
        }
        table[m-1][n-1] = grid[m-1][n-1];

        for(int x=n-2; x>=0; x--)
        {
            table[m-1][x] = table[m-1][x+1] + grid[m-1][x];
        }
        for(int y=m-2; y>=0; y--)
        {
            table[y][n-1] = table[y+1][n-1] + grid[y][n-1];
        }

        int x = n-2;
        int y = m-2;

        while(x>=0 && y>=0)
        {
            if(x>=0 && y>=0)
            {
                for(int xx=x; xx>=0; xx--)
                {
                    table[y][xx] = min(table[y+1][xx],table[y][xx+1]) + grid[y][xx];
                }
                y--;
            }
            if(x>=0 && y>=0)
            {
                for(int yy=y; yy>=0; yy--)
                {
                    table[yy][x] = min(
                        table[yy+1][x] , table[yy][x+1]) + grid[yy][x];
                }
                x--;
            }
        }
        //print_table(table);
        return table[0][0];
    }
};

int main(int argc, char *argv[])
{
    Solution sln;
    vector<vector<int> > obs = {
        {1,1,1},
        {1,1,1},
        {1,1,1}
    };
    cout <<"min path: " <<  sln.minPathSum(obs) << endl;
    return 0;
}
