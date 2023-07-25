class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        set<string> ans;
        string curr;
        int removal = 0;
        int sum = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i] == ')'){ sum += -1;}
            else if(s[i] =='('){sum += 1;}
            if(sum < 0){removal++;sum=0;}
        }
        removal +=sum;
        // cout<<valid(s)<<endl;
        solve(0,removal,s,ans,curr);
        vector<string> res;
        for(auto i:ans){
            res.push_back(i);
        }
        return res;
    }
    void solve(int i,int removal,string &s,set<string> &ans,string &curr){
        if(i == s.size()){
            // cout<<curr<<endl;
            if(valid(curr)) ans.insert(curr);
            return;
        }
        if(isalpha(s[i])){
            curr.push_back(s[i]);
            solve(i+1,removal,s,ans,curr);
            curr.pop_back();
            return;
        }
        int sum = 0;
        for(int i = 0;i<curr.size();i++){
            if(curr[i] == ')'){ sum += -1;}
            else if(curr[i] =='('){sum += 1;}
            
            if(sum < 0){return;}
        }

        curr.push_back(s[i]);
        solve(i+1,removal,s,ans,curr);
        curr.pop_back();
        if(removal>0){
            // cout<<
            solve(i+1,removal-1,s,ans,curr);
        }
    }

    bool valid(string &s){
        int sum = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i] == ')'){ sum += -1;}
            else if(s[i] =='('){sum += 1;}
            
            if(sum < 0){return false;}
        }
        if(sum != 0) return false;
        return true;
    }
    
    
};