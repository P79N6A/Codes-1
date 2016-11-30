/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package leanjava;

/**
 *
 * @author apple1
 */
public class Modem {
    int speed;
    public Modem(){};
    public Modem(int x) {
        speed = x;
    }
    static int cnt = 0;
    public void getSpeed() {
        ++cnt;
        System.out.println("The speed is " + speed);
    }
}
