#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int la = a.length();
        int lb = b.length();
        int lmax = max(la, lb);
        string result(lmax, '0');

        int ia = la-1;
        int ib = lb-1;
        int i = lmax-1;
        int carry = 0;

        while(ia>=0 && ib>= 0)
        {
            result[i] = ((a[ia]-'0') ^ (b[ib]-'0') ^ (carry-'0'))+'0';
            carry = (a[ia]=='1' && b[ib]=='1');
            ia--;
            ib--;
            i--;
        }
        if(carry)
            result.insert(result.begin(), '1');

        return result;
    }
};

int main(int argc, char *argv[])
{
    string a("111");
    string b("111");
    Solution sln;
    string c = sln.addBinary(a, b);
    cout << c << endl;
    return 0;
}
