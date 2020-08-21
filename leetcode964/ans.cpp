    #include<iostream>//剪枝很关键//临界处理很重要
    #include<algorithm>
    #include<math.h>
    #include<unordered_map>
    #include<limits>
    #include<vector>
    #include<string>
    using namespace std;
    typedef long long ll;
    const ll INF = 1e10;
    ll ans = INF;
    unordered_map<string, ll> memo;
    vector<ll> cost, fac;

    string encode(ll a, ll b) {
        return to_string(a) + "#" + to_string(b);
    }
    
    ll solve(ll target, int limit) {
        string code = encode(target, limit);
        if (memo.find(code) != memo.end())
            return memo[code];
        if (target == 0)
            return 0;
        ll sum = 0;
        ll num = target / fac[limit];
        if (num * cost[limit] >= ans)
            return INF;
        if (limit == 0)
            return num * cost[limit];
        ll left = num * cost[limit] + solve(target - fac[limit] * num, limit - 1);
        ll right = (num + 1) * cost[limit] + solve(fac[limit] * (num + 1) - target, limit - 1);
        return memo[code] = min(left, right);
    }
    int leastOpsExpressTarget(int x, int target) {
        cost.assign(30, 0);
        cost[0] = 2;
        for (int i = 1; i < 30; ++i)
            cost[i] = i;
        fac = {1};
        for (int i = 1; fac.back() < INF; ++i)
            fac.emplace_back(fac.back() * x);
        int limit = 0;
        while (target > fac[limit])
            limit++;
        for (int i = limit; i >= 0; --i)
            ans = min(ans, solve(target, i));
        return ans - 1;
    }
int main()
{








             cout<<leastOpsExpressTarget(11,795);
            // cout<<leastOpsExpressTarget(11,916);
            // cout<<leastOpsExpressTarget(11,2247);

            // cout<<leastOpsExpressTarget(11,16888);
            // cout<<leastOpsExpressTarget(11,177939);
            // cout<<leastOpsExpressTarget(11,338990);
            // cout<<leastOpsExpressTarget(11,500041);

}
