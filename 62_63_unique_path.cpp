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

    int uniquePaths(int m, int n) {
        if(m <=0 || n<= 0)
            return 0;

        vector<vector<int> > table(m);
        for(int i=0; i<m; i++)
        {
            table[i].resize(n);
        }
        for(int x=0; x<n; x++)
        {
            table[m-1][x] = 1;
        }
        for(int y=0; y<m; y++)
        {
            table[y][n-1] = 1;
        }

        int x = n-2;
        int y = m-2;

        while(x>=0 && y>=0)
        {
            if(x>=0 && y>=0)
            {
                for(int xx=x; xx>=0; xx--)
                {
                    table[y][xx] = table[y+1][xx] + table[y][xx+1];
                }
                y--;
            }
            if(x>=0 && y>=0)
            {
                for(int yy=y; yy>=0; yy--)
                {
                    table[yy][x] = table[yy+1][x] + table[yy][x+1];
                }
                x--;
            }
        }
        return table[0][0];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        if(obstacleGrid.empty())
            return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if(m <=0 || n<= 0)
            return 0;

        vector<vector<int> > table(m);
        for(int i=0; i<m; i++)
        {
            table[i].resize(n);
        }

        if(obstacleGrid[m-1][n-1] == 1)
            return 0;
        else
            table[m-1][n-1] = 1;

        for(int x=n-2; x>=0; x--)
        {
            table[m-1][x] = obstacleGrid[m-1][x] == 0 ? table[m-1][x+1] : 0;
        }
        for(int y=m-2; y>=0; y--)
        {
            table[y][n-1] = obstacleGrid[y][n-1]  == 0 ? table[y+1][n-1] : 0;
        }
        //print_table(table);

        int x = n-2;
        int y = m-2;

        while(x>=0 && y>=0)
        {
            if(x>=0 && y>=0)
            {
                for(int xx=x; xx>=0; xx--)
                {
                    table[y][xx] = obstacleGrid[y][xx] == 0 ?
                        table[y+1][xx] + table[y][xx+1] : 0;
                }
                y--;
            }
            if(x>=0 && y>=0)
            {
                for(int yy=y; yy>=0; yy--)
                {
                    table[yy][x] = obstacleGrid[yy][x] == 0 ?
                        table[yy+1][x] + table[yy][x+1] : 0;
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
    cout << sln.uniquePaths(4,4) << endl;
    vector<vector<int> > obs = {
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };
    vector<vector<int> > obs2 = {
        {1,0}
    };

    cout <<"obs path: " <<  sln.uniquePathsWithObstacles(obs2) << endl;
    return 0;
}
