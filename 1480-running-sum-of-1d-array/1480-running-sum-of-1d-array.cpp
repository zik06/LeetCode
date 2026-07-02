class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        int ref=0;
        for(int i : nums){
            ref+=i;
            ans.push_back(ref);
        }
        return ans;
    }
};