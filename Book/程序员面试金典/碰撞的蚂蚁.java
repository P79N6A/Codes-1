import java.util.*;

public class Ants {
    public double antsCollision(int n) {
        return 1 - Math.pow(2, -(n - 1));
    }
}