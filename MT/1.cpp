#include<iostream>
#include<string>
using namespace std;
int main()
{
    
    int T;
    cin >> T;
    getchar();
    for(int i = 0; i < T - 1; i++)
    {
        int n;
        cin >> n;
        getchar();
        string s = "";
        for(int i = 0; i < n; i++)
        {
            char tem ;
            cin >> tem;
            s += tem;
        }
        getchar();
        bool once = false;
        bool check = true;
        pair<int, char> change;
        int left, right;
        if(s.length() % 2 == 1)
        {
            left = s.length() / 2;
            right = s.length() / 2;
        }
        else
        {
            left = s.length() / 2 - 1;
            right = left + 1;
        }
        while(left >= 0)
        {
            if(s.at(left) == s.at(right))
            {
                left--;
                right++;
                continue;
            }
            else if(s.at(left) != s.at(right) && once == false)
            {
                if(s.at(left) > s.at(right))
                {
                    change.first = left;
                    change.second = s.at(right);
                }
                else
                {
                    change.first = right;
                    change.second = s.at(left);
                }
                left--;
                right++;
                once = true;
                continue;
            }
            else if(s.at(left) != s.at(right) && once == true)
            {
                left = 0;
                for(; left < s.size(); left++)
                {
                    if(s.at(left) == '0')
                    {
                        continue;
                    }
                    else
                    {
                        s.at(left) = s.at(left) - 1;
                        break;
                    }
                }
                cout << s << endl;
                check = false;
                break;
            }
            left--;
            right++;
        }
        // cout << "check" << check << endl;
        // cout << "once " << once << endl;
        if(check && once == false)
        {
            cout << s << endl;
        }
        else if(check && once)
        {
            s.at(change.first) = change.second;
            cout << s << endl;
        }
    }
                int n;
        cin >> n;
        getchar();
        string s = "";
        for(int i = 0; i < n; i++)
        {
            char tem ;
            cin >> tem;
            s += tem;
        }
        getchar();
        bool once = false;
        bool check = true;
        pair<int, char> change;
        int left, right;
        if(s.length() % 2 == 1)
        {
            left = s.length() / 2;
            right = s.length() / 2;
        }
        else
        {
            left = s.length() / 2 - 1;
            right = left + 1;
        }
        while(left >= 0)
        {
            if(s.at(left) == s.at(right))
            {
                left--;
                right++;
                continue;
            }
            else if(s.at(left) != s.at(right) && once == false)
            {
                if(s.at(left) > s.at(right))
                {
                    change.first = left;
                    change.second = s.at(right);
                }
                else
                {
                    change.first = right;
                    change.second = s.at(left);
                }
                left--;
                right++;
                once = true;
                continue;
            }
            else if(s.at(left) != s.at(right) && once == true)
            {
                left = 0;
                for(; left < s.size(); left++)
                {
                    if(s.at(left) == '0')
                    {
                        continue;
                    }
                    else
                    {
                        s.at(left) = '0';
                        break;
                    }
                }
                cout << s;
                check = false;
                break;
            }
            left--;
            right++;
        }
        // cout << "check" << check << endl;
        // cout << "once " << once << endl;
        if(check && once == false)
        {
            cout << s;
        }
        else if(check && once)
        {
            s.at(change.first) = change.second;
            cout << s ;
        }
    return 0;
}