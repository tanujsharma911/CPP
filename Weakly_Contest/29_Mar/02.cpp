#include <set>
#include <iostream>
using namespace std;

class EventManager {
public:

    struct CustomCompare {
        bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) const {
            // If seconds are equal, sort by first element descending.
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first > b.first;
        }
    };

    set<pair<int, int>, CustomCompare> priority_id; // sort
    unordered_map<int, int> id_priority;

    EventManager(vector<vector<int>>& events) { // [eventId, priority][]
        for(auto event: events){
            priority_id.insert({event[1], event[0]});
            id_priority[event[0]] = event[1];
        }
    }

    void updatePriority(int eventId, int newPriority) {
        if(!id_priority.count(eventId)) return;

        int old_priority = id_priority[eventId];
        id_priority[eventId] = newPriority;

        priority_id.erase({old_priority, eventId});
        priority_id.insert({newPriority, eventId});
    }

    int pollHighest() {
        if(priority_id.empty()) return -1;

        int event_id = priority_id.begin()->second;

        id_priority.erase(event_id);

        priority_id.erase(priority_id.begin());

        return event_id;
    }
};

int main()
{
    vector<vector<int>> e = {{4,1},{7,2}};

    EventManager m(e);

    cout << m.pollHighest();

    cout << m.pollHighest();

    cout << m.pollHighest();

    cout << endl;
    return 0;
}
