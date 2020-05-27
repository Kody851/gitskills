/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        permute_core(nums, 0, res);
        return res;

    }
    void swap_v(vector<int>&a, int i, int j){
        int tmp=a[i];
        a[i]=a[j];
        a[j]=tmp;
    }
    void permute_core(vector<int>& nums, int begin, vector<vector<int>>& res){
        if(begin==nums.size()-1){
            res.push_back(nums);
            return;
        }
        for(int i=begin;i<nums.size();i++){
            swap_v(nums,i,begin);
            permute_core(nums, begin+1, res);
            swap_v(nums,i,begin);
        }
    }
};
// @lc code=end

