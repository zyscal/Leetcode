#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;
void testUnorderedMap() {
	unordered_map<int, string> test;
	auto insertIter = test.insert(pair<int, string>(1, "11"));
	cout << insertIter.second << " " << insertIter.first->first << " " << insertIter.first->second << endl;	
	auto findIter = test.find(1);
	auto delIter = test.erase(findIter);
	cout << delIter->first << " " << delIter->second << endl;	


}

int main() {
	testUnorderedMap();
}
