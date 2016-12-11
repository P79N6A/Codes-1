public class Solution {
    public String validIPAddress(String ip) {
        if (ip.isEmpty()) return "Neither";
        if (ip.contains(":")) {
            return isIPv6(ip) ? "IPv6" : "Neither";
        }
        else return isIPv4(ip) ? "IPv4" : "Neither";
    }
    
    public boolean isIPv4(String ip) {
        if (ip.charAt(ip.length() - 1) == '.') return false;
        String split[] = ip.split("\\.");
        if (split.length != 4) return false;
        for (String x : split) {
            if (x.length() > 3) return false;
            for (int i = 0; i < x.length(); ++i) {
                char cur = x.charAt(i);
                if (cur < '0' || cur > '9') return false;
            }
            int val = Integer.parseInt(x);
            if (val > 255) return false;
            if (x.charAt(0) == '0' && x.length() != 1) return false;
        }
        return true;
    }
    
    public boolean isIPv6(String ip) {
        if (ip.charAt(ip.length() - 1) == ':') return false;
        String split[] = ip.split(":");
        if (split.length != 8) return false;
        for (String x : split) {
            if (x.isEmpty() || x.length() > 4) return false;
            char[] temp = x.toCharArray();
            for (int i = 0; i < temp.length; ++i) {
                if (!(('0' <= temp[i] && temp[i] <= '9') || ('a' <= temp[i] && temp[i] <= 'f') || ('A' <= temp[i] && temp[i] <= 'F')))
                return false;
            }
        }
        return true;
    }
}