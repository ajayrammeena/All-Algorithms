class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> cur;
        partition(s, 0, cur, ans);
        return ans;
    }

private:
    void partition(string& s, int start, vector<string>& cur, vector<vector<string>>& ans) {
        
        if (start == s.size()){
            
            ans.push_back(cur);
        } 

        for (int len = 1; len <= s.size() - start; len++) {
            string substr = s.substr(start, len);
            // print(cur,start,len,substr);
            if (isPalindrome(substr)) {
                cur.push_back(substr);
                partition(s, start + len, cur, ans);
                // cout<<"ret"<<endl;
                cur.pop_back();
            }
        }
    }

    bool isPalindrome(string& s) {
        for (int i = 0; i < s.size() / 2; i++) {
            if (s[i] != s[s.size() - i - 1]) return false;
        }
        return true;
    }
    
    void print(vector<string>&curr,int st, int len,string sub){
        cout<<st<<" "<<len<<" "<<sub<<" "<<endl;
        // for(int i=0;i<curr.size();i++){
        //     cout<<curr[i]<< " ";
        // }
        // cout<<endl;
    }
};
Time Complexity : O(N⋅2^N), where N is the length of string sss. This is the worst-case time complexity when all the possible substrings are palindrome.
