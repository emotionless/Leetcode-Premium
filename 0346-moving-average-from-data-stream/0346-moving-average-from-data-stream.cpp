// solved by Milon
class MovingAverage {
public:
    MovingAverage(int size) {
        sum = 0;
        sz = size;
    }
    
    double next(int val) {
        sum += val;
        dq.push(val);
        if (dq.size() > sz) {
            sum -= dq.front();
            dq.pop();
        }
        return (sum+0.0f)/(double)dq.size();
    }
private:
    int sz;
    queue<int> dq;
    int sum = 0;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */