#include<iostream>
#include<algorithm>
#include<climits>

using namespace std;
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int n, m;
        cin >> n >> m;
        int hangA0 = (2 + (n - 1) * m) * n / 2;
        int hangdd = m;
        int hangAn_1 = hangA0 + (n - 1) * m;
        int minhang = 9999999999;
        int minhangpos = 9999999999;
        for(int j = 0; j < m - 1; j++){
            int hangAdn = hangA0 + j * hangdd;
            int hangAdnPlus1 = hangAdn + hangdd;
            int plus_before = (hangA0 + hangAdn) * (j + 1) / 2;
            int plus_back = (hangAdnPlus1 + hangAn_1) * (m - j - 1) / 2;
            int diff = plus_before - plus_back;
            if( diff < 0){
                diff = diff * -1;
            }
            if(minhang > diff){
                minhang = diff;
                minhangpos = j + 2;
            }
        }
        int sumhang = (hangA0 + hangAn_1) * m / 2;
        if (sumhang <= minhang)
        {
            minhang = sumhang;
            minhangpos = 1;
        }

        int lieA0 = (1 + m) * m / 2;
        int liedd = n * m;
        int lieAn_1 = lieA0 + (m - 1) * n;
        int minlie = 9999999999;
        int minliepos = 9999999999;
        for(int j = 0; j < n - 1; j++){
            int lieAdn = lieA0 + j * liedd;
            int lieAdnPlus1 = lieAdn + liedd;
            int plus_before = (lieA0 + lieAdn) * (j + 1) / 2;
            int plus_back = (lieAdnPlus1 + lieAn_1) * (n - j - 1) / 2;
            int diff = plus_before - plus_back;
            cout << diff << endl;
            if( diff < 0){
                diff = diff * -1;
            }
            if(minlie > diff){
                minlie = diff;
                minliepos = j + 2;
            }
        }
        int sumlie = (lieA0 + lieAn_1) * m / 2;
        if (sumlie <= minlie)
        {
            minlie = sumlie;
            minliepos = 1;
        }
        cout << "minghang " << minhang << endl;
        cout << "minlie " << minlie << endl; 
        if(minhang <= minlie ) {
            cout << "V " << minhangpos << endl;
        }
        else{
            cout << "H " << minliepos << endl;
        }

    }
}