/*
 * 
 * Create a file named “a.txt”. Manually write 5 strings to that file in 5
 * different lines. Now read the data from this file and print it to the
 * console.
 */

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Task1 {

    public static void main(String[] args) {
        try {
            BufferedReader reader = new BufferedReader(new FileReader("a.txt"));
            String line;
            while ((line = reader.readLine()) != null) {
                System.out.println(line);
            }
            reader.close();
        } catch (IOException e) {
            e.printStackTrace();
            System.out.println("Error reading file");
            System.exit(1);

        }
    }

}