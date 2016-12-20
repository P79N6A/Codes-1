public class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, Integer> map = new HashMap<>();
        List<List<String>> ret = new ArrayList<>();
        int cnt = 0;
        for (String s : strs) {
            char[] temp = s.toCharArray();
            Arrays.sort(temp);
            String ss = new String(temp);
            if (map.containsKey(ss)) {
                int x = map.get(ss);
                ret.get(x).add(s);
            }
            else {
                map.put(ss, cnt++);
                ret.add(new ArrayList<String>(Arrays.asList(s)));
            }
            System.out.println(map.containsKey(temp) + "\n=========");
            //System.out.println(map.get(temp));
        }
        System.out.println(cnt);
        return ret;
    }
}