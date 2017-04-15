import java.util.*;
// 也可以使用快排来查找相同的
public class Different {
    
    public boolean checkDifferent(String iniString) {
        if (iniString != null && iniString.length() > 256) return false;
        for (int i = 0; i < iniString.length(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (iniString.charAt(i) == iniString.charAt(j)) return false;
            }
        }
        return true;
    }
}