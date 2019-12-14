/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
/*
Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
*/
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        if(n<=1) return s;
        //Attention the initializing method of 2-dimension vector!
        vector<vector<int>>dp(n,vector<int>(n,0));
        int maxLen=0,l=0,r=0;
        // we need i from n-1 to 0 and j from 0 to n-1, s.t. i<=j
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<=n-1;j++){
                if(i==j) dp[i][j]=1;
                else if(j-i==1) dp[i][j]=(s[i]==s[j]);
                else dp[i][j]=(dp[i+1][j-1] && s[i]==s[j]);

                if(dp[i][j]==1 && j-i>maxLen){
                    maxLen=j-i;
                    l=i;
                    r=j;
                }
            }    
        }
        return s.substr(l,r-l+1);//substr(start position, length)
    }
};
// @lc code=end

