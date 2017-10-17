#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        return process(word1, 0, word2, 0);
    }

    int process(string &word1, int n1, string &word2, int n2)
    {
        if(n1>(int)word1.size()-1) {
            return word2.size()-n2;
        }else if(n2 > (int)word2.size()-1){
            return word1.size()-n1;
        }
        else if(word1[n1] == word2[n2]){
            return process(word1, n1+1, word2, n2+1);
        }
        else{
            int d1 = process(word1, n1+1, word2, n2)+1;
            int d2 = process(word1, n1, word2, n2+1)+1;
            int d3 = process(word1, n1+1, word2, n2+1)+1;
            return min(min(d1,d2),d3);
        }

    }
};

int main(int argc, char *argv[])
{
    string w1("dinitrophenylhydrazine");
    string w2("acetylphenylhydrazine");
    Solution sln;
    cout << sln.minDistance(w1, w2) << endl;
    return 0;
}
