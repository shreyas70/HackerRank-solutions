#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*Used DFS. Can use concept of disjoint sets too*/

void dfs(int i, vector<int> *adj,vector<int> &visited, int &count)
{
    if(!visited[i])
    {
        visited[i]=1;
        count++;
        for(auto b:adj[i])
        {
            if(!visited[b])
            {
                dfs(b,adj,visited,count);
            }
        }
    }
}

// Complete the journeyToMoon function below.
long journeyToMoon(int n, vector<vector<int>> astronaut) {

    vector<int> adj[n];

    for(auto i:astronaut)
    {
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }


    // // cout << "Adj list " << endl;

    // for(int i=0;i<n;i++)
    // {
    //     cout << "list of " << i << endl;
    //     for(auto x:adj[i])
    //         cout << x << " ";
    //     cout << endl;
    // }


    vector<int> visited(n,0);
    vector<int> clusters;
    for(int i=0;i<n;i++)
    {
        int count=0;
        if(!visited[i])
        {
            // cout << endl << "DFS on " << i << endl;
            dfs(i,adj,visited,count);
        }
        if(count!=0)
            clusters.push_back(count);
    }

    // cout << clusters.size() << endl;
    // for(auto i:clusters)
    // {
    //     cout << i << " ";
    // }

    long long ans = 0;
    long sum=0;
    for(int i = 0; i < clusters.size(); i++) {
        // if(s[i] != 0) {
            ans += sum*clusters[i];
            sum += clusters[i];
        // }
    }

    // long ans=0;
    // for(int i=0;i<clusters.size();i++)
    // {
    //     for(int j=i+1;j<clusters.size();j++)
    //     {
    //         ans+=clusters[i]*clusters[j];
    //     }
    // }

    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string np_temp;
    getline(cin, np_temp);

    vector<string> np = split_string(np_temp);

    int n = stoi(np[0]);

    int p = stoi(np[1]);

    vector<vector<int>> astronaut(p);
    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> astronaut[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long result = journeyToMoon(n, astronaut);

    fout << result << "\n";

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
