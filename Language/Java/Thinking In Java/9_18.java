// 工厂模式初试

import static Print.Print.*;

interface Cycle {
    void ride();
}

interface CycleFactory{
    Cycle getCycle();
}

class Unicycle implements Cycle {
    @Override
    public void ride() {
        println("ride Unicycle");
    }
}

class Implementation1 implements CycleFactory {
    @Override
    public Cycle getCycle() {
        return new Unicycle();
    }
}

class Bicycle implements Cycle {
    @Override
    public void ride() {
        println("ride Bicycle");
    }
}

class Implementation2 implements CycleFactory {
    @Override
    public Cycle getCycle() {
        return new Bicycle();
    }
}

class Tricycle implements Cycle {
    @Override
    public void ride() {
        println("ride Tricycle");
    }
}

class Implementation3 implements CycleFactory {
    @Override
    public Cycle getCycle() {
        return new Tricycle();
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