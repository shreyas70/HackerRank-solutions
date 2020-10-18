//  https://www.interviewbit.com/problems/permutations/
// TC: n!
void permuteHelper(vector<vector<int> > &result, set<int> available, vector<int> &single, int length)
{

    if(length==single.size())
    {
        vector<int> copy;
     
        for(int i:single)
        {
            copy.push_back(i);
        }

        result.push_back(copy);
        return;
    }
    
    vector<int> test;
    
    for(int i:available)
        test.push_back(i);
    
    if(!available.empty())
    for(int i : test)
    {
        available.erase(i);
        single[length]=i;
        permuteHelper(result, available, single,length+1);
        available.insert(i);
    }
    return;
    
}

vector<vector<int> > Solution::permute(vector<int> &A) 
{
    vector<vector<int>> result;
    vector<vector<int>> result1;
    vector<int> single(A.size(),-1);
    set<int> available;
    for(int i:A)
    {
        available.insert(i);
    }
    
    permuteHelper(result,available,single,0);
    return result;
}