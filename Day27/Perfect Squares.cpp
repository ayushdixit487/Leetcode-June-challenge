class Solution {
public:
    int numSquares(int n) {
        while(!(n&3)) n /= 4;
        if(n%8 == 7) return 4;
        for(int a = sqrt(n); a > 0; --a)
        {
            int b = sqrt(n-a*a);
            if(a*a+b*b == n) return !b? 1 : 2;
        }
        return 3;           
    }
};
