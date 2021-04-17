#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    struct node
    {
        char value = '\0';
        vector<int> next_list;
        bool contain_self = false;
        /* data */
        node(char value)
        {
            this->value = value;
        }
    };
    bool isMatch(string s, string p) {
        vector<node> state_list;
        make_state_list(state_list, p);
        for(int i = 0; i < state_list.size(); i++)
        {
            cout << state_list.at(i).value << " : ";
            for(int j = 0; j < state_list.at(i).next_list.size(); j++)
            {
                cout << state_list.at(i).next_list.at(j) << " ";
            }
            cout << endl;
        }
        vector< vector<bool>> DFA(28);
        for(int i = 0; i < DFA.size(); i++)
        {
            for(int j = 0; j < 28; j++)
            {
                DFA.at(i).push_back(false);
            }
        }
        NFA_to_DFA(DFA, state_list);
        for(int i = 0; i < DFA.size(); i++)
        {
            for(int j = 0; j < DFA.at(i).size(); j++)
            {
                if(DFA.at(i).at(j))
                {
                    cout << "1 "; 
                }
                else
                {
                    cout << "0 ";
                }
                
            }
            cout << endl;
        }
        return true;
        // return dfs(state_list, 0, s, 0);
    }
    bool dfs(vector<node> tem_state_list, int tem_state_list_i, const string s, int tem_s_i)
    {
        node get_current_node = tem_state_list.at(tem_state_list_i);
        if(tem_s_i == s.size())
        {
            for(int i = 0; i < get_current_node.next_list.size(); i++)
            {
                int get_tem_next_serial = get_current_node.next_list.at(i);
                if(tem_state_list.at(get_tem_next_serial).value == 'E')
                {
                    return true;
                }
            }
            return false;
        }
        for(int i = 0; i < get_current_node.next_list.size(); i++)
        {
            int get_tem_next_serial = get_current_node.next_list.at(i);
            if((tem_state_list.at(get_tem_next_serial).value == s[tem_s_i] || tem_state_list.at(get_tem_next_serial).value == '.') 
                && dfs(tem_state_list, get_tem_next_serial, s, tem_s_i + 1))
            {
                return true;
            }
        }
        return false;
    }
    bool dfs_DFA()
    void make_state_list(vector<node> &state_list, const string p)
    {
        node start_node = node('a' - 1);
        state_list.push_back(start_node);
        for(int i = 0; i < p.length(); i++)
        {
            if((p[i] >= 'a' && p[i] <= 'z') || p[i] == '.')
            {
                node tem_node = node(p[i]);
                state_list.push_back(tem_node);
                state_list.at(state_list.size() - 2).next_list.push_back(state_list.size() - 1);
            }
            else if(p[i] == '*')
            {
                state_list.at(state_list.size() - 1).next_list.push_back(state_list.size() - 1);
                state_list.at(state_list.size() - 1).contain_self = true;
            }
        }
        node end_node = node('z' + 1);
        state_list.push_back(end_node);
        state_list.at(state_list.size() - 2).next_list.push_back(state_list.size() - 1);
        for(int i = 0; i < state_list.size(); i++)
        {
            int j = 1;
            while(i + j < state_list.size() && state_list.at(i + j).contain_self)
            {
                state_list.at(i).next_list.push_back(i + j + 1);
                j++;
            }
        }
    }
    void NFA_to_DFA(vector< vector<bool>> &DFA, vector<node> state_list)
    {
        for(int i = 0; i < state_list.size(); i++)
        {
            for(int j = 0; j < state_list.at(i).next_list.size(); j++)
            {
                int next_serial = state_list.at(i).next_list.at(j);
                cout << "next_serial : " << next_serial << endl;
                DFA.at(state_list.at(i).value - 'a' + 1).at(state_list.at(next_serial).value - 'a' + 1 ) = true;
            }
        }
    }
};
int main()
{
    Solution a;

    cout << a.isMatch("aaaaaaaaaaaaab", "a*a*a*a*a*a*a*a*a*a*c");
}
