/*
https://leetcode.com/problems/sliding-window-maximum/

TC: O(n)
SC: O(windowSize)
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& A, int B) {
        
    /*
    Core idea is to only keep the 'promising' elements of the window 
    in a double ended queue
    
    window = 100 50 60 30 40 => dqueue = 100 60 40
    */
        
    deque<pair<int,int>> dq;
    vector<int> result;
 
    for(int i=0;i<A.size();i++)
    {
        // remove elements out of the window
        while(!dq.empty() && dq.front().second < (i-B+1)) dq.pop_front();
    
        // remove elements useless in the window
        while(!dq.empty() && dq.back().first<A[i])
        {
            dq.pop_back();
        }
        
        // push the next element
        dq.push_back(make_pair(A[i],i));
        
        // update answer for this window
        if(i>=(B-1))
        {
            result.push_back(dq.front().first);
            
        }
    }

    return result;
        
    }
};