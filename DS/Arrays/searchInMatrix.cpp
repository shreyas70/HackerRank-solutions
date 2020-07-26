
// Problem - https://www.geeksforgeeks.org/search-in-row-wise-and-column-wise-sorted-matrix/

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;


bool test(vector<vector<int>> &mat, int num,int row,int col, int m, int n)
{
    // cout << "Checking " << row << ", " << col << " | ";
    
    if(row>=m || col>=n || row < 0 || col<0)
        return false;
        
    if(mat[row][col]==num)
        return true;
    
    if(mat[row][col]>num)
        return test(mat,num,row,col-1,m,n);
    
    if(mat[row][col]<num)
        return test(mat,num,row+1,col,m,n);
}

int main() {
    
    int t,m,n,num;
    
    cin >> t;
    
    while(t--)
    {
        cin >> m >>n;
        
        vector<vector<int>> a;
        for(int i=0;i<m;i++)
        {
            vector<int> b;
            for(int j=0;j<n;j++)
            {
                int temp;
                cin >> temp;
                b.push_back(temp);
            }
            a.push_back(b);
        }
        
        cin >> num;
        
        //  for(int i=0;i<m;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         cout << a[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        
        cout << test(a,num,0,n-1,m,n) << endl;
        
    }
	//code
	return 0;
}