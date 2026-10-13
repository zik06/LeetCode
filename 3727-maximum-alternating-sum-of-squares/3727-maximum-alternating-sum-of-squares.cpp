class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        for(auto& i: nums){
            i*=i;
        }
        sort(nums.begin(),nums.end());
        int l=0,r=n-1;
        long long score=0;
        while(l<r){
            score+=nums[r--];
            score-=nums[l++];
        }
        if(l==r)score+=nums[r];
        return score;
    }
};