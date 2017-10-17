#include <iostream>
#include <string>
#include <assert.h>
#include <math.h>

using namespace std;

class Solution {
    public:
    int mySqrt(int x) {
        if(x<=0 ) return 0;
        double resultf = x/2.0;
        double last_resultf = resultf;
        double diff;
        do {
            last_resultf = resultf;
            resultf = (resultf + x/resultf)/2.f;
            diff = fabs(last_resultf - resultf);
            cout << resultf << endl;
        } while (diff > 0.01);
        return (int)(resultf);
    }
};

int main(int argc, char *argv[])
{
    Solution sln;
    cout << sln.mySqrt(3) <<endl;
    return 0;
}
