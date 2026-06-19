class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minDegree = ((double)minutes/60)*(double)360;
        double hrDegree = (((double)(hour%12)/12)*(double)360) + ((double)minutes/60)*(double)30;
        return min(abs(hrDegree-minDegree),((double)360-abs(hrDegree-minDegree)));
    }
};