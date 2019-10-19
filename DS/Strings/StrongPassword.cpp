#include <bits/stdc++.h>

using namespace std;

// Complete the minimumNumber function below.

bool containsSpecialCharacter(string password)
{
    string special = "!@#$%^&*()-+";
    for(auto i:password)
    {
        if(std::string::npos!=special.find(i))
        {   
            // cout << i << " found special " <<endl;
            return true;
        }
    }

    return false;
}


bool containsUpperCase(string password)
{
    // string special = "!@#$%^&*()-+";
    for(auto i:password)
    {
        if(i >='A' && i <='Z')
            return true;
    }

    return false;
}

bool containsLowerCase(string password)
{
    // string special = "!@#$%^&*()-+";
    for(auto i:password)
    {
        if(i >='a' && i <='z')
            return true;
    }

    return false;
}

bool containsNumber(string password)
{
    // string special = "!@#$%^&*()-+";
    for(auto i:password)
    {
        if(i >='0' && i <='9')
            return true;
    }

    return false;
}



int minimumNumber(int n, string password) {
    // Return the minimum number of characters to make the password strong
    bool s = !containsSpecialCharacter(password);
    bool u = !containsUpperCase(password);
    bool l = !containsLowerCase(password);
    bool nn = !containsNumber(password);

    // cout << s << u << l << nn <<endl;

    return max((s+u+l+nn),(int)(6-password.size()));

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

    fout.close();

    return 0;
}
