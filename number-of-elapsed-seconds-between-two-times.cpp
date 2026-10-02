class Solution {
private:
    int getTotalSeconds(string time) {
        int hourSeconds = stoi(time.substr(0, 2)) * 3600;
        int minuteSeconds = stoi(time.substr(3, 2)) * 60;
        int seconds = stoi(time.substr(6, 2));
        return hourSeconds + minuteSeconds + seconds;
    }

public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int startTimeSeconds = getTotalSeconds(startTime);
        int endTimeSeconds = getTotalSeconds(endTime);
        return endTimeSeconds - startTimeSeconds;
    }
};
