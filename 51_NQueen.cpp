#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
       vector<int> chessboard(64, 0);
	   setHere(0,0,chessboard);
	   for (int i = 0; i < 64; i++)
	   {
		   cout << chessboard[i];
		   if (i%8 == 7)
		   {
				cout << endl;
		   }
	   }
	   return vector<vector<string>>(); 
    }

	void setHere(int x, int y, vector<int> &chessboard)
	{
		for (int i = 0; i < 8; i++)
		{
			chessboard[x+i*8]++;
		}
		for (int i = 0; i < 8; i++)
		{
			chessboard[8*y+i]++;
		}
		
		int index = y*8+x;
		chessboard[index]--;

		int indexTmp = index;
		//Ð±Ïß 
		while (indexTmp-9 >=0 )
		{
			indexTmp = indexTmp-9;
			chessboard[indexTmp]++;
		}
		indexTmp = index;
		while(indexTmp+9 <= 63)
		{
			indexTmp += 9;
			chessboard[indexTmp]++;
		}
		indexTmp = index;
		while (indexTmp-7 >= 0)
		{
			indexTmp = indexTmp-7;
			chessboard[indexTmp]++;
		}
		indexTmp = index;
		while(indexTmp+7 <= 63)
		{
			indexTmp += 7;
			chessboard[indexTmp]++;
		}
	}
};

/*
int main()
{
	Solution sln;
	sln.solveNQueens(0);
	system("PAUSE");
	return 0;
}
*/