class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes){

        int n = envelopes.size();

        sort(envelopes.begin(), envelopes.end(), [](auto &a , auto &b){
            if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });

        vector<int> heights;

        for(auto &h : envelopes){
            heights.push_back(h[1]);
        }

        vector<int> temp;
        temp.push_back(heights[0]);

        for(int i=1; i<n; i++){
            if(heights[i]>temp.back()){
                temp.push_back(heights[i]);
            }
            else{
                int ind = lower_bound(temp.begin(), temp.end(), heights[i]) - temp.begin();
                temp[ind] = heights[i];
            }
        }
        return temp.size();
    }
};
