#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'kruskals' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts WEIGHTED_INTEGER_GRAPH g as parameter.
 */

/*
 * For the weighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] and <name>_to[i]. The weight of the edge is <name>_weight[i].
 *
 */


int root(int a,vector<int> arr)
{
    if(arr[a]==a)
        return a;
    else
    {
        arr[a]=arr[arr[a]];
        return root(arr[a],arr);
    }
        
}



 int find(int a,int b,vector<int> &arr)
 {
    if(root(a,arr)==root(b,arr))
        return 1;
    else 
        return 0;
 }


 void unionn(int a, int b, vector<int> &arr)
 {
     int a_root = root(a,arr);
     arr[a_root]=root(b,arr);
    return;
 }



bool sortvec(vector<int> a, vector<int> b)
{
    return a[0] < b[0];
}


int kruskals(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight)
{
    vector< vector<int> > v;
    
    for(int i=0;i<g_from.size();i++)
    {
        vector<int> h = {g_weight[i],g_from[i],g_to[i]};
        v.push_back(h);
    }

    sort(v.begin(),v.end(),sortvec);

    vector<int> arr(g_nodes+1);
    int count=0;
    for(int i=0;i<arr.size();i++)
        arr[i]=i;

    for(int i=0;i<v.size();i++)
    {
        if(find(v[i][1],v[i][2],arr))
            continue;
        else
        {
            cout << v[i][1] << " " << v[i][2] << endl;
            unionn(v[i][1],v[i][2],arr);
            count+=v[i][0];
        }
        // cout << v[i][0] << " " << v[i][1] << " " << v[i][2] << endl;

    }
    cout << count << endl;

    return count;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string g_nodes_edges_temp;
    getline(cin, g_nodes_edges_temp);

    vector<string> g_nodes_edges = split(rtrim(g_nodes_edges_temp));

    int g_nodes = stoi(g_nodes_edges[0]);
    int g_edges = stoi(g_nodes_edges[1]);

    vector<int> g_from(g_edges);
    vector<int> g_to(g_edges);
    vector<int> g_weight(g_edges);

    for (int i = 0; i < g_edges; i++) {
        string g_from_to_weight_temp;
        getline(cin, g_from_to_weight_temp);

        vector<string> g_from_to_weight = split(rtrim(g_from_to_weight_temp));

        int g_from_temp = stoi(g_from_to_weight[0]);
        int g_to_temp = stoi(g_from_to_weight[1]);
        int g_weight_temp = stoi(g_from_to_weight[2]);

        g_from[i] = g_from_temp;
        g_to[i] = g_to_temp;
        g_weight[i] = g_weight_temp;
    }

    int res = kruskals(g_nodes, g_from, g_to, g_weight);

    // Write your code here.
    fout << res << endl;
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
