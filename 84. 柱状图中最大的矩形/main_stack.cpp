#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int>pairtype; // 第一个参数为当前的height,第二个参数为vector中的下角标 

struct monotoneStack {
	stack<pairtype> monoStack;
	int maxAns = 0;
	pairtype top(){
			return this->monoStack.top();
	} 
	void pop(){
		if(!empty()){
			this->monoStack.pop();
		}
	}
	void push(pairtype a) {
		int depth = a.second;
		while(!empty() && top().first > a.first){ // 如果不为空
			pairtype topValue = top();
			pop();
			this->maxAns = max(this->maxAns, topValue.first * (a.second - topValue.second));
			depth = min(depth, topValue.second);
		}
		if(!empty() && top().first == a.first) {
			return;
		}
		this->monoStack.push(pairtype(a.first, depth));	
	}
	bool empty() {
		return this->monoStack.empty();	
	}
};

class Solution {
	public:
		
		int largestRectangleArea(vector<int>& heights) {
			monotoneStack RectStack;
			for(int i = 0; i < heights.size(); i++) {
				RectStack.push(pairtype(heights.at(i), i));
			}
			while(!RectStack.empty()){
				pairtype topValue = RectStack.top();
				RectStack.pop();
				RectStack.maxAns = max(RectStack.maxAns, topValue.first * ((int)heights.size() - topValue.second));
			}
			return RectStack.maxAns;
		}
};
int main() {
		Solution a;
		vector<int> test = {5, 5, 1, 7, 1, 1, 5, 2, 7, 6};
		cout << a.largestRectangleArea(test) << endl;

}
