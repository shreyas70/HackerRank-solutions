/*

Backtracking solution
*/

class Solution {    
    bool isValid(string s1)
    {
        
        if(s1.length()==0 || s1.length()>3)
            return false;
        
        if(s1[0]=='0' && s1.length()!=1)
            return false;
        
        int num = 0;
        for(int i=0;i<s1.length();i++)
        {
           if(s1[i]<'0' || s1[i]>'9')
               return false;
            // cout << num << " ";
            num = num*10+((s1[i]-'0'));
        }
  
        if(num<=255)
            return true;
   
        return false;
    }
    void backTrack(string s, int pos, int left, vector<string> &result)
    {
        // cout << "|" << s << ","<<pos<<","<<s.length()<<","<<left<<"| ";
        
        if(left==0)
        {
            if(isValid(s.substr(pos)))
                result.push_back(s);
            return;
        }
        
        if(pos>=s.length())
            return;
            
        for(int i=1;(pos+i)<=(s.length()-1);i++)
        {
            // cout << " checking" <<s.substr(pos,i) << " ";
            if(isValid(s.substr(pos,i)))
            {
                s.insert(pos+i,".");
                backTrack(s,pos+i+1,left-1,result);
                s.erase(pos+i,1);
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        backTrack(s,0,3,result);
        return result;
    }
};