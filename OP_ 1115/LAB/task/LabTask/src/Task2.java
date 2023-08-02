/*
 * 
 * Create a file named “a.txt”. Manually write 5 strings to that file in 5
 * different lines. Now read the data from this file and print it to the
 * console.
 */

import java.io.IOException;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.util.Scanner;

public class Task2 {
    public static void main(String[] args) {
        try {
            BufferedWriter writer = new BufferedWriter(new FileWriter("b.txt"));
            Scanner scanner = new Scanner(System.in);
            System.out.println("Enter 5 integers:");
            for (int i = 0; i < 5; i++) {
                int number = scanner.nextInt();
                writer.write(String.valueOf(number));
                writer.newLine();
            }
            scanner.close();
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
            System.out.println("Error writing to file");
            System.exit(1);
        }
    }
}
