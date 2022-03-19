class FreqStack {
    int maxFreq;
    unordered_map<int,int> frequency;
    unordered_map<int,stack<int>> freqMapping;
public:
    FreqStack() {
        maxFreq = 0;
    }
    
    void push(int val) {
        int freq = frequency[val];
        maxFreq = max(maxFreq,1+freq);
        frequency[val] = 1+freq;
        freqMapping[1+freq].push(val);
    }
    
    int pop() {
        int element = freqMapping[maxFreq].top();
        frequency[element] = maxFreq-1;
        freqMapping[maxFreq].pop();
        if(freqMapping[maxFreq].size() == 0){
            maxFreq--;
        }
        return element;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */