class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> r_queue, d_queue;
        int n = senate.size();

        for (int i = 0; i < n; ++i) {
            if (senate[i] == 'R') r_queue.push(i);
            else d_queue.push(i);
        }

        while (!r_queue.empty() && !d_queue.empty()) {
            int r_idx = r_queue.front(); r_queue.pop();
            int d_idx = d_queue.front(); d_queue.pop();

            // Whichever senator appears earlier gets to ban the other
            if (r_idx < d_idx) {
                r_queue.push(r_idx + n); // moves to next round
            } else {
                d_queue.push(d_idx + n);
            }
        }

        return r_queue.empty() ? "Dire" : "Radiant";
    }
};