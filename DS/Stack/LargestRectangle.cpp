//https://www.geeksforgeeks.org/largest-rectangle-under-histogram/


#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the largestRectangle function below.
long largestRectangle(vector<int> h) 
{
    stack<int> s;
    long max = 0;

    for(int i=0;i<h.size();i++)
    {
        if(s.empty() || h[i]>=h[s.top()])
        {
            s.push(i);
            cout << "Pushing " << i << endl;
        }
        else
        {
            int cur=s.top();
            s.pop();
            cout << "poped " << cur << endl;
            int prev;
            if(s.empty())
                prev=-1;
            else
                prev=s.top();
            

            cout << "Area : " <<  h[cur] << " * " << i-prev-1 << " = " << h[cur]*(i-prev-1)  << endl;
            // cout << "hello" << endl;
            if( (h[cur]*(i-prev-1)) > max)
                max = h[cur]*(i-prev-1);
            
            i--; //checking same element
        }
    }

    while(!s.empty())
    {
        int cur=s.top();
        s.pop();
        int prev;
        if(s.empty())
            prev=-1;
        else
            prev=s.top();
        cout << "Area : " <<  h[cur] << " * " << h.size()-1-prev << " = " <<  h[cur]*(h.size()-1-prev)  << endl;
        cout << h[cur]*(h.size()-1-prev) << endl;
        if( (h[cur]*(h.size()-1-prev)) > max)
        {
            max = h[cur]*(h.size()-1-prev) ;
            
        }
        else
        {
            cout << "done" << endl;
        }
    }
    
    return (long)max;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string h_temp_temp;
    getline(cin, h_temp_temp);

    vector<string> h_temp = split_string(h_temp_temp);

    vector<int> h(n);

    for (int i = 0; i < n; i++) {
        int h_item = stoi(h_temp[i]);

        h[i] = h_item;
    }

    long result = largestRectangle(h);

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
