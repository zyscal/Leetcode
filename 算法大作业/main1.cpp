#include<iostream>
#include<assert.h>
#include<vector>
#include<time.h>
#include<ctime>
using namespace std;

struct node
{
    double x;
    double y;
    // node(double x, double y)
    // {
    //     this->x = x;
    //     this->y = y;
    // }
};
double get_k(node a, node b)//斜率
{
    assert(a.x == b.x);
    return (a.y - b.y) / (a.x - b.x);
}
double get_b(double k, node a)//截距
{
    return a.y - k * a.x;
}
int func_g(node linea, node lineb, node point)
{
    //竖线
    if(linea.x == lineb.x)
    {
        if(point.x == linea.x)//三点共竖线
        {
            return 0;
        }
        if(point.x < linea.x)//点在左边为负数
        {
            return -1;
        }
        else//右边为正
        {
            return 1;
        }
    }
    else
    {
        double k = get_k(linea, lineb);
        double b = get_b(k, linea);
        if(k * point.x + b > point.y)//点在直线下方
        {
            return -1;
        }
        else if(k * point.x + b < point.y)//点在直线上方
        {
            return 1;
        }
        return 0;//三点共线
    }
    
}
bool is_inside(node a, node b, node c, node p)
{
    if(func_g(a, b, p) * func_g(a, b, c) >= 0 
        && func_g(a, c, p) * func_g(a, c, b) >= 0 
        && func_g(b, c, p) * func_g(b, c, a) >= 0)
    {
        return true;
    }
    return false;
}
void make_rand_nodes(vector<node> &nodes, int num_of_nodes)//产生随机点集
{
    srand(time(NULL));
    for(int i = 0; i < num_of_nodes; i++)
    {

        struct node new_node{
            x : (rand() / (RAND_MAX + 1.0)) * 100,
            y : (rand() / (RAND_MAX + 1.0)) * 100
        };
        nodes.push_back(new_node);
    }
    for(int i = 0; i < num_of_nodes; i++)
    {
        cout << nodes.at(i).x << " " << nodes.at(i).y << endl;
    }
}
vector<node> BruteForceCH(vector<node> const &nodes)
{
    clock_t start_time, end_time;
    start_time = clock();
    vector<node> ans(0);


    
    end_time = clock();
    cout << "the time of BruteFOrceCH : " << end_time - start_time << endl;
    return ans;
}
int main()
{
    vector<node> nodes(0);
    int num_of_nodes;
    cin >> num_of_nodes;
    getchar();
    make_rand_nodes(nodes, num_of_nodes);
    BruteForceCH(nodes);
}