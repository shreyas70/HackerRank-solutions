#include <bits/stdc++.h>

using namespace std;

//  determine and report the shortest distance to each of the other nodes from a given starting position using the breadth-first search algorithm (BFS). 

vector<string> split_string(string);

vector<int> bfs(int n, int m, vector<vector<int>> edges, int s)
{
    // vector< vector<int> > adj(n);

    vector<int> adj[n+1];

    for( auto x:edges)
    {
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }


    queue<int> q;
    q.push(s);
    q.push(-1);
    vector<int> visited(n+1,0);
    vector<int> distance(n+1,-1);
    distance[s]=0;
    int count=0;

    while(!q.empty())
    {
        int node = q.front();
        // cout << " popped " << node << endl;
        q.pop();

        if(node==-1)
        {
            count++;
            // cout << " count incr " << endl;
            // cout << " next elem in queue " << q.front() << endl;
            if(!q.empty() || q.front()==-1)
                q.push(-1);
            // cout << " pushing -1 " << endl;
            
            continue;
        }

        if(visited[node]==0)
        {
            visited[node]=1;
            distance[node]=count;
            for(auto edge:adj[node])
            {
                if(visited[edge]==0)
                {
                    q.push(edge);   
                    // cout << " pushing " << edge << endl;
                }
            }
        }
    }

    distance.erase(distance.begin()+s);
    distance.erase(distance.begin());
   
    for(int i=0;i<distance.size();i++)
    {
        if(distance[i]!=-1)
            distance[i]=distance[i]*6;
    }

    return distance;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        int n = stoi(nm[0]);

        int m = stoi(nm[1]);

        vector<vector<int>> edges(m);
        for (int i = 0; i < m; i++) {
            edges[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> edges[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int s;
        cin >> s;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<int> result = bfs(n, m, edges, s);

        for (int i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
