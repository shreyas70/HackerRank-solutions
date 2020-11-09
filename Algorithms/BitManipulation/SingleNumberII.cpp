
/*

https://leetcode.com/problems/single-number-ii/

Easy to read, O(n) time and O(1) space complexity solution

Runtime: 12 ms, faster than 89.65% of C++ online submissions for Single Number II.
Memory Usage: 9.7 MB, less than 93.70% of C++ online submissions for Single Number II.
*/


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int ans=0;
        
        for(int i=0;i<32;i++)
        {
            
            int sum=0;
            for(auto num:nums)
            {
                if(num & 1<<i)
                {
                    sum++;
                }
            }
            //cout << i << " " << sum << endl;
            
            sum=sum%3;
            if(sum)
            {
                ans = ans | (1<<i);
            }
        }
        return ans;
    }
};
