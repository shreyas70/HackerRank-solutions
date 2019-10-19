//actually DP problem


#include <bits/stdc++.h>

using namespace std;
#define HELLO 1000001
/*
 * Complete the downToZero function below.
 */

int flag=0;
int maxx=1000001;
vector<int> dist(1000001,0);


void precompute()
{
    dist[0]=0;
    dist[1]=1;
    dist[2]=2;
    dist[3]=3;
    dist[4]=3;
    for(int i=1;i<maxx;i++)
    {
        if(dist[i]==0 || dist[i]>dist[i-1]+1)
        {
            dist[i]=dist[i-1]+1;
        }

        // for(int k=0;k<maxx;k++)
        // {
        //     cout << dist[k] << " ";
        // }
        // cout << endl;
        
        for(int j=2; j*i < maxx && j<=i;j++)
        {
            if(dist[j*i] > dist[i]+1 || dist[j*i]==0)
            {
                dist[j*i]=dist[i]+1;
            }
        }

        // for(int k=0;k<maxx;k++)
        // {
        //     cout << dist[k] << " ";
        // }
        // cout << endl;
        // cout << endl;
    }
    flag=1;

}

int downToZero(int n) {

    // if(!flag)
    // {
    //     precompute();
    // }

    // for(int k=0;k<maxx;k++)
    //     {
    //         cout << dist[k] << " ";
    //     }
    //     cout << endl;
    

    return dist[n];
    /*
     * Write your code here.
     */

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
     precompute();
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = downToZero(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
