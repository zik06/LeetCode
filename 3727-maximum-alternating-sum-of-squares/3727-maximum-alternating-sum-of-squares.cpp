class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        for(int &i:nums){
            // if(i<0)i=i*-1;
            i=abs(i);
        }
        sort(nums.begin(),nums.end());
        int l=0,r=n-1;
        long long score=0;
        while(l<r){
            score+=nums[r]*nums[r];
            r--;
            score-=nums[l]*nums[l];
            l++;
        }
        if(l==r){
            score+=nums[r]*nums[r];
        }
        return score;
    }
};