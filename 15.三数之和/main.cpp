#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
	public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ans;

		if(nums.size() < 3 ) 	


	 }
	vector<vector<int>> twoSum(vector<int>& nums, int target) {
		vector<vector<int>> ans;
		if (nums.size() <= 1){
			return ans;
		}	
		auto iterBegin = nums.begin();
		auto iterEnd = nums.end() - 1;
		while(iterBegin < iterEnd) {
			if(*iterBegin + *iterEnd == target){
				vector<int> temAns = {*iterBegin, *iterEnd};
				ans.push_back(temAns);
				while (iterBegin < iterEnd - 1) {
					if (*iterBegin == *(iterBegin + 1)) {
						iterBegin++;
					}
					else{
						break;
					}
				}
				while (iterBegin < iterEnd - 1) {
					if(*iterEnd == *(iterEnd - 1)){
						iterEnd--;
					}
					else {
						break;
					}
				}
				iterBegin++;
				iterEnd--;
				
			}
			else if (*iterBegin + *iterEnd < target) {
				iterBegin++;
			}
			else {
				iterEnd--;
			}
		}
		return ans;

	}
};
int main() {
	

}
