#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct area {
	int height;
	int length;
	area *next;
	area(int h, int l) : height(h), length(l), next(NULL){};
};	

class Solution {
	public:
		int largestRectangleArea(vector<int>& heights) {
			area *head = new area(-1, -1);
			int ans = 0;
			for (int i = 0; i < heights.size(); i++) {
				handlerArea(head, heights.at(i), ans);				
			}	
			return ans;
		}
		void handlerArea(area *head, int height, int &ans) {
			bool check = false;
			area *thisHeight = NULL;
			area *position = head;//存放thisHeight适当位置的前一个
			area *p = head->next;
			area *bp = head;
			
			while(p != NULL) {
				if(p->height < height) {
					p->length += 1;
					ans = max(ans, p->height * p->length);
					cout << " < " <<  height << "pheight " << p->height << "  p->length" << p->length << " " << ans << endl;
					bp = p;
					position = bp;
					p = p->next;
					
				} else if (p -> height == height) {
					p -> length += 1;
					ans = max(ans, height * p->length);

					cout << " == " <<  height << "pheight " << p->height << "  p->length" << p->length<< " " << ans << endl;
					check = true;
					thisHeight = p;
					bp = p;
					p = p->next;
				} else if (p -> height > height && check) {
					thisHeight->length = max(thisHeight->length, p->length + 1);
					ans = max(ans, p->height * p->length);

					cout << " > true " <<  height << "pheight " << p->height << "  p->length" << p->length<< " " << ans << endl;
					bp->next = p->next;
					p = p->next;
				} else if (p -> height > height && !check) {
					if(thisHeight == NULL) {
						thisHeight = new area(height, 1);
					}
					thisHeight->length = max(thisHeight->length, p->length + 1);
					ans = max(ans, p->height * p->length);
					ans = max(ans, thisHeight->length * thisHeight->height);
					cout << " > false" <<  height  << "pheight " << p->height << "  p->length" << p->length<< " "  << ans << endl;
				   	bp->next = thisHeight;
					bp = thisHeight;
					thisHeight->next = p->next;
					p = p->next;
					check = true;
				}
			}
			if (!check) {
				if (thisHeight == NULL) {
					thisHeight = new area(height, 1);
				}
				bp->next = thisHeight;
				ans = max(ans, height);
				cout << "first" << height << " " << ans << endl;
			}	
			cout << ans << endl;
		}
};

int main () {
	Solution a;
	vector<int> test = {5, 5, 1, 7, 1, 1, 5, 2, 7, 6};
	cout << a.largestRectangleArea(test) << endl;

}
