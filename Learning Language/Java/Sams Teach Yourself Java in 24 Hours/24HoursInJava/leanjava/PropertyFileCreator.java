/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package leanjava;
import com.sun.xml.internal.txw2.Document;
import java.io.*;
import java.util.*;

/**
 *
 * @author apple1
 */
public class PropertyFileCreator {
    public PropertyFileCreator() {
        Properties prop = new Properties();
        prop.setProperty("username", "gzy");
        prop.setProperty("password", "111");
        try {
            File propFile = new File("properties.xml");
            FileOutputStream propStream = new FileOutputStream(propFile);
            prop.storeToXML(propStream, "Create on " + new Date());
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }
}
