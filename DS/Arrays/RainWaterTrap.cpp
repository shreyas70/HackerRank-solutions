/*
https://leetcode.com/problems/trapping-rain-water/solution/

TC: O(N)
SC: O(N)

*/
int Solution::trap(const vector<int> &A) {
    
    vector<int> left;
    vector<int> right(A.size());
    
    int count = 0;
    
    left.push_back(0);
    int leftMax=A[0];
    for(int i=1;i<A.size();i++)
    {
        leftMax = max(leftMax,A[i]);
        // left[i]=leftMax;
        left.push_back(leftMax);
    }
    
    
    right[A.size()-1]=0;
    int rightMax=A[A.size()-1];
    for(int i=A.size()-2;i>=0;i--)
    {
        rightMax = max(rightMax,A[i]);
        right[i]= rightMax;
    }
    
    for(int i=0;i<A.size();i++)
    {
        if(left[i]>A[i] && right[i]>A[i])
        {
            count += min(left[i],right[i])-A[i];
        }
    }
    return count;
}