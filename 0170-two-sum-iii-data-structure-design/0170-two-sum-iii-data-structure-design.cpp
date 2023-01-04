// Solved by Milon
class TwoSum {
public:
    TwoSum() {
        freq.clear();
    }
    
    void add(int number) {
        freq[number]++;
    }
    
    bool find(int value) {
        if (llabs(value) > 200000) return false;
        for (auto &element : freq) {
            int num = element.first;
            int rest = value - num;
            if (num == rest && element.second > 1) return true;
            if (num != rest && freq.count(rest)) return true;
        }
        return false;
    }
private:
    unordered_map<int, int> freq;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */