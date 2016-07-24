/*
  树的最小表示:递归子树，然后给子树排序
 */
 
string mRept(string s) {
    string ret = "0";
    vector<string> temp;
    int cnt = 0, p = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '0') ++cnt;
        else --cnt;
        if (cnt == 0) {
            temp.push_back(mRept(s.substr(p + 1, i - 1 - (p + 1) + 1)));
            p = i + 1;
        }
    }
    sort(temp.begin(), temp.end());
    for (int i = 0; i < temp.size(); ++i) ret += temp[i];
    return ret + "1";
}