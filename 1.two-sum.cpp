/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */
// @lc code=start
#include<unordered_map>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>hash;
        vector<int>res;
        /*//direct idea
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++){
            if(hash.find(target-nums[i])!=hash.end() 
            && hash[target-nums[i]]!=i){//防止target-nums[i]==nums[i]这种情况
                res.push_back(i);
                res.push_back(hash[target-nums[i]]);
                return res;
            }
        }
        */
        /*//wrong on [3,3]\n6
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]=i;
            if(hash.find(target-nums[i])!=hash.end() 
            && hash[target-nums[i]]!=i){
                res.push_back(hash[target-nums[i]]);
                res.push_back(i);
                return res;
            }
            
        }
        */
        //best
        for(int i=0;i<nums.size();i++){
            if(hash.find(target-nums[i])!=hash.end()){
                res.push_back(hash[target-nums[i]]);
                res.push_back(i);
                return res;
            }
            hash[nums[i]]=i;            
        }
        return res;
    }
};
// @lc code=end

