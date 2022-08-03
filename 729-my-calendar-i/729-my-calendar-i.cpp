class MyCalendar {
public:
    map<int,int> mp;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(mp.empty()){
            mp[start] = end;
            return true;
        }
        map<int,int>::iterator it = mp.lower_bound(start);
        if(it!=mp.end() && (*it).first < end){
            return false;
        }
        if(it == mp.begin()){
            mp[start] = end;
            return true;
        }
        it = prev(it);
        if((*it).second > start){
            return false;
        }
        mp[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */