class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),[](auto &v1,auto &v2){
            return v1[1] < v2[1]; 
        });
        int currTime = 0,coursesTaken = 0,n = courses.size();
        priority_queue<int> durations;
        for(int i=0;i<n;i++){
            if(courses[i][0] > courses[i][1]){
                continue;
            }
            if(currTime + courses[i][0] <= courses[i][1]){
                durations.push(courses[i][0]);
                coursesTaken++;
                currTime += courses[i][0];
            }else{
                int topDur = durations.top();
                if(topDur > courses[i][0]){
                    currTime -= topDur;
                    currTime += courses[i][0];
                    durations.pop();
                    durations.push(courses[i][0]);
                }
            }
        }
        return coursesTaken;
    }
};