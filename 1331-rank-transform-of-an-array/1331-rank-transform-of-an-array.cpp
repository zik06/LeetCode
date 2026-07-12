class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int>res;
        int a=1;
        vector<int>tot(arr.begin(),arr.end());
        sort(tot.begin(),tot.end());
        for(auto& i : tot){
            if(res[i]==0)
            res[i]=a++;
        }
        //     for(int i=0;i<n;i++){
        //         for(auto& v : res){
        //             if(arr[i]==v.first) tot[i]=v.second;
        //         }
        // }
        for(int i=0;i<n;i++){
            tot[i]=res[arr[i]];
        }
        return tot;
    }
};