class A {
    class B {
        public B(int x) {
        }
    }
}

public class Solution {
    static class C extends A.B {
        public C(A a) {
            a.super(0);
        }
    }
    public static void main(String[] args) {
        new C(new A());
    }
}