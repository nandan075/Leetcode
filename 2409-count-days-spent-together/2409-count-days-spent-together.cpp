class Solution {
public:
    int convert(string date, vector<int>& prefix) {
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));

        return prefix[month - 1] + day;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        vector<int> days = {
            31, 28, 31, 30, 31, 30,
            31, 31, 30, 31, 30, 31
        };

        vector<int> prefix(13, 0);

        for (int i = 1; i <= 12; i++) {
            prefix[i] = prefix[i - 1] + days[i - 1];
        }

        int a1 = convert(arriveAlice, prefix);
        int a2 = convert(leaveAlice, prefix);
        int b1 = convert(arriveBob, prefix);
        int b2 = convert(leaveBob, prefix);

        int start = max(a1, b1);
        int end = min(a2, b2);

        return max(0, end - start + 1);
    }
};