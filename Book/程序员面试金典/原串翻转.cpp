class Reverse {
public:
    string reverseString(string iniString) {
        for (int i = 0; i < iniString.length() / 2; ++i) {
            char temp = iniString[i];
            iniString[i] = iniString[iniString.length() - 1 - i];
            iniString[iniString.length() - 1 - i] = temp;
        }
        return iniString;
    }
};