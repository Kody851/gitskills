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
//[recommend] The 1st comment on  https://leetcode.com/problems/regular-expression-matching/discuss/5651/Easy-DP-Java-Solution-with-detailed-Explanation
//https://leetcode.com/problems/regular-expression-matching/discuss/280588/DP-solution-with-the-most-general-natural-explanation
class Solution {
public:
    bool isMatch(string s, string p) {
        if(s.empty() && p.empty()) return true;
        //dp[i][j] represents if s[0,1,...,i-1] can match p[0,1,...,j-1]
        vector<vector<bool>>dp(s.size()+1,vector<bool>(p.size()+1,false));

        dp[0][0] = true;
        for(int j=2; j <p.size()+1; j +=2){
            if(p[j-1] == '*' && dp[0][j-2]){
                dp[0][j] = true;
            }
        }

        for(int i=1;i<s.size()+1;i++){
            for(int j=1;j<p.size()+1;j++){
                if(p[j-1]==s[i-1] || p[j-1]=='.') dp[i][j]=dp[i-1][j-1];
                if(p[j-1]=='*'){
                    if(p[j-2]!=s[i-1] && p[j-2]!='.') 
                        //repeated 0 times
                        dp[i][j]=dp[i][j-2];
                    else 
                        //repeated 0 times || repeated 1 times || repeated many times
                        dp[i][j]= dp[i][j-2] || dp[i-1][j-2] || dp[i-1][j];
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};
// @lc code=end

