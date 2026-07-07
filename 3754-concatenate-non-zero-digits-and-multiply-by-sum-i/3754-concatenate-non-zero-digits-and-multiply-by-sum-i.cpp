class Solution {
public:
    long long sumAndMultiply(int n) {
        long long temp=0,res=0;
        int reversedNum = 0;
    
    while (n != 0) {
        int remainder = n % 10;
        if (reversedNum > INT_MAX / 10 || (reversedNum == INT_MAX / 10 && remainder > 7)) return 0;
        if (reversedNum < INT_MIN / 10 || (reversedNum == INT_MIN / 10 && remainder < -8)) return 0;
        
        reversedNum = reversedNum * 10 + remainder;
        n /= 10;
    }
    while(reversedNum>0){
        int a=reversedNum%10;
        if(a!=0) temp=temp*10+a;
        res+=a;
        reversedNum/=10;
    }
    return temp*res;
    }
};