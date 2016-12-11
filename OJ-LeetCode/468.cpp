class Solution {
public:
    string validIPAddress(string ip) {
        ip += ".";
        vector<char> ans;
        int bg = 0;
        bool flag = false;
        for (int i = 0; i < ip.length(); ++i) {
            if (isdigit(ip[i])) continue;
            else {
                ans.push_back(ip[i]);
                string judge = ip.substr(bg, i - bg);
                for (int j = 0; judge.size() > 1 && j < judge.size(); ++j) {
                    if (judge[j] == '0') {
                        flag = true;
                        break;
                    }
                    else break;
                }
                int sum = 0;
                for (int j = 0; j < judge.size(); ++j) {
                    sum *= 10;
                    sum += judge[j] - '0';
                }
                if (sum > 255 || judge.size() > 3) {
                    flag = true;
                    break;
                }
                bg = i + 1;
            }
        }
        if (!flag && ans.size() == 4) {
            bool ff = true;
            for (int i = 0; i < ans.size(); ++i) {
                if (ans[i] != '.') {
                    ff = false;
                    break;
                }
            }
            if (ff)
                return "IPv4";
        }
        
        ans.clear();
        bg = 0;
        flag = false;
        ip[ip.length() - 1] = ':';
        int need = 8;
        for (int i = 0; i < ip.length(); ++i) {
            if (isdigit(ip[i]) || isalpha(ip[i])) continue;
            else {
                ans.push_back(ip[i]);
                if (i && ip[i - 1] == ':') --need;
                string judge = ip.substr(bg, i - bg);
                if (judge.size() > 4) {
                    flag = true;
                    break;
                }
                for (int j = 0; j < judge.size(); ++j) {
                    if (isalpha(judge[j])) {
                        judge[j] = tolower(judge[j]);
                        if (judge[j] > 'f') {
                            flag = true;
                            break;
                        }
                    }
                }
                bg = i + 1;
            }
        }
        if (!flag && ans.size() == need) {
            bool ff = true;
            for (int i = 0; i < ans.size(); ++i) {
                if (ans[i] != ':') {
                    ff = false;
                    break;
                }
            }
            if (ff)
                return "IPv6";
        }
        return "Neither";
    }
};