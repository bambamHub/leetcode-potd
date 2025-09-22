class Solution {
public:
    int maxFrequencyElements(vector<int>& nums){

        int n = nums.size();

        unordered_map<int, int> mp;

        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        
        int maxi = 0;
        for(auto it : mp){
            maxi = max(maxi, it.second);
        }
        
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(mp[nums[i]]==maxi){
                cnt++;
            }
        }
        return cnt;
        
    }
};
