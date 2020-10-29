/*
https://www.interviewbit.com/problems/edit-distance/
*/
int d(int i, int j, string &A, string &B, vector<vector<int>> &dp)
{
    if(i>=A.length())
    {
        return B.length()-j;
    }
    if(j>=B.length())
    {
        return A.length()-i;
    }
    
    if(dp[i][j]!=-1)
    return dp[i][j];
    
    int ans;
    if(A[i]==B[j])
    {
        ans = d(i+1,j+1,A,B,dp);
    }
    else
    {
        ans = 1+min(d(i+1,j,A,B,dp),min(d(i,j+1,A,B,dp),d(i+1,j+1,A,B,dp)));
    }
    
    dp[i][j]=ans;
    return ans;
}
int Solution::minDistance(string A, string B) {
    
    vector<vector<int>> dp(A.length(),vector<int>(B.length(),-1));
    
    return d(0,0,A,B,dp);
}
