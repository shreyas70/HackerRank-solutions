
// https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1


void dfs_helper(vector<int> A[], vector<vector<int>> &visited,int row, int col, int N, int M)
{
    if(row < 0 || col <0 || row >= N || col >=M)
        return;        
     
    if(A[row][col]== 1 && visited[row][col]==0)
    {
        visited[row][col]=1;
        // cout << row << ", " << col << " | ";
        dfs_helper(A,visited,row+1,col,N,M);
        dfs_helper(A,visited,row,col+1,N,M);
        dfs_helper(A,visited,row+1,col+1,N,M);
        dfs_helper(A,visited,row+1,col-1,N,M);
        dfs_helper(A,visited,row,col-1,N,M);
        dfs_helper(A,visited,row-1,col+1,N,M);
        dfs_helper(A,visited,row-1,col,N,M);
        dfs_helper(A,visited,row-1,col-1,N,M);
    }
    
    return;
}

int findIslands(vector<int> A[], int N, int M) {
    
    vector<vector<int>> visited(N,vector<int>(M,0));
    
    
    //  for(int i =0;i<N;i++)
    // {
    //     for(int j=0;j<M;j++)
    //     {
    //         cout << A[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    
    int count = 0;
    
    for(int i =0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(A[i][j]==1 && visited[i][j]!=1)
            {
                count++;
                // cout << "DFS on " << i << ", " << j <<endl;
                dfs_helper(A,visited,i,j,N,M);
            }
            // cout << A[i][j] << " ";
        }
        // cout << endl;
    }
    return count;
}
