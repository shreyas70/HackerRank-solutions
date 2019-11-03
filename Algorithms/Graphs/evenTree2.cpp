#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



void dfs(int node, vector<int> &t_from, vector<int> &t_to,vector<int> &visited, int &count)
{
    if(visited[node])
        return;
    
    visited[node]=1;
    count++;

    for(int i=0;i<t_from.size();i++)
    {
        if(t_from[i]==node)
        {
            dfs(t_to[i],t_from,t_to,visited,count);
        }
        else if(t_to[i]==node)
        {
            dfs(t_from[i],t_from,t_to,visited,count);
        }

    }
}
int countNodes(int node, vector<int> &t_from, vector<int> &t_to,int t_nodes)
{
    vector<int> visited(t_nodes+1,0);
    visited[0]=1;
    // visited[node]=1;
    int count=0;

    dfs(node,t_from,t_to,visited,count);
    return count;
}



// Complete the evenForest function below.
int evenForest(int t_nodes, int t_edges, vector<int> t_from, vector<int> t_to) 
{
    int countRemoved=0;
    for(int i=0;i<t_from.size();i++)
    {
        int from = t_from[i];
        int to = t_to[i];
        // t_from.erase(t_from.begin() + i);
        // t_to.erase(t_to.begin() + i);
        t_from[i]=0;
        t_to[i]=0;
        int c1 = countNodes(from,t_from,t_to,t_nodes);
        int c2 = countNodes(to,t_from,t_to,t_nodes);
        if(c1%2==0 && c2%2==0)
        {
            countRemoved++;
        }
        else
        {
            t_from[i]=from;
            t_to[i]=to;
        }
    }
    return countRemoved;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    // freopen("input.txt","r",stdin);


    string t_nodes_edges_temp;
    getline(cin, t_nodes_edges_temp);

    vector<string> t_nodes_edges = split(rtrim(t_nodes_edges_temp));

    int t_nodes = stoi(t_nodes_edges[0]);
    int t_edges = stoi(t_nodes_edges[1]);

    vector<int> t_from(t_edges);
    vector<int> t_to(t_edges);

    for (int i = 0; i < t_edges; i++) {
        string t_from_to_temp;
        getline(cin, t_from_to_temp);

        vector<string> t_from_to = split(rtrim(t_from_to_temp));

        int t_from_temp = stoi(t_from_to[0]);
        int t_to_temp = stoi(t_from_to[1]);

        t_from[i] = t_from_temp;
        t_to[i] = t_to_temp;
    }

    int res = evenForest(t_nodes, t_edges, t_from, t_to);

    fout << res << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
