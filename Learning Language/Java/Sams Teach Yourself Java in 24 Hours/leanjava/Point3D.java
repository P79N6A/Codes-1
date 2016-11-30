/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package leanjava;

import java.awt.Point;

/**
 *
 * @author apple1
 */
public class Point3D extends Point{
    int z;
    
    public Point3D(int x, int y, int z) {
        super(x, y);
        this.z = z;
    }
    
    public void move(int x, int y, int z) {
        super.move(x, y);
        this.z = z;
    }
    
    public void translate(int x, int y, int z) {
        super.translate(x, y);
        this.z += z;
    }
}
