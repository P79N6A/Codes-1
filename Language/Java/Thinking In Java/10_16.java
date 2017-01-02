// 工厂模式再试

import static Print.Print.*;

interface Cycle {
    void ride();
}

interface CycleFactory{
    Cycle getCycle();
}

class Implementation1 implements CycleFactory {
    @Override
    public Cycle getCycle() {
        return new Cycle() {
            @Override
            public void ride() {
                println("ride Unicycle");
            }
        };
    }
}

class Implementation2 implements CycleFactory {
    @Override
    public Cycle getCycle() {
        return new Cycle() {
            @Override
            public void ride() {
                println("ride Bicycle");
            }
        };
    }
}

class Implementation3 implements CycleFactory {
    @Override
    public Cycle getCycle() {
        return new Cycle() {
            @Override
            public void ride() {
                println("ride Tricycle");
            }
        };
    }
}

public class Solution {
    public static void rideCycle(CycleFactory fact) {
        Cycle c = fact.getCycle();
        c.ride();
    }
    public static void main(String[] args) {
        rideCycle(new Implementation1());
        rideCycle(new Implementation2());
        rideCycle(new Implementation3());
    }
    
}