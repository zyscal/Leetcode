#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        vector<pair<int, int>> maxHeight; // 存储最高点的位置, pair<最高点值，最高点位置>
        maxHeight.push_back(make_pair(-1, -1));
        int area = 0; // 统计柱子面积
        for(int i = 0; i < height.size(); i++) {
            if(height.at(i) > maxHeight.at(0).first) {
                maxHeight.clear();
                maxHeight.push_back(make_pair(height.at(i), i));
            }else if(height.at(i) == maxHeight.at(0).first) {
                maxHeight.push_back(make_pair(height.at(i), i));
            }
            area += height.at(i);
        }
        // 从左向右遍历
        int leftarea = 0;
        int leftmin = height.at(0);
        int leftpos = 0;
        for(int i = 0; i <= maxHeight.at(0).second; i++) {
            if(height.at(i) > leftmin) {
                leftarea += leftmin * (i - leftpos);
                leftpos = i;
                leftmin = height.at(i);
            }
        }

        int rightarea = 0;
        int rightmin = height.at(height.size() - 1);
        int rightpos = height.size() - 1;
        for(int i = height.size() - 1; i >= maxHeight.at(maxHeight.size() - 1).second; i--) {
            if(height.at(i) > rightmin) {
                rightarea += (rightpos - i) * rightmin;
                rightmin = height.at(i);
                rightpos = i;
            }
        }

        int midarea = (maxHeight.at(maxHeight.size() - 1).second - maxHeight.at(0).second + 1) * maxHeight.at(0).first;
        return midarea + leftarea + rightarea - area;
    }
};
int main() {
    Solution a;
    vector<int> height = {4};
    cout << a.trap(height);

}