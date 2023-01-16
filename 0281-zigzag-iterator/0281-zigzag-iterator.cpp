// solved by Milon

class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (v1.size() > 0) {
            q.push(v1.begin());
            listEnd.push(v1.end());
        }
        if (v2.size() > 0) {
            q.push(v2.begin());
            listEnd.push(v2.end());
        }
    }

    int next() {
        auto frnt = q.front();
        q.pop();
        auto frntEnd = listEnd.front();
        listEnd.pop();
        int ret = *frnt;
        frnt++;
        if (frnt != frntEnd) {
            q.push(frnt);
            listEnd.push(frntEnd);
        }
        return ret;
    }

    bool hasNext() {
        return q.size() > 0;
    }
private:
    queue<vector<int>::iterator> q, listEnd;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */