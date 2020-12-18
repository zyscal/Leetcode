#include<string>
#include<iostream>
#include<unordered_map>
using namespace std;
enum state{
    CKG,
    ZSF1,
    ZSF2,
    ZSW1,
    ZSW2,
    XSD1,
    XSD2,
    XSW,
    eE,
    WKG
};
enum chartype{
    NUMBER,
    SPACE,
    SIGN,
    POINT,
    E,
    EXP
};
unordered_map <state, unordered_map<chartype, state> > statechange
{
    {
        CKG,
            {
                {SPACE,CKG},
                {NUMBER,ZSW1},
                {SIGN,ZSF1},
                {POINT,XSD2}
            }
    },
    {
        ZSF1,
            {
                {NUMBER,ZSW1},
                {POINT,XSD2},
            }
    },
    {
        ZSW1,
            {
                {SPACE,WKG},
                {E,eE},
                {POINT,XSD1},
                {NUMBER,ZSW1}
            }
    },
    {
        XSD2,
            {
                {NUMBER,XSW}
            }
    },
    {
        XSD1,
            {
                {SPACE,WKG},
                {E,eE},
                {NUMBER,XSW}
            }
    },
    {
         XSW,
            {
                {NUMBER,XSW},
                {E,eE},
                {SPACE,WKG}
            }
    },
    {
        eE,
            {
                {SIGN,ZSF2},
                {NUMBER,ZSW2}
            }
    },
    {
        ZSF2,
            {
                {NUMBER,ZSW2}
            }
    },
    {
        ZSW2,
            {
                {NUMBER,ZSW2},
                {SPACE,WKG}
            }
    },
    {
        WKG,
            {
                {SPACE,WKG}
            }
    }
};

chartype chartotype(char a)
{
    if(a >= '0' && a <= '9')
    {
        return NUMBER;
    }
    else if(a == ' ')
    {
        return SPACE;
    }
    else if(a == '+' || a == '-')
    {
        return SIGN;
    }
    else if(a == '.')
    {
        return POINT;
    }
    else if(a == 'e' || a == 'E')
    {
        return E;
    }
    else
    {
        return EXP;
    }
}

bool isNumber(string s) {
    if(s.size() == 0)
    {
        return false;
    }
    state thisstate = CKG;
    for(int i = 0; i < s.size(); i++)
    {
        // chartype thischartype = chartotype(s[i]);
        // auto iter = statechange.find(thisstate);
        // auto iter2 = iter->second.find(thischartype);       
        // if(iter2 == iter->second.end())
        // {
        //     return false;
        // }
        // else
        // {
        //     thisstate = iter2->second;
        // }
        chartype thischartype = chartotype(s[i]);
        if(statechange[thisstate].find(thischartype) != statechange[thisstate].end())
        {
            thisstate = statechange[thisstate][thischartype];
        }
        else
        {
            return false;
        }
        
    }
    if(thisstate == ZSW1 || thisstate == XSD1 || thisstate == XSW || thisstate == ZSW2 || thisstate == WKG)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}
int main()
{
    cout<<isNumber(".");
}