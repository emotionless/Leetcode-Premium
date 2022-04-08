// solved by Milon

/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int tot = 0;
        char buffer[4];
        while (tot < n) {
            int sz = read4(buf + tot);
            if (sz == 0) break;
            tot += sz;
        }
        return min(n, tot);
    }
};