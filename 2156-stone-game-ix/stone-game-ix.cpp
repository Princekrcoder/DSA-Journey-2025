class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {0, 0, 0};

        for (int x : stones) {
            cnt[x % 3]++;
        }

        // If there are no remainder 1 and 2 stones,
        // Alice cannot make the sum divisible by 3 strategically.
        if (cnt[1] == 0 && cnt[2] == 0) {
            return false;
        }

        // If cnt[0] is even, the game is balanced.
        // Alice can win if there is enough imbalance between
        // remainder-1 and remainder-2 stones.
        if (cnt[0] % 2 == 0) {
            return cnt[1] > 0 && cnt[2] > 0;
        }

        return abs(cnt[1] - cnt[2]) > 2;
    }
};