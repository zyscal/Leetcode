#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
class Solution {
public:
    struct map_node
    {
        int value;
        map_node *next;
        int bus_id;
        /* data */
    };
    struct queue_node
    {
        int value;
        int tem_ans;
        int bus_id;
        /* data */
    };
    
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target){
        if(source == target)
        {
            return 1;
        }
        unordered_map<int, map_node> map_nodes;
        unordered_map<int, bool> already_been;
        make_map(routes, map_nodes);
        cout << "map_nodes.size() : " ;
        cout << map_nodes.size() << endl;
        // queue<queue_node> ans_list;
        // auto iter = map_nodes.find(source);
        // queue_node the_source;
        // the_source.bus_id = iter->second.bus_id;
        // the_source.tem_ans = 1;
        // the_source.value = source;
        // ans_list.push(the_source);
        // already_been.insert(pair<int, bool>(source, true));
        // while (true)
        // {
        //     queue_node head_node = ans_list.front();
        //     ans_list.pop();
        //     if (head_node.value == target)
        //     {
        //         return head_node.tem_ans;
        //         /* code */
        //     }
            
        //     if(already_been.find(head_node.value) != already_been.end())
        //     {
        //         continue;
        //     }
        //     auto iter2 = map_nodes.find(head_node.value);
        //     map_node * node_p = iter2->second.next;
        //     while(node_p != NULL)
        //     {
        //         if(already_been.find(node_p->value) == already_been.end())
        //         {
        //             queue_node next_queue_node;
        //             next_queue_node.value = node_p->value;
        //             if (node_p->bus_id != head_node.bus_id)
        //             {
        //                 next_queue_node.tem_ans = head_node.tem_ans + 1;
        //                 /* code */
        //             }
        //             else{
        //                 next_queue_node.tem_ans = head_node.tem_ans;
        //             }
        //             next_queue_node.bus_id = node_p->bus_id;
        //         }
        //     }



        //     /* code */
        // }
        return 0;


    }

    void make_map (vector< vector<int>> &routes, unordered_map<int, map_node> &map_nodes)
    {
        for(int i = 0; i < routes.size(); i++)
        {

            for(int j = 0; j < routes[i].size(); j++)
            {
                cout << "map : " << i << " " << j << endl;
                auto iter = map_nodes.find(routes[i][j]);
                if(iter == map_nodes.end())//还没加入
                {
                    cout << "还没加入" << endl;
                    map_node head_node;
                    head_node.value = routes[i][j];
                    head_node.next == NULL;
                    head_node.bus_id = i;
                    map_nodes.insert(pair<int, map_node>(head_node.value, head_node));
                }

                if(j == routes[i].size() - 1)
                {
                    map_node the_first;
                    the_first.bus_id = i;
                    the_first.next = NULL;
                    the_first.value = routes[i][0];
                    add_next(iter->second, the_first);
                    continue;
                }
                map_node next_node;
                next_node.value = routes[i][j + 1];
                next_node.next = NULL;
                next_node.bus_id = i;
                add_next(iter->second, next_node);
            }
        }
    }
    void add_next(map_node &front_node, map_node &next_node)
    {
        map_node *node_p = &front_node;
        while(front_node.next != NULL)
        {
            node_p = node_p->next;
        }
        node_p->next = &next_node;
        cout << "end of add_next" << endl;
    }
};



int main()
{
    Solution a;
    vector< vector<int>> test_list = {{1,2,7},{3,6,7}};
    cout << a.numBusesToDestination(test_list, 1, 6);
}