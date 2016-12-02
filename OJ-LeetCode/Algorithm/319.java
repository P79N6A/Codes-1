public class Solution {
    public int bulbSwitch(int n) { 
        //考虑除1以外的数，每个数字必定都有自己和本身，那么首先可整除数为2个。
        //接着如果在(1,sqrt(n))之间找到整除的数，那么必定也会在(sqrt(n),n)之间找到配对
        //所以，除了点sqrt(n)整除的情况下，后期不管怎么加，都是加2。
        return (int)Math.sqrt(n);
    }
}