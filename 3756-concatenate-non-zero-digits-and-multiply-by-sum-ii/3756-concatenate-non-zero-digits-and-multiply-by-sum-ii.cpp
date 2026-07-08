class Solution {
    const int MOD = 1000000007;
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int m = s.size();
        vector<long long> pow10(m + 1, 1);
        for (int i = 1; i <= m; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }
        vector<int> sumD(m + 1, 0);  
        vector<int> cntN0(m + 1, 0);  
        vector<long long> p(m + 1, 0);   

        for (int i = 1; i <= m; i++) {
            int d = s[i - 1] - '0';
            sumD[i] = sumD[i - 1] + d;
            cntN0[i] = cntN0[i - 1] + (d > 0);
            p[i] = d ? (p[i - 1] * 10 + d) % MOD : p[i - 1];
        }
        vector<int> fin;
        fin.reserve(queries.size());

        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            long long sd = sumD[r + 1] - sumD[l];
            int n0 = cntN0[r + 1] - cntN0[l];
            long long x = (p[r + 1] - (p[l] * pow10[n0]) % MOD + MOD) % MOD;
            
            long long res = (x * (sd % MOD)) % MOD;
            fin.push_back(res);
        }
        return fin;
    }
};