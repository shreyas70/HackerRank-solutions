#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
// #include <bits/stdc++.h>
#include <stack>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int t,n,data;
    cin >> t;  
    stack<int> s1,s2;

    while(t--)
    {
        cin >> n;
        switch (n)
        {
            case 1:
                cin >> data;
                s1.push(data);
                break;
            case 2:
                if(s2.empty())
                {
                    while(!s1.empty())
                    {
                        s2.push(s1.top());
                        s1.pop();
                    }
                    s2.pop();
                }
                else
                {
                    s2.pop();
                }
                break;
            case 3:
                if(s2.empty())
                {
                    while(!s1.empty())
                    {
                        s2.push(s1.top());
                        s1.pop();
                    }
                    cout << s2.top() <<endl;
                }
                else
                {
                    cout << s2.top() <<endl;
                }
                break;
        }
    }
    return 0;
}
