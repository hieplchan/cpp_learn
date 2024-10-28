class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        if (strs[0][0] == '\0') return "";

        string prefix = "";
        char temp;
        for (int i = 0; i <= 200; i++)
        {
            if (strs[0][i] == '\0')
                return prefix;
            else
                temp = strs[0][i];

            for (int j = 1; j < strs.size(); j++)
            {
                if (strs[j][i] == '\0') return prefix;
                if (strs[j][i] != temp) return prefix;
            }

            prefix += temp;
        }

        return prefix;
    }
};