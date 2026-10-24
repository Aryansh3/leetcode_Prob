class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        string st = max(arriveAlice , arriveBob);
        string end = min(leaveAlice , leaveBob);
        if(st > end){
            return 0;
        }
        auto convert = [&](string date) {
            int month = stoi(date.substr(0, 2));
            int day = stoi(date.substr(3, 2));

            int total = day;

            for (int i = 0; i < month - 1; i++) {
                total += days[i];
            }

            return total;
        };
        return convert(end)- convert(st)+1;
    }
};