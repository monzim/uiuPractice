import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        List<Integer> integers = getInputFileFromFilename();

        System.out.println("List of integers: " + integers);

        SortAlgorithm algorithm = askForAlgorithm();
        SortOrder order = askForOrderType();

        System.out.println("Input data:");
        System.out.println("Choose algorithm: " + algorithm);
        System.out.println("Choose order: " + order);

  
        long timeTaken = 0;

         switch (algorithm) {
            case BUBBLE:
                timeTaken = withTiming(() -> bubbleSort(integers, order));
                break;
            case INSERTION:
                timeTaken = withTiming(() -> insertionSort(integers, order));
                break;
            case SELECTION:
                timeTaken = withTiming(() -> selectionSort(integers, order));
                break;
            default:
                timeTaken = withTiming(() -> bubbleSort(integers, order));
                break;
        }

        System.out.println("Sorted data: " + integers);
        System.out.println("Time taken: " + timeTaken + "ms");

        System.out.println("Do you want to save the sorted data to a file? (y/n)");
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();

        if (input.equals("y")) {
            saveToFile(integers, timeTaken);
        }

        System.out.println("Thank you for using the program!");
    }

    private static long withTiming(Runnable code) {
        long startTime = System.nanoTime();
        code.run();
        long endTime = System.nanoTime();
        return (endTime - startTime) / 1_000_000; // milliseconds
    }


    private static List<Integer> getInputFileFromFilename() {
        System.out.println("Please enter the input file name:");
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();

        List<Integer> integers = new ArrayList<>();

        try (BufferedReader reader = new BufferedReader(new FileReader(input))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] numStrings = line.split(" ");
                for (String numStr : numStrings) {
                    integers.add(Integer.parseInt(numStr));
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        return integers;
    }

    private static SortAlgorithm askForAlgorithm() {
        System.out.println("Please choose a sorting algorithm: (default: 1)");
        System.out.println("1. Bubble Sort");
        System.out.println("2. Insertion Sort");
        System.out.println("3. Selection Sort");

        Scanner scanner = new Scanner(System.in);
        int input = scanner.nextInt();

        switch (input) {
            case 1:
                return SortAlgorithm.BUBBLE;
            case 2:
                return SortAlgorithm.INSERTION;
            case 3:
                return SortAlgorithm.SELECTION;
            default:
                return SortAlgorithm.BUBBLE;
        }
    }

    private static SortOrder askForOrderType() {
        System.out.println("Please choose a sorting order: (default: 1)");
        System.out.println("1. Ascending");
        System.out.println("2. Descending");

        Scanner scanner = new Scanner(System.in);
        int input = scanner.nextInt();

        switch (input) {
            case 1:
                return SortOrder.ASC;
            case 2:
                return SortOrder.DESC;
            default:
                return SortOrder.ASC;
        }
    }

    private static void bubbleSort(List<Integer> arr, SortOrder order) {
        int n = arr.size();
        boolean swapped = true;

        while (swapped) {
            swapped = false;
            for (int i = 1; i < n; i++) {
                if ((order == SortOrder.ASC && arr.get(i - 1) > arr.get(i))
                        || (order == SortOrder.DESC && arr.get(i - 1) < arr.get(i))) {
                    int temp = arr.get(i - 1);
                    arr.set(i - 1, arr.get(i));
                    arr.set(i, temp);
                    swapped = true;
                }
            }
            n--;
        }
    }

    private static void insertionSort(List<Integer> arr, SortOrder order) {
        for (int i = 1; i < arr.size(); i++) {
            int key = arr.get(i);
            int j = i - 1;

            while (j >= 0 && ((order == SortOrder.ASC && arr.get(j) > key) || (order == SortOrder.DESC && arr.get(j) < key))) {
                arr.set(j + 1, arr.get(j));
                j--;
            }
            arr.set(j + 1, key);
        }
    }

    private static void selectionSort(List<Integer> arr, SortOrder order) {
        int n = arr.size();

        for (int i = 0; i < n - 1; i++) {
            int minMaxIndex = i;
            for (int j = i + 1; j < n; j++) {
                if ((order == SortOrder.ASC && arr.get(j) < arr.get(minMaxIndex))
                        || (order == SortOrder.DESC && arr.get(j) > arr.get(minMaxIndex))) {
                    minMaxIndex = j;
                }
            }
            int temp = arr.get(i);
            arr.set(i, arr.get(minMaxIndex));
            arr.set(minMaxIndex, temp);
        }
    }

    private static void saveToFile(List<Integer> integers, long timeTaken) {
        System.out.println("Please enter the output file name:");
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();

        try (BufferedWriter writer = new BufferedWriter(new FileWriter(input))) {
            for (Integer i : integers) {
                writer.write(i + " ");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        System.out.println("Sorted data saved to file: " + input);
    }

    enum SortAlgorithm {
        BUBBLE,
        INSERTION,
        SELECTION
    }

    enum SortOrder {
        ASC,
        DESC
    }
}
