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
public class DSLModem extends Modem{
    String method = "DSL phone connection";
    public void get() {
        ++cnt;
        System.out.println(method);
    }
}
