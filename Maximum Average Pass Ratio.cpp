class Solution {
public:
    #define P pair<double, int>
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {

        int n = classes.size();

        priority_queue<P> pq;

        for(int i=0; i<n; i++){
            double current_PR = (double)classes[i][0]/classes[i][1];
            double new_PR = (double)(classes[i][0]+1)/(classes[i][1]+1);
            double delta = new_PR - current_PR;
            pq.push({delta, i});
        }

        while(extraStudents--){
            auto curr = pq.top();
            pq.pop();

            double delta = curr.first;
            int ind = curr.second;

            classes[ind][0]++;
            classes[ind][1]++;

            double current_PR = (double)classes[ind][0]/classes[ind][1];
            double new_PR = (double)(classes[ind][0]+1)/(classes[ind][1]+1);
            delta = new_PR - current_PR;
            pq.push({delta, ind});
        }

        double res = 0.0;
        for(int i=0; i<n; i++){
            res += (double)classes[i][0]/classes[i][1];
        }
        return res/n;
    }
};
