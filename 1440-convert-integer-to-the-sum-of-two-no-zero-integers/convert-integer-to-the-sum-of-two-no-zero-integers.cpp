class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int a = 1; a < n; a++) {
            int b = n - a;
            if (isValid(a) && isValid(b)) {
                return {a, b};
            }
        }
        return {};
    }

private:
    bool isValid(int num) {
        while (num > 0) {
            if (num % 10 == 0) return false;
            num /= 10;
        }
        return true;
    }
};