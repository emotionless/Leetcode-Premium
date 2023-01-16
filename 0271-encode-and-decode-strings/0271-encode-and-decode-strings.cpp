class Codec {
public:
    
    string getString(int num) {
        string str = to_string(num);
        while (str.size() < 3) {
            str = "0" + str;
        }
        return str;
    }

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded = "";
        for (auto &str : strs) {
            int len = str.size();
            encoded += getString(len) + str;
        }
        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        int ind = 0;
        vector<string> ans;
        while (s[ind] != '\0') {
            string str = "";
            str += s[ind];
            str += s[ind + 1];
            str += s[ind + 2];
            int len = stoi(str);
            ind += 3;
            ans.push_back(s.substr(ind, len));
            ind += len;
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));