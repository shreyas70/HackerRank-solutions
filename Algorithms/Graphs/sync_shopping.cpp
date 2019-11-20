#include <bits/stdc++.h>

using namespace std;

/*

https://www.hackerrank.com/challenges/synchronous-shopping/submissions

23rd test case failing. 

*/

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'shop' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 *  3. STRING_ARRAY centers
 *  4. 2D_INTEGER_ARRAY roads
 */

void printBits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;

    for (i=size-1;i>=0;i--)
    {
        for (j=7;j>=0;j--)
        {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
    puts("");
}

bool Compare(vector<int> a, vector<int> b)
{
    return a[0]>b[0];
}

void relax(int node, int mask, vector< pair<int,int> > *adj,vector< vector<int> > &distance,vector<int> &fish_at_centers,set< pair<int, pair<int,int> > > &S)
{
    // cout << "node " << node << endl;
    for(int i=0;i<adj[node].size();i++)
    {
        
        int to_node = adj[node][i].first;
        // cout << " connected to " << to_node << endl;
        int weight = adj[node][i].second;
        // cout << " weight " << weight << endl;
        // cout << endl;
        int new_mask = mask | fish_at_centers[to_node];
        if(distance[to_node][new_mask]>(distance[node][mask]+weight))
        {
            S.erase(make_pair(distance[to_node][new_mask],make_pair(to_node,new_mask)));
            distance[to_node][new_mask] = (distance[node][mask]+weight);
            auto p = make_pair(to_node,new_mask);
            // vector<int> a = {distance[i][new_mask], i,new_mask};
            // cout << "pushing " << i << endl;

            S.insert(make_pair(distance[to_node][new_mask],p));
        }   
    }
    return;

}


int shop(int n, int k, vector<string> centers, vector<vector<int>> roads) 
{
    vector<int> fish_at_centers(centers.size()+1,0);
    for(int c=0;c<centers.size();c++)
    {
        
        stringstream ss;     
        /* Storing the whole string into string stream */
        ss << centers[c]; 

        /* Running loop till the end of the stream */
        int found; 
        ss >> found; 
        while (!ss.eof()) 
        { 
            ss >> found;
            fish_at_centers[c+1] |= 1<<(found-1);
        } 
        
        // cout << centers[c]<< " ";
        // printBits(sizeof(fish_at_centers[c+1]),&fish_at_centers[c+1]);
        // cout << endl;
    }

    vector< pair<int, int>  > adj[n+1];
    for(auto v:roads)
    {
        adj[v[0]].push_back(make_pair(v[1],v[2]));
        adj[v[1]].push_back(make_pair(v[0],v[2]));
        // cout << adj[v[0]][v[1]] << endl;
    }

    // for(int j=1;j<=n;j++)
    // {
    //     cout << j << " : ";
    //     for(int i=1;i<=n;i++)
    //     {
    //         if(adj[j].find(i)!=adj[j].end())
    //             cout << i << " ";
    //     }
    //     cout << endl;
    // }


    vector< vector<int> > distance(n+1, vector<int>(pow(2,k),INT_MAX));

    // for(auto v:distance)
    // {
    //     for(auto item:v)
    //         cout << item << " ";
    //     cout << endl;
    // }


    set< pair<int, pair<int,int>> > S;
    // priority_queue< vector<int>, vector< vector<int> >, function<bool(vector<int>, vector<int>)> > pq(Compare);

    // vector<int> visited(n+1,0);

    // vector<int> a = {0,1,fish_at_centers[1]};
    auto a = make_pair(0,make_pair(1,fish_at_centers[1]));
    S.insert(a);
    // visited[1]=1;
    distance[1][fish_at_centers[1]]=0;
    // pq.push(make_pair(3,4));

    while(!S.empty())
    {
        auto node = S.begin();
        S.erase(S.begin());
        relax((*node).second.first,(*node).second.second,adj,distance,fish_at_centers,S);
    }

    int minimum=INT_MAX;
    for(int i=0;i<pow(2,k);i++)
    {
        for(int j=i;j<pow(2,k);j++)
        {
            if(distance[n][i]!=INT_MAX && distance[n][j]!=INT_MAX)
            {
                if((i|j)==(pow(2,k)-1))
                {
                    int temp_minimum = max(distance[n][i],distance[n][j]);

                    if(temp_minimum<minimum)
                        minimum = temp_minimum;
                }
            }
        }
    }
    // cout << pq.top().first << endl;

    return minimum;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    int k = stoi(first_multiple_input[2]);

    vector<string> centers(n);

    for (int i = 0; i < n; i++) {
        string centers_item;
        getline(cin, centers_item);

        centers[i] = centers_item;
    }

    vector<vector<int>> roads(m);

    for (int i = 0; i < m; i++) {
        roads[i].resize(3);

        string roads_row_temp_temp;
        getline(cin, roads_row_temp_temp);

        vector<string> roads_row_temp = split(rtrim(roads_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int roads_row_item = stoi(roads_row_temp[j]);

            roads[i][j] = roads_row_item;
        }
    }

    int res = shop(n, k, centers, roads);

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
