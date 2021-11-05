#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct group
{
    int small_group[5];
};
bool bmp(group a, group b)
{
    return a.small_group[2] < b.small_group[2];
}
void add_list_yu(vector<int> &list, vector<int> &list_ans, int numofgroup, int yu)
{
    if(yu == 0)
    {
        return;
    }
    for(int i = 0; i < yu; i++)
    {
        list_ans.push_back(list[numofgroup * 5 + i]);
    }
    return;
}

int BFPRT(vector<int> list, int k)//第k小问题
{
    int sumnum = list.size();
    if(sumnum <= 5)
    {
        sort(list.begin(), list.end());
        return list[k - 1];
    }
    int numofgroup = sumnum / 5;
    int yu = sumnum - numofgroup * 5;
    vector<group> group_list;
    for(int i = 0; i < numofgroup; i++)
    {
        group temgroup;
        for(int j = 0; j < 5; j++)
        {
            temgroup.small_group[j] = list[5 * i + j];
        }
        sort(temgroup.small_group,temgroup.small_group + 5);
        group_list.push_back(temgroup);
    }
    sort(group_list.begin(), group_list.end(), bmp);
    for(int i = 0; i < numofgroup; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            cout << group_list[i].small_group[j] << " ";
        }
        cout << endl;
    }
    int midrow = numofgroup / 2;
    if(numofgroup % 2 == 0)
    {
        midrow -= 1;
    }
    if((midrow + 1) * 3 >= k)
    {
        vector<int> nextlist;
        for(int i = 0; i <= midrow; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                nextlist.push_back(group_list[i].small_group[j]);
            }
        }
        add_list_yu(list, nextlist, numofgroup, yu);
        return BFPRT(nextlist, k);
    }
    else
    {
        vector<int> nextlist;
        for(int i = 0; i <= midrow; i++)
        {
            for(int j = 3; j < 5; j++)
            {
                nextlist.push_back(group_list[i].small_group[j]);
            }
        }
        for(int i = midrow + 1; i < numofgroup; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                nextlist.push_back(group_list[i].small_group[j]);
            }
        }
        add_list_yu(list, nextlist, numofgroup, yu);
        return BFPRT(nextlist, k - 3 * (midrow + 1));
    }
}

int main()
{
    vector<int> testans = {9,6,5,8,45,66,46,46,1,13,13,1,1,5,64,94,65,7,9,5,46,5,1,3,23,1,56,79,7,5,6,31,31,31,3,2,23,13,13,2,1,31,3};
    int ans = BFPRT(testans,5);
    cout << "ans : " << ans << endl;
    sort(testans.begin(), testans.end());
    for(int i = 0; i < testans.size(); i++)
    {
        cout << testans[i] << " ";
    }

}



/**
* 打印 int 数组中第 3 大的数，和除前 10 个大数以外的所有数字的中位数，数组可能有重复的值，个数少于 100 个。
*
*```java
*int[] arr = [1, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 12, 11, 12, 7, 8, 9, 13, 1]
*int max3 = 11; // 第一大为13，第二大为12，第三大为11
*int medianOfRemains = 2;  // 除前十个大数以外的所有数字是 1 2 3 3 1，中位数是 2。
**/
#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
typedef pair(int, bool) pairtype;
struct node{
	int list[5];
}
void handle_arr(const vector<int> arr, vector<int> &ans)
{
	unordered_map<int, bool> get_ride_of_reap;
  	for(int i = 0; i < arr.size(); i++)
    {
    	if(get_ride_of_reap.find(arr.at(i) == get_ride_of_reap.end()))
        {
        	ans.insert(arr.at(i));
          	get_ride_of_reap.insert(pairtype(arr.at(i), true));
        }
      	else
        {
        	//nothing to do;
        }
    }
  	return;
}

bool cmp(node a, node b)
{
	return a.list[2] < b.list[2];
}
int bfprt(vector<int> arr, int pos){
  	//create map
	vector<node> arr_map(arr.size() / 5);
  	//make map data
  	for(int i = 0; i < arr_map.size() * 5; i++) 
    {
    	arr_map.at(i / 5).list[i % 5] = arr.at(i);
    }
 	//sort every line
  	for(int i = 0; i < arr_map.size(); i++)
    {
    	sort(arr_map.at(i).list, arr_map.at(i).list + 5);
    }
  	//sort the mid of list
  	sort(arr_map.begin(), arr_map.end(), cmp);
  	//get mid of arr
  	int mid = arr_map.at(arr_map.size() / 2).list[2];
  	//split the arr
  	vector<int> left(0);
	vector<int> right(0);
  	for(int i = 0; i < arr.size(); i++)
    {
      	if(arr.at(i) <= mid)
        {
        	left.push_back(arr.at(i));
        }
      	else
        {
        	right.push_back(arr.at(i));
        }
    }
  	//find ans 
  	if(right.size() == pos - 1)
    {
    	return mid;
    }
  	else if(right.size() > pos - 1)
    {
    	return bfprt(right, pos);
    }
  	return bfprt(left, pos - right.size());
}
vector<vector<int> > get_ans(vector<int> arr)
{
  	vector<vector<int> > ans;
	vector<int> with_out_reap(0);
  	handle_arr(arr, with_out_reap);
  	ans.at(0).push_back(bfprt(with_out_reap, 3));
  	
  	int que2 = bfprt(10);
  	for(int i = 0; i < arr.size(); i++)
    {
      	if(arr.at(i) < que2)
        {
        	ans.at(1).push_back(arr.at(i));
        }
    }
  	return ans;
}
int main()
{
  	vector<int> arr = {/**/};
	vector<vector<int> > ans = get_ans;
  	return 0
}





/**
*IP检测：实现一个检测IP是否重复存在的工具，核心方法 isIPExist(String inputIP)，该工具需要满足如下要求：
*a. 时间复杂度为常数级
*b. 工具内部操作完全基于内存不得有网络或文件读取，但初始化加载对象时不受此影响(如构造对象时可从文件中loadip名单列表)
*c. 让此工具所能支持的ip列表数量尽可能大(甚至能否覆盖整个ipv4地址空间),内存占用尽可能小
*d. 此工具可能在多线程环境被使用
*/

#include<iostream>

using 





/**
* 实现如下接口：取出两个list中的差集
* @param list1
* @param list2
* @return 差集元素
*/
public <T extends Comparable<T>> List<T> pickDiff(List<T> list1, List<T> list2){
	
// 	// HashMap<T, Boolean> map_of_list1 = new HashMap<>();
//   	HashMap<T, Boolean> map_of_list2 = new HashMap<>();

// 	for(int i = 0; i < list2.size(); i++)
//     {
//     	map_of_list1.put(list2.get(i), true);
//     }
//   	List<T> ans_list = new List<T>();
  
//   	for(int i = 0; i < list1.size(); i++)
//   	{
//   	if(map_of_list2.containsKey(list1.get(i)))
//   	{
//   	//same , do nothind;
//   	}
//   	else{
//   	ans_list.add(list1.get(i));
//   	}
//   	}
//   	return ans_list;
// }











