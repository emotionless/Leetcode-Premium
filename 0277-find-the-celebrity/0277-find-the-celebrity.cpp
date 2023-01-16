// solved by Milon

/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        deque<int> q;
        for (int i = 0; i < n; i++) {
            q.push_back(i);
        }
        while (q.size() > 1) {
            int person1 = q.front();
            q.pop_front();
            int person2 = q.front();
            q.pop_front();
            if (knows(person1, person2)) {
                q.push_front(person2);
            } else {
                q.push_front(person1);
            }
        }
        if (q.size()) {
            int person = q.front();
            q.pop_front();
            for (int i = 0; i < n; i++) {
                if (i == person) continue;
                if (knows(person, i)) return -1;
                if (knows(i, person) == false) return -1;
            }
            return person;
        }
        return -1;
    }
};