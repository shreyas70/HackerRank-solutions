/*
Minimum number of characters that need to be added in the beginning to make covert string to palindrome
*/
int Solution::solve(string A) {
    
    string B=A+"$";
    reverse(A.begin(),A.end());
    B=B+A;
    vector<int> Z(B.length(),0);
    
    int left=0,right=0;
    
    for(int i=1;i<Z.size();i++)
    {
        if(i>right)
        {
            
            left=right=i;
            
            while(right<Z.size() && B[right]==B[right-left])
                right++;
            
            Z[i] = right-left;
            right--;
        }
        else
        {
            int i1 = i-left; //coresponding char in beginning
            if(Z[i1]+i<right)
            {
                Z[i]=Z[i1];
            }
            else
            {
                left=i;
                while(right<Z.size() && B[right]==B[right-left])
                    right++;
                    
                Z[i]=right-left;
                right--;
            }
        }
        
        if(Z[i]+i==Z.size())
        {
            return A.length()-Z[i];
        }
        
    }
    return A.length()-1;
    
}
