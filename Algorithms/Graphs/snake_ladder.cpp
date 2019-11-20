#include <bits/stdc++.h>

using namespace std;

// Complete the quickestWayUp function below.


/*
Problem : https://www.hackerrank.com/challenges/the-quickest-way-up/problem

Create graph and use bfs. Add 6 edges from each position.

Mark 'special' nodes. Foot of ladder and head of snake. 
They don't add to the number of moves.
*/

int quickestWayUp(vector<vector<int>> ladders, vector<vector<int>> snakes) {
    vector<int> adj[101];
    vector<int> special(101,0);

    for(auto v:ladders)
    {
        adj[v[0]].push_back(v[1]);
        special[v[0]]=1;
    }

    for(auto v:snakes)
    {
        adj[v[0]].push_back(v[1]);
        special[v[0]]=1;
    }


    for(int i=1;i<101;i++)
    {
        if(!special[i])
        {
            adj[i].push_back(i+1);
            adj[i].push_back(i+2);
            adj[i].push_back(i+3);
            adj[i].push_back(i+4);
            adj[i].push_back(i+5);
            adj[i].push_back(i+6);
        }
    }


    queue< pair<int,int> > q;
    vector<int> visited(101,0);
    q.push(make_pair(1,0));
    int minimum = -1;
    while(!q.empty())
    {
        int flag = 0;
        // for()
        auto node = q.front();
        q.pop();

        if(special[node.first])
        {
            int next_node = adj[node.first][0];
            if(next_node==100)
            {
                minimum = node.second;
                break;
            }

            if(!visited[next_node])
            {
                q.push(make_pair(next_node,node.second));
            }

        }
        else
        {
            for(int i=0;i<adj[node.first].size();i++)
            {
                int next_node = adj[node.first][i];

                if(next_node==100)
                {
                    minimum = node.second+1;
                    flag=1;
                    break;
                }

                if(!visited[next_node])
                {
                    visited[next_node]=1;
                    q.push(make_pair(next_node,node.second+1));
                }
            }

            if(flag==1)
                break;
        }
    }

    return minimum;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> ladders(n);
        for (int i = 0; i < n; i++) {
            ladders[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> ladders[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int m;
        cin >> m;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> snakes(m);
        for (int i = 0; i < m; i++) {
            snakes[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> snakes[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int result = quickestWayUp(ladders, snakes);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
