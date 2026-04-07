class Robot {
    vector<int> steps;
    vector<string> dir = {"East","North","West","South"};
    int pos;
    int modulo;
    bool moved;
    int width;
    int height;
public:
    Robot(int width, int height) {
        this->width = width;
        this->height = height;
        steps.push_back(width-1);
        steps.push_back(height+width-2);
        steps.push_back(height+2*width-3);
        steps.push_back(2*height+2*width-4);
        pos = 0;
        moved = false;
        modulo = 2*height+2*width-4;
    }
    
    void step(int num) {
        moved = true;
        pos += num;
        pos %= modulo;
    }
    
    vector<int> getPos() {
        if(pos <= width-1){
            return {pos,0};
        }else if(pos <= height + width - 2){
            return {width-1,pos - width + 1};
        }else if(pos <= height + 2*width-3){
            return {2*width + height - pos - 3,height-1};
        }else{
            return {0,(modulo-pos)};
        }
    }
    
    string getDir() {
        if(!moved){
            return "East";
        }
        if(pos == 0){
            return "South";
        }
        int idx = lower_bound(steps.begin(),steps.end(),pos) - steps.begin();
        return dir[idx];
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->move(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */