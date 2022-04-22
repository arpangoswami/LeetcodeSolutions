class MyHashMap {
    vector<int> present;
public:
    MyHashMap() {
        present.resize(1000001,-1);
    }
    
    void put(int key, int value) {
        present[key] = value;
    }
    
    int get(int key) {
        return present[key];
    }
    
    void remove(int key) {
        present[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */