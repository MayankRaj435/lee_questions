class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0, sum = 0, place = 1;
        while (n > 0) {
            int d = n % 10;
            if (d != 0) {
                x   += (long long)d * place;  // digit ko x mein uski jagah pe rakho
                place *= 10;                  // place SIRF rakhe hue digit pe badhao
                sum += d;
            }
            n /= 10;
        }
        return x * sum;
    }
};