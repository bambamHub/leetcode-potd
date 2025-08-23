class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums){

        int n = nums.size();

        long long cntZero = 0;
        long long res = 0;
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                cntZero++;
                res += cntZero;
            }
            else{
                cntZero = 0;
            }
        }
        return res;
    }
};
