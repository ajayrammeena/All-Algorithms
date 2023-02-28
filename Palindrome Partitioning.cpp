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
//Time Complexity : O(N⋅2^N), where N is the length of string sss. This is the worst-case time complexity when all the possible substrings are palindrome.
    
  //Using Dynamic Programing
class Solution {
public:
    vector<vector<string>> partition(string s) {
        int len = s.length();
        vector<vector<bool>> dp (len, vector <bool> (len, false));
        vector<vector<string>> result;
        vector<string> currentList;
        dfs(result, s, 0, currentList, dp);
        return result;
    }

    void dfs(vector<vector<string>> &result, string &s, int start, vector<string> &currentList, vector<vector<bool>> &dp) {
        if (start >= s.length()) result.push_back(currentList);
        for (int end = start; end < s.length(); end++) {
            if (s[start] == s[end] && (end - start <= 2 || dp[start + 1][end - 1])) {
                dp[start][end] = true;
                currentList.push_back(s.substr(start, end - start + 1));
                dfs(result, s, end + 1, currentList, dp);
                currentList.pop_back();
            }
        }
    }
};
//A given string s starting at index start and ending at index end is a palindrome if the following conditions are satisfied:

//         The characters at start and end indexes are equal.
//         The substring starting at index start+1 and ending at index end−1 is a palindrome.
