class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int N = flowerbed.size(),place = 0;
        if(N == 1){
            if(flowerbed[0] == 0){
                place++;
            }
            return place >= n;
        }
        for(int i=0;i<N;i++){
            if((i == 0 && flowerbed[i] + flowerbed[i+1] == 0) || 
                (i == N-1 && flowerbed[i] + flowerbed[i-1] == 0) ||
                (i > 0 && i < (N-1) && flowerbed[i] + flowerbed[i+1] + flowerbed[i-1] == 0)){
                place++;
                flowerbed[i] = 1;
            }
        }
        return place >= n;
    }
};