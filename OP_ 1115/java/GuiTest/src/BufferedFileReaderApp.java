import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class BufferedFileReaderApp {
    public static void main(String[] args) {
        String fileName = "example.txt";

        try (BufferedReader bufferedReader = new BufferedReader(new FileReader(fileName))) {
            String line;
            while ((line = bufferedReader.readLine()) != null) {
                System.out.println(line);
            }
        } catch (IOException e) {

            if (e.getMessage().equals(fileName + " (No such file or directory)")) {
                System.out.println("File not found. Creating file...");
                try {
                    new java.io.File(fileName).createNewFile();
                    System.out.println("File created successfully.");
                } catch (IOException e2) {
                    System.out.println("An error occurred: " + e2.getMessage());
                }
            } else {
                System.out.println("An error occurred: " + e.getMessage());
            }

        }
    }
}