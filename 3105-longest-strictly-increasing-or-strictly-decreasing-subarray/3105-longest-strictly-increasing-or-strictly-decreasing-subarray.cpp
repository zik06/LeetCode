class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 1;
        int cnt=1, maxi=INT_MIN;
        bool check=false;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1] && (i==1 || check)){
                check=true;
                cnt++;
            }
            else if(nums[i]<nums[i-1] && (i==1 || !check)){
                check=false;
                cnt++;
            }
            else if(nums[i]>nums[i-1] && !check){
                check=true;
                cnt=2;
            }
            else if(nums[i]<nums[i-1] && check){
                check=false;
                cnt=2;
            }
            else if(nums[i]==nums[i-1])cnt=1;
            maxi=max(maxi,cnt);
        }
        return maxi;
    }
};