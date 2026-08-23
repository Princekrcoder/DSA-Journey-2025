class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int diff = 0;
        int qLeft = 0;
        int qRight = 0;

        // First half
        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?') {
                qLeft++;
            } else {
                diff += num[i] - '0';
            }
        }

        // Second half
        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?') {
                qRight++;
            } else {
                diff -= num[i] - '0';
            }
        }

        int qDiff = qRight - qLeft;

        // Bob wins only when:
        // 2 * diff == 9 * qDiff
        return 2 * diff != 9 * qDiff;
    }
};