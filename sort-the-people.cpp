struct Person {
    string name;
    int height;
};

class Solution {
private:
    void fillPeopleArray(vector<Person>& people, const vector<string>& names, const vector<int>& heights) {
        for (int i = 0; i < names.size(); i++) {
            people.push_back({names[i], heights[i]});
        }
    }

    void fillSortedNames(vector<string>& sortedNames, const vector<Person>& people) {
        for (auto person : people) {
            sortedNames.push_back(person.name);
        }
    }

public:
    vector<string> sortPeople(const vector<string>& names, const vector<int>& heights) {
        vector<Person> people;
        fillPeopleArray(people, names, heights);
        sort(people.begin(), people.end(),
            [](const Person& a, const Person& b) {
                return a.height > b.height;
            }
        );
        vector<string> sortedNames;
        fillSortedNames(sortedNames, people);
        return sortedNames;
    }
};
