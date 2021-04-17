#include<iostream>
#include<string>
#include<climits>
#include<stdio.h>
#include<vector>
using namespace std;
#define f1(bit, bitmap, i) { \
    int length_of_long = sizeof(long) * 8; \
    int serial = bit / length_of_long; \
    int pos = bit % length_of_long;\
    unsigned long get_long = bitmap[serial]; \
    int move = pos; \
    i = get_long & (1 << move);\
} \


bool f1_1 (int bit, unsigned long *bitmap)
{
    /** 0123 4567 
     *  0100 0000
     * 
     * 
     */
    int length_of_long = sizeof(long) * 8;
    int serial = bit / length_of_long;
    int pos = bit % length_of_long;
    unsigned long get_long = bitmap[serial];
    int move = pos;
    return get_long & (1 << move);
}

int f12_2(string &input)
{
    int front = 0;
    int back = 0;
    int ans = 0;
    for(int i = 0 ; i < input.length(); i++)
    {
        if(input[i] != ' ')
        {
            input[front] = input[back];
            back++;
            front++;
        }
        else
        {
            ans++;
            back++;
        }
    }
    input.resize(front);
    return ans;
}


int f12(string &input)
{
    string ans = "";
    int number = 0;
    for(int i = 0; i < input.length(); i++)
    {
        if(input[i] == ' ')
        {
            number++;
        }
        else
        {
            ans += input[i];
        }
    }
    input = ans;
    return number;
}

long double pow_2(long double a, int b)
{
    if(b < 0)
    {
        return 1/pow_2(a, -b);
    }
    else if(b == 0)
    {
        return 1;
    }
    if(b == INT32_MIN)
    {
        b = b + 1;
        long double tem = 1 / pow_2(a, -b);
        return tem / a;
    }
    long double tem_ans = 1;
    while (b != 1)
    {
        if(b % 2 == 0)
        {
            a = a * a;
            b = b / 2;
        }
        else
        {
            tem_ans = tem_ans * a;
            b = b - 1;
        }
    }
    return tem_ans * a;
}


double pow(double a, int b)
{
    if(b == 0)
    {
        return 1;
    }
    if(b == 1)
    {
        return a;
    }
    if(b == INT32_MIN)
    {
        b = b + 1;
        double tem = 1 / pow(a, -b);
        return tem / a;
    }
    if(b < 0)
    {
        return 1/pow(a, -b);
    }
    double tem_ans = pow(a, b / 2);
    if(b % 2 == 0)
    {
        return tem_ans * tem_ans;
    }
    else
    {
        return tem_ans * tem_ans * a;
    }
    return 0.0;
}


// int main()
// {
//     int a[5][5];
//     cout << a << endl;
//     cout << &a[0][1] << endl;
//     cout << &a[2][2] << endl;
// }

// void GetIntA(int * p)
// {
//     p = malloc(sizeof(int));
//     return;
// }
// int * GetIntB()
// {
//     int kk;
//     return &kk;
// }
// int main(void)
// {
//     int * p;
//     p = NULL; GetIntA(p); *p = 0x22;
//     p = NULL; p = GetIntB(); *p = 0x33;
//     return 0;
// }

// struct
// {
//     int a;
//     char b;
//     short c;
//     double d;
// } Item1;
// struct
// {
//     int a;
//     char b;
//     short c;
//     double d;
//     char e[13];
// } Item2;
// struct 
// {
//     int a;
//     Item1 b;
//     Item2 c;
// } Item3;
unsigned long a[1000];
bool check(unsigned long get_long, int serial)
{
    int length_of_long = sizeof(long) * 8;
    int sum = 0;
    // for(int i = 0; i < length_of_long; i++)
    for(int i = length_of_long - 1; i >= 0; i--)
    {
        int tem_bit = f1_1(serial * length_of_long + i, a);
        sum <<= 1;
        if(tem_bit == 1)
        {
            sum += 1;
        }
    }
    if(get_long == sum)
    {
        return true;
    }
    return false;
}

int main(void) 
{
    // a[0] = 0xffff;
    // int bit = 16;
    // int ans;
    // cout <<  f1_1(bit, a) << endl;
    // bit = 15;
    // // cout <<  f1_1(bit, a);
    // long interval =1000;
    // int sum = 0;
    // for(int i = 0; i < 100; i++)
    // {
    //     a[i] = sum;
    //     sum += interval;
    // }
    // //test
    // for(int i = 0; i < 100; i++)
    // {
    //     if(check(a[i], i) == false)
    //     {
    //         cout << "NO";
    //     }
    // }
    vector<pair<long double, int>> test = {{-5.0, 4}, {-5.0, 1}, {5.0, -3}, {5.0, -1}, {1, 1}, {1, -1}, {1, 0}, {0, 0},{1.1, 2},
    {99, INT32_MAX}};
    for(int i = 0; i < test.size(); i++)
    {
        // cout << "a : " << test.at(i).first << "\tb : " << test.at(i).second 
        // << "\t" << pow_2(test.at(i).first, test.at(i).second) << endl;
    }

    // cout << pow_2(5, 3) << endl;
    // cout << pow_2(5, 1);
    // cout << pow_2(5, -3);
    // cout << pow_2(5, -1);
    // cout << pow_2(1, 1);
    // cout << pow_2(1, -1);




}