#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * 动态规划思想，
 * 字符串a -> horse 和 字符串b -> ros
 * 
 * i指向horse最开始，j指向ros最开始
 * 1、当a[i] == b[j]时候，map[i][j] = map[i + 1][j + 1]
 * 2、当a[i] != b[j]是否：
 *      选择一：将a[i]替换为b[j]，所以map[i][j] = 1 + map[i + 1][j + 1]
 *      选择二：将a[i]删除，所以map[i][j] = 1 + map[i + 1][j]
 *      选择三：在a[i]前插入b[j],所以map[i][j] = 1 + map[i][j + 1]
 *      两种选择选择最小的即可
 * 值得注意的是，在建立map时候，需要在竖列多加一列一行，标识从horse换到空字符串的操作数。
 */
class Solution {
public:
    int minDistance(string word1, string word2) {
        int lengthOfWord1 = word1.size();
        int lengthOfWord2 = word2.size();
        vector<vector<int>> wordMap(lengthOfWord1 + 1);
        // map初始化
        for(int i = 0; i < wordMap.size(); i++) {
            wordMap.at(i).resize(lengthOfWord2 + 1, 0);
        }
        // 建立最后一列
        for(int i = 0; i < lengthOfWord1; i++) {
            wordMap.at(i).at(lengthOfWord2) = lengthOfWord1 - i;
        }
        // 建立最底下一行
        for(int j = 0 ; j < lengthOfWord2; j++) {
            wordMap.at(wordMap.size() - 1).at(j) = lengthOfWord2 - j;
        }
        // 填充
        for(int i = lengthOfWord1 - 1; i >= 0; i--) {
            for(int j = lengthOfWord2 - 1; j >= 0; j--){
                if(word1.at(i) == word2.at(j)) {
                    wordMap.at(i).at(j) = wordMap.at(i + 1).at(j + 1);
                } else {
                    wordMap.at(i).at(j) = min (
                        wordMap.at(i + 1).at(j + 1),
                        wordMap.at(i + 1).at(j)
                    ) + 1;
                    wordMap.at(i).at(j) = min (
                        wordMap.at(i).at(j),
                        wordMap.at(i).at(j + 1) + 1
                    );
                }
            }
        }
        for(int i = 0; i < wordMap.size(); i++) {
            for(int j = 0; j < wordMap.at(0).size(); j++) {
                cout << wordMap.at(i).at(j) << " ";
            }
            cout << endl;
        }
        return wordMap.at(0).at(0);
    }
};
int main() {
    Solution a;
    cout << a.minDistance("park", "spake");
}