#include <iostream>
#include<climits>
#include<string>
using namespace std;
class Solution {
public:
    int strToInt(string str) {
        int pos = 0;
        bool positive = true;
        int64_t ans = 0;
        while (pos < str.size() && str[pos] == ' ')
        {
            pos++;
            /* code */
        }
        if(pos == str.size())
        {
            return 0;
        }
        else if(is_normal_char(str[pos]))
        {
            return 0;
        }

        if(str[pos] == '-')
        {
            positive = false;
            pos++;
        }
        else if(str[pos] == '+')
        {
            pos++;
        }
        while(pos < str.size() && str[pos] >= '0' && str[pos] <= '9')
        {
            if(positive)
            {
                ans *= 10;
                ans += str[pos] - '0';
                if(ans > INT32_MAX)
                {
                    return INT32_MAX;
                }
            }
            else
            {
                ans *= 10;
                ans -= str[pos] - '0';
                if(ans < INT32_MIN)
                {
                    return INT32_MIN;
                }
            }
            pos ++;
        }

        return ans;
        
    }
    bool is_normal_char(char a)
    {
        if(a == '+' || a == '-')
        {
            return false;
        }
        if(a >= '0' && a <= '9')
        {
            return false;
        }
        return true;
    }
};
int main()
{
    Solution a;
    cout << a.strToInt("");
}