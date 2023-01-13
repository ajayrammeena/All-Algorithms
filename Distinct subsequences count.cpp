#include <bits/stdc++.h>
using namespace std;
void solve(){
	string s;
	cin>>s;

	/*
	ex.  abcb --> the total number of subsequnces = 2^4 = 16;

String index: 	   0       |  1      |  2         | 3 
                   a       |  b      |  c         | b
dp index:     0  | 1       |  2      |  3         | 4

Ans:          1  |2*1=2    |2*2=4    |4*2=8        |8*2 = 16
                           |         |             |
              .  | .       |. b      |. b  c  bc   |.  b   c   bc 
                 | a       |a ab     |a ab ca abc  |a  ab  ca  abc 
                                                   |b  bb  cb  bcb 
                                                   |ab abb cab abcb

      So in last column few subsequnces (ab,b) which are generated by the 
      previous b. So we need to remove from count
      dp[i]--> Distinct subsequnces till ith index
          }
	*/
	int dp[s.length()+1];
	map<char,int>mp;
	dp[0]=1;
	for(int i=1;i<(s.length())+1;i++){
		dp[i] = 2*dp[i-1];
		char ch = s[i-1];
		if(mp[ch] != 0){
			int a = mp[ch];
			dp[i] = dp[i]-dp[a-1];
		}
		mp[ch] = i;
	}
	cout<<dp[s.length()]<<endl;
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t=1;
	// cin>>t;
	while(t--){
		solve();
	}

	return 0;
}