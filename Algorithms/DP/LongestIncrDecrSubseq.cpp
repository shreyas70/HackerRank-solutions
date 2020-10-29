/*
https://www.interviewbit.com/problems/length-of-longest-subsequence/

Break the problem into two sub problems - longest incr subseq and longest decr subseq

TC - O(n^2)
SC - O(n)
*/


int solution::longestSubsequenceLength(const vector<int> &A) {
    
    vector<int> incrTill(A.size(),1);
    vector<int> decrFrom(A.size(),1);
    
    for(int i=0;i<A.size();i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            if(A[i]>A[j])
                incrTill[i]=max(incrTill[i],incrTill[j]+1);
        }
    }
    
    for(int i=A.size()-1;i>=0;i--)
    {
        for(int j=i+1;j<A.size();j++)
        {
            if(A[i]>A[j])
                decrFrom[i]=max(decrFrom[i],decrFrom[j]+1);
        }
    }
    
    int result = 0;
    for(int i=0;i<A.size();i++)
        result=max(result,incrTill[i]+decrFrom[i]-1);
        
    return result;
}