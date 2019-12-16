/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

// @lc code=start
#include<string>
#include<vector>
using namespace std;
/*
1, If p.charAt(j) == s.charAt(i) :  dp[i][j] = dp[i-1][j-1];
2, If p.charAt(j) == '.' : dp[i][j] = dp[i-1][j-1];
3, If p.charAt(j) == '*': 
   here are two sub conditions:
               1   if p.charAt(j-1) != s.charAt(i) : dp[i][j] = dp[i][j-2]  //in this case, a* only counts as empty
               2   if p.charAt(j-1) == s.charAt(i) or p.charAt(j-1) == '.':
                              dp[i][j] = dp[i-1][j]    //in this case, a* counts as multiple a 
                           or dp[i][j] = dp[i][j-1]   // in this case, a* counts as single a
                           or dp[i][j] = dp[i][j-2]   // in this case, a* counts as empty
*/
/*
Testcase
"ab"
".*"
Answer
false
Expected Answer
true
*/
//https://leetcode.com/problems/regular-expression-matching/discuss/5651/Easy-DP-Java-Solution-with-detailed-Explanation
//https://leetcode.com/problems/regular-expression-matching/discuss/280588/DP-solution-with-the-most-general-natural-explanation
class Solution {
public:
    bool isMatch(string s, string p) {
        if(s.empty() && p.empty()) return true;//
        vector<vector<bool>>dp(s.size(),vector<bool>(p.size(),false));
        //初始条件
        for(int i=0;i<s.size();i++){
            for(int j=0;j<2;j++){
                dp[i][j]
            }
        }
        for(int j=1;j<p.size();j++){
            if(p[j]==s[0] && p[j-1]=='*') dp[0][j]=true; 
            if(p[j]=='*') dp[0][j]=dp[0][j-1];
        }
        //
        
        
        dp[0][0] = (p[0]==s[0] || p[0]=='.') ? true : false;
        for(int j=1;j<p.size();j++){
            if(p[j]==s[0] && p[j-1]=='*') dp[0][j]=true; 
            if(p[j]=='*') dp[0][j]=dp[0][j-1];
        }
        if(p.size()>1)
            dp[0][1] = (p[1]=='*' || p[1]==NULL) ? dp[0][0] : false;

        for(int i=0;i<s.size();i++){
            if(p[1]=='*')
            dp[i][1]
        }
        if(s.size()>1 && p.size()>1){
            dp[1][0]=false;
            if(p[1]==s[1] || p[1]=='.') dp[1][1]=dp[0][0];
            if(p[1]=='*' && (p[0]==s[1] || p[0]=='.')) dp[1][1]=dp[0][0];
        }


        for(int i=0;i<s.size();i++){
            for(int j=0;j<p.size();j++){
                if(p[j]==s[i] || p[j]=='.') dp[i+1][j+1]=dp[i][j];
                if(p[j]=='*'){
                    if(p[j-1]!=s[i] && p[j-1]!='.') dp[i+1][j+1]=dp[i+1][j-1];
                    if(p[j-1]==s[i] || p[j-1]=='.')
                        dp[i][j]= dp[i][j-1] || dp[i][j-2] || dp[i-1][j];
                }
            }
        }
        return dp[s.size()-1][p.size()-1];
    }
};
// @lc code=end

