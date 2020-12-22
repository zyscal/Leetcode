#include<queue>
#include<vector>
#include<iostream>
using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */

    double mid;
    priority_queue<int> maxque;
    priority_queue<int, vector<int>, greater<int>> minque;
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(maxque.empty() && minque.empty())
        {
            mid = num;
            maxque.push(num);
            return;
        }
        if(maxque.size() == minque.size())
        {
            if(num <= mid)
            {
                maxque.push(num);
                mid = maxque.top();
            }
            else
            {
                minque.push(num);
                mid = minque.top();
            }
        }
        else if(maxque.size() > minque.size())
        {
            if(num <= mid)
            {
                maxque.push(num);
                minque.push(maxque.top());
                maxque.pop();
                mid = ((double)maxque.top() + (double)minque.top()) / 2;
            }
            else
            {
                minque.push(num);
                mid = (mid + (double)minque.top()) / 2;
            }
        }
        else
        {
            if(num <= mid)
            {
                maxque.push(num);
                mid = (mid + (double)maxque.top()) / 2;
            }
            else
            {
                minque.push(num);
                maxque.push(minque.top());
                minque.pop();
                mid = ((double)maxque.top() + (double)minque.top()) / 2;
            }   
        }
    }
    
    double findMedian() {
        return mid;
    }
};