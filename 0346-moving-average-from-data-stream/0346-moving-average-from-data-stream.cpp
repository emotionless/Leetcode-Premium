// solved by Milon
class MovingAverage {
public:
    MovingAverage(int size) {
        dq.clear();
        sum = 0;
        sz = size;
    }
    
    double next(int val) {
        sum += val;
        dq.push_back(val);
        if (dq.size() > sz) {
            sum -= dq.front();
            dq.pop_front();
        }
        return (sum+0.0f)/(double)dq.size();
    }
private:
    int sz;
    deque<int> dq;
    int sum = 0;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */