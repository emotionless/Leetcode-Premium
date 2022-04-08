class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int id = 0;
        while(n--) {
            if (ind == 0) {
                sz = read4(tmp);
            }
            if (sz > 0) {
                buf[id++] = tmp[ind++];
                sz--;
            }
            else
                break;
            ind %= 4;
        }
        return id;
    }

private:
    char tmp[4];
    int ind = 0, sz = 0;
};