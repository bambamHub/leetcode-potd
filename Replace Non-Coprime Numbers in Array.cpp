class Solution {
public: 
    vector<int> replaceNonCoprimes(vector<int>& nums){

        vector<int> res;

        for(int num : nums){

            while(!res.empty()){
                int prev = res.back();
                int curr = num;

                int GCD = gcd(prev, curr);
                if(GCD == 1){
                    break;
                }
                res.pop_back();
                int LCM = prev / GCD * curr;

                num = LCM;
            }
            res.push_back(num);
        }

        return res; 
    }
};
