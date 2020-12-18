#include<string>
#include<iostream>
using namespace std;

    string replaceSpace(string s) {
        int lenofs = s.size();
        string ans = "";
        for(int i = 0; i < lenofs; i++)
        {
            if(s.compare(i, 1," ",0,1) == 0)
            {
                ans += "%20";
            }
            else
            {
                ans += s.at(i);
            }
        }
        return ans;
    }
int main()
{

}