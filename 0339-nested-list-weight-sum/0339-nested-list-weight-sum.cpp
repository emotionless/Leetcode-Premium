// solved by Milon

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    
    int solve(int ind, int depth, const vector<NestedInteger> &nestedList) {
        if (ind == nestedList.size()) {
            return 0;
        }
        int ret = 0;
        if (!nestedList[ind].isInteger())
            ret += solve(0, depth + 1, nestedList[ind].getList());
        else {
            ret += nestedList[ind].getInteger() * depth; 
        }
        ret += solve(ind + 1, depth, nestedList);
        // cout << ind << " " << depth << " " << ret << " " <<  nestedList[ind].isInteger() << " " << nestedList[ind].getInteger() << " " << nestedList[ind].getList().size() << endl;
        return ret;
    }
    
    int depthSum(vector<NestedInteger>& nestedList) {
        int len = nestedList.size();
        return solve(0, 1, nestedList);
    }
};