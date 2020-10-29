
/*
https://www.interviewbit.com/problems/repeating-subsequence/
*/

int r(string &A,int i,int j)
{
    if(i>=A.size() || j>=A.size())
        return 0;
        
    if(A[i]==A[j])
        return 1+r(A,i+1,j+1);
    else
        return max(r(A,i,j+1),r(A,i+1,j+1));
}
int Solution::anytwo(string A) {
    
    int result = r(A,0,1);
    if(result>1)
        return 1;
    else 
        return 0;
}
