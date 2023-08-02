/*
 * Create a file named “c.txt”. Take 5 integers as input from the user and write them to this file. Now read the data from the file and find their average. Then write the average to a separate file named “d.txt.”

 */

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Task3 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        try {
            BufferedWriter writer = new BufferedWriter(new FileWriter("c.txt"));

            System.out.println("Enter 5 integers:");
            int sum = 0;
            for (int i = 0; i < 5; i++) {
                int number = scanner.nextInt();
                if (number < 0) {
                    throw new InvalidPriceExp("Price cannot be negative.");
                }
                sum += number;
                writer.write(String.valueOf(number));
                writer.newLine();
            }

            writer.close();

            int avg = sum / 5;

            BufferedWriter averageWriter = new BufferedWriter(new FileWriter("d.txt"));
            averageWriter.write("Average: " + avg);
            averageWriter.close();

        } catch (IOException | InvalidPriceExp e) {
            e.printStackTrace();
            System.out.println("Error writing to file");

        }

        finally {
            scanner.close();
            System.out.println("Done");
            System.exit(1);
        }
    }
}

class InvalidPriceExp extends Exception {
    public InvalidPriceExp(String message) {
        super(message);
    }
}
