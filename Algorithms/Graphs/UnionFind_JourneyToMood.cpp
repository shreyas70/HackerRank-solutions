#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the journeyToMoon function below.

void initialize (vector<int> &arr, vector<int> &size, int n)
{
    for(int i=0;i<n;i++)
    {
        arr[i]=i;
        size[i]=1;
    }
}

int root(vector<int> &arr, int n)
{
    // cout << "Root of " << n << endl;
    while(arr[n]!=n)
    {
        n=arr[n];
    }
    // cout << n << endl;
    return n;
}


int find(vector<int> &arr, int a, int b)
{
    if(root(arr,a)==root(arr,b))
        return 1;
    else
        return 0;
}

void union_nodes(vector<int> &arr, vector<int> &size, int a, int b)
{
    if(find(arr,a,b))
        return;
    
    if(size[root(arr,a)]>size[root(arr,b)])
    {
        cout << size[root(arr,a)] << " + " << size[root(arr,b)] << endl;
        size[root(arr,a)]+=size[root(arr,b)];
        arr[root(arr,b)]=root(arr,a);
        // cout << "Setting " << root(arr,b) << " to " << root(arr,a) << endl;
        
    }
    else
    {
        cout << size[root(arr,b)] << " + " << size[root(arr,a)] << endl;
        size[root(arr,b)]+=size[root(arr,a)];
        arr[root(arr,a)]=root(arr,b);
    }
}



long journeyToMoon(int n, vector<vector<int>> astronaut)
{
    vector<int> size(n,0);
    vector<int> arr(n,0);
    initialize(arr,size,n);

    for(auto edge:astronaut)
    {
        // for(auto i:arr)
        // {
        //     cout << i << " ";
        // }
        //     cout << endl;
        // for(auto i:size)
        // {
        //     cout << i << " ";
        // }
        // cout << endl;
        // cout << "Calling union " << edge[0] << " " << edge[1] << endl;
        union_nodes(arr,size,edge[0],edge[1]);
    }

    // for(auto i:arr)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    // for(auto i:size)
    // {
    //     cout << i << " ";
    // }


    vector<int> clusters;

    for(int i=0;i<arr.size();i++)
    {
        if(i==arr[i])
        {
            clusters.push_back(size[i]);
        }
    }

    // cout <<  endl << "clusters ";

    // for(auto i:clusters)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    long sum=0;
    long ans=0;

    for(int i=0;i<clusters.size();i++)
    {
        ans+=sum*clusters[i];
        sum+= clusters[i];
    }
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
