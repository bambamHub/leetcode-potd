class Solution {
public:
    int smallestNumber(int n){
        
        
        int ans = 0;
        for(int i=1; i<31; i++){
            int smallestNum = pow(2,i)-1;
            if(smallestNum>=n){
                ans = smallestNum;
                break;
            }
        }
        return ans;
    }
};
