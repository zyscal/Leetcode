    #include<iostream>//剪枝很关键//临界处理很重要
    #include<algorithm>
    #include<math.h>
    #include<unordered_map>
    using namespace std;
    typedef pair<long long ,long long> pairtype;
    unordered_map<long long ,long long> dp;
    long long leastOPs(int x, int target)
    {
        auto iter = dp.find(target);
        if(iter != dp.end())
        {
            return iter->second;
        }
        if(target < x)
        {
            auto iter = dp.insert(pairtype(target , min(2 * target - 1 , 2 * (x - target))));
            return iter.first->second;//insert返回的迭代器中first指向的是pair中存放的内容，second为bool类型。
        }
        if(target == x)
        {
            auto iter = dp.insert(pairtype(target , 0));
            return iter.first -> second;
        }
        long long count = 1 + log10(target) / log10(x);
        long long temmi = pow(x,count);
        if(temmi/x == target)
        {
            auto iter = dp.insert(pairtype(target , count - 2));
            return iter.first->second;
        }

        cout<<"target:"<<target<<" count："<<count<<endl;
        //count大一点 count-1小一点

        long long jian = 999999;
        if(temmi - target < target)
            jian = leastOPs(x,temmi - target);
        long long jia = leastOPs(x,target - temmi / x);


        auto iter2 = dp.insert(pairtype(target , min(jia + count - 1, jian + count)));
        cout<<"target : "<<target<<" dp : "<<iter2.first->second<<endl;
        return iter2.first -> second;
    }


    int leastOpsExpressTarget(int x, int target) {
        
        return leastOPs(x, target);
        
    }
    int main()
    {
        cout<<leastOpsExpressTarget(11,500041);

        return 0;
    }