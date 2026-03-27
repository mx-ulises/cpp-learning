class Solution {
private:
    vector<int> groupStudentsBySandwichPreferences(vector<int>& students) {
        vector<int> studentsByPreference(2);
        studentsByPreference[1] = accumulate(students.begin(), students.end(), 0);
        studentsByPreference[0] = students.size() - studentsByPreference[1];
        return studentsByPreference;
    }

    bool areSandwichLeft(int topSandwich, vector<int>& sandwiches) {
        return topSandwich < sandwiches.size();
    }

    bool doSomeoneWantThisSandwich(int sandwichType, vector<int>& studentsByPreference) {
        return 0 < studentsByPreference[sandwichType];
    }

    void giveSandwich(int sandwichType, vector<int>& studentsByPreference) {
        studentsByPreference[sandwichType]--; 
    }

public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        vector<int> studentsByPreference = groupStudentsBySandwichPreferences(students);
        int topSandwich = 0;
        while(areSandwichLeft(topSandwich, sandwiches) && doSomeoneWantThisSandwich(sandwiches[topSandwich], studentsByPreference)) {
            giveSandwich(sandwiches[topSandwich], studentsByPreference);
            topSandwich++;
        }
        return students.size() - topSandwich;
    }
};
