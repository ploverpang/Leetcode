#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <assert.h>

using namespace std;

class Solution {
public:

    struct Point{
        int x;
        int y;
        Point(int _x, int _y):x(_x),y(_y){};
    };

    int cals_one_connect(queue<Point> &q, vector<vector<int> >& grid, const  int rows, const  int cols)
    {
        int n = 0;
        while(!q.empty() )
        {
            Point p = q.front();
            q.pop();
            n++;

            if(p.y>0 && grid[p.y-1][p.x] == 1)
            {
                grid[p.y-1][p.x]++;
                q.push(Point(p.x,p.y-1));
            }
            if(p.y<rows-1 && grid[p.y+1][p.x] == 1)
            {
                grid[p.y+1][p.x]++;
                q.push(Point(p.x,p.y+1));
            }
            if(p.x>0 && grid[p.y][p.x-1] == 1)
            {
                grid[p.y][p.x-1]++;
                q.push(Point(p.x-1,p.y));
            }
            if(p.x<cols-1 && grid[p.y][p.x+1] == 1)
            {
                grid[p.y][p.x+1]++;
                q.push(Point(p.x+1,p.y));
            }
        }
        assert(n>0);
        return n;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        if(grid.empty())
            return 0;

        int max_area = 0;
        queue<Point> q;
        int rows = grid.size();
        int cols = grid[0].size();
        cout << "rows: " << rows << "\tcols: " << cols << endl;
        for(int y=0; y<rows; y++)
        {
            for(int x =0; x< cols; x++)
            {
                if(grid[y][x] == 1)
                {
                    Point p(x,y);
                    q.push(p);
                    grid[y][x]++;
                    int tmp_area = cals_one_connect(q, grid, rows, cols);
                    if(tmp_area > max_area)
                    {
                        max_area = tmp_area;
                    }
                }
            }
        }

        return max_area;
    }

};

int main(int argc, char *argv[])
{
    Solution sln;
    vector<vector<int> > grid =
       {{0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}};

    vector<vector<int> > grid2 =
                   {{1,1,0,0,0},
                    {1,1,0,0,0},
                    {0,0,0,1,1},
                    {0,0,0,1,1}};

   int max_area = sln.maxAreaOfIsland(grid2);
    cout << "max_area: " << max_area << endl;

    return 0;
}
