class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> r, d;
        int n = senate.size();

        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') {
                r.push(i);
            } else {
                d.push(i);
            }
        }

        while(!r.empty() && !d.empty()){
            int ri = r.front();
            int di = d.front();

            r.pop();
            d.pop();

            if (di < ri) {
                d.push(di + n);
            } else {
                r.push(ri + n);
            }
        }
        return r.empty() ? "Dire" : "Radiant";
    }
};