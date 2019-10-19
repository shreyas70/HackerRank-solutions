#include <bits/stdc++.h>

using namespace std;

// Complete the superReducedString function below.
string superReducedString(string s) {

    // string ans="";
    int flag;
    do
    {
        flag=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==s[i+1] && i!=s.length()-1)
            {
                s.erase(i,1);
                s.erase(i,1);
                i--;
                flag=1;
            }

        }
    }while(flag==1);
    if(s.compare("")==0)
        return "Empty String";
    else
        return s;


}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = superReducedString(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
