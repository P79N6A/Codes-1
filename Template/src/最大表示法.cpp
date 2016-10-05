// s.length() == 2 * l
int MR(string &s, int l)
{
    int i = 0, j = 1, k = 0;
    while (i < l && j < l)
    {
        k = 0;
        while (k < l && s[i + k] == s[j + k]) ++k;
        if (k == l) return min(i, j);
        if (s[i + k] < s[j + k])
        {
            if (i + k + 1 <= j) i = j + 1;
            else i = i + k + 1;
        }
        else
        {
            if (j + k + 1 <= i) j = i + 1;
            else j = j + k + 1;
        }
    }
    return min(i, j);
}
