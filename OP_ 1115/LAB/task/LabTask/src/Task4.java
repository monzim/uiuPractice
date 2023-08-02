/*
 * Create a file named “e.txt”. Take 5 strings as input from the user and write them to this file. Now read the data from the file and form a single sentence (words separated by a single space). Then write this sentence to a single line of a new file named “f.txt”.
 */

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Task4 {
    public static void main(String[] args) {
        try {
            BufferedWriter wri = new BufferedWriter(new FileWriter("e.txt"));
            Scanner scanner = new Scanner(System.in);
            System.out.println("Enter 5 strings:");
            for (int i = 0; i < 5; i++) {
                String input = scanner.nextLine();
                wri.write(input);
                wri.newLine();
            }
            scanner.close();
            wri.close();

            StringBuilder sentence = new StringBuilder();
            BufferedReader reader = new BufferedReader(new FileReader("e.txt"));
            String line;
            while ((line = reader.readLine()) != null) {
                sentence.append(line).append(" ");
            }
            reader.close();

            BufferedWriter sentenceWritter = new BufferedWriter(new FileWriter("f.txt"));
            sentenceWritter.write(sentence.toString());
            sentenceWritter.close();
        } catch (IOException e) {
            e.printStackTrace();
            System.out.println("Error writing to file");

        }

    }
}
