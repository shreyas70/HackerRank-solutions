#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the prims function below.
int prims(int n, vector<vector<int>> edges, int start) {

    int visited_count=0;
    vector<int> visited(n,0);
    vector<int> explored(n,0);
    

    // set< pair< int, pair< int, int > > s;
    set<pair<int, pair<int, int> > > s;

    int node = start;
    int sum = 0;
    int weight = 0;
    while(visited_count!=n || !s.empty())
    {

        /*
            extract from set.
            See if it is are visited, discard.
            otherwise add the new node's neighbours to set and mark it visited
        */
        visited[node]=1;
        visited_count++;
        sum+=weight;
         
        cout << "visited " << node << endl;
        cout << "weight " << weight << endl;
        cout << "stack size " << s.size() << endl;
        cout << "visited count " << visited_count << endl;
        // exploring adding neighbour edges to set

        for(int i=0;i<edges.size();i++)
        {
            if(edges[i][0]==node)
            {
                cout << " edge " << edges[i][1] << endl;
                // if(visited[edges[i][1]]==0)
                // {
                    cout << " inserted " << edges[i][2] << endl;
                    s.insert(make_pair(edges[i][2],make_pair(edges[i][0],edges[i][1])));
                    visited[edges[i][1]]=1;
                // }
            }
            else if(edges[i][1]==node)
            {
                cout << " edge " << edges[i][0] << endl;
                // if(visited[edges[i][0]]==0)
                // {
                    cout << " inserted " << edges[i][2] << endl;
                    s.insert(make_pair(edges[i][2],make_pair(edges[i][1],edges[i][0])));
                    visited[edges[i][0]]=1;
                // }
            }
            explored[node]=1;
        }

        if(visited_count==n)
            break;
        
        int flag = 0;
        while(1)
        {
            if(s.empty())
            {
                flag = 1;
                break;
            }
                
            node = (s.begin())->second.second;
            weight = (s.begin())->first;
            s.erase(s.begin());
            cout << "  popped " << node << endl;
            if(explored[node]==0)
            {
                cout << "  unexplored " << node << endl;
                break;
            }
        }

        if(flag == 1 )
        break;


    }

    return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<vector<int>> edges(m);
    for (int i = 0; i < m; i++) {
        edges[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> edges[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int start;
    cin >> start;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = prims(n, edges, start);

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
