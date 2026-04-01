struct Robot {
    int position;
    int health;
    int idx;
    char direction;
    Robot(int position,int health,int idx,char direction){
        this->position = position;
        this->health = health;
        this->idx = idx;
        this->direction = direction;
    }
};
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<Robot> rightMovers;
        vector<Robot> robots;
        vector<Robot> ans;
        for(int i=0;i<n;i++){
            robots.emplace_back(Robot(positions[i],healths[i],i,directions[i]));
        }
        sort(robots.begin(),robots.end(),[](Robot &r1,Robot &r2){
            return r1.position < r2.position;
        });
        for(int i=0;i<n;i++){
            if(robots[i].direction == 'L'){
                int health = robots[i].health;
                while (!rightMovers.empty() && health > rightMovers.back().health) {
                    rightMovers.pop_back();
                    health--;
                }
                if (rightMovers.empty()) {
                    ans.push_back(Robot(robots[i].position, health, robots[i].idx, robots[i].direction)); //will survive;
                } else if (health < rightMovers.back().health) {
                    (rightMovers.back().health)--; //moving left destroyed
                } else if (health == rightMovers.back().health) {
                    rightMovers.pop_back(); //both destroyed;
                }
            } else {
                rightMovers.push_back(robots[i]);
            }
        }
        for(Robot &x:rightMovers){
            ans.push_back(x);
        }
        sort(ans.begin(),ans.end(),[](Robot &r1,Robot &r2){
            return r1.idx < r2.idx;
        });
        vector<int> sol;
        for(int i=0;i<ans.size();i++){
            sol.push_back(ans[i].health);
        }
        return sol;
    }
};