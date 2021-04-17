int findans(int n, int k, vector< vector<int>> &global_map)
    // {
    //     if(k > 6 * n || k < n)
    //     {
    //         global_map[n][k] = 0;
    //         return 0;
    //     }
        
    //     if(global_map[n][k] != -1)
    //     {
    //         return global_map[n][k];
    //     }

    //     if(n == 1)
    //     {
    //         global_map[n][k] = 1;
    //         return 1;
    //     }
    //     int ans = 0;
    //     for(int i = 1; i <= 6; i++)
    //     {
    //         ans += findans(n - 1, k - i, global_map);
    //     }
    //     global_map[n][k] = ans;
    //     return ans;
    // }