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

        int aa, bb;
        for(; i>=0; i--, ia--,ib--)
        {
            if(ia >=0 ) {
                aa = a[ia]-'0';
            }else {
                aa = 0;
            }

            if(ib >=0 ) {
                bb = b[ib]-'0';
            }else {
                bb = 0;
            }

            result[i] = (aa ^ bb ^ carry)+'0';
            carry = (aa+bb+carry) >1;

            cout<<"i:" << i<< "\tia:" << ia << "\tib:" << ib
                <<"\ta:" <<a[ia] << "\tb:" << b[ib] << "\tresult:" << result[i]
                << "\tcarry: " << carry << endl;

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
