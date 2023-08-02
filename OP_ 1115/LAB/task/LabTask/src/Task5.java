/*
 * Write a program to calculate the profit for each product. The product list and corresponding information can be found in the given input file "AnnualSell.txt". (The file is given in LMS with assignment). Write output to "Profit.txt" file in the following format:

Item    Profit
...         .... 
...         .... 
...         .... 
Total Profit: 
Max Profit Item: 

 */

import java.io.*;
import java.util.HashMap;
import java.util.Map;

public class Task5 {
    public static void main(String[] args) {
        try {
            BufferedReader reader = new BufferedReader(new FileReader("AnnualSell.txt"));
            BufferedWriter writer = new BufferedWriter(new FileWriter("Profit.txt"));

            writer.write("Item\tProfit");
            writer.newLine();

            Map<String, Integer> productMap = new HashMap<>();
            String line;
            while ((line = reader.readLine()) != null) {
                String[] data = line.split(",");
                String item = data[0];

                int price = Integer.parseInt(data[1]);
                int unitsSold = Integer.parseInt(data[2]);

                if (price < 0) {
                    throw new InvalidPriceExp("Cannot have negative price.");
                }
                if (unitsSold < 0) {
                    throw new TotalUnitSoldMinBoundExp("Units sold cannot be negative.");
                }
                if (unitsSold > 1000) {
                    throw new TotalUnitSoldMaxBoundExp("Total units sold must be less than 1000.");
                }

                int profit = price * unitsSold;
                writer.write(item + "\t" + profit);
                writer.newLine();
                productMap.put(item, profit);
            }

            reader.close();

            int totalProfit = 0;
            String maxProfitItem = "";
            int maxProfit = Integer.MIN_VALUE;
            for (Map.Entry<String, Integer> entry : productMap.entrySet()) {
                totalProfit += entry.getValue();
                if (entry.getValue() > maxProfit) {
                    maxProfit = entry.getValue();
                    maxProfitItem = entry.getKey();
                }
            }

            writer.write("Total Profit: " + totalProfit);
            writer.newLine();
            writer.write("Max Profit Item: " + maxProfitItem);
            writer.close();
        } catch (IOException | InvalidPriceExp | TotalUnitSoldMinBoundExp
                | TotalUnitSoldMaxBoundExp e) {
            e.printStackTrace();
        }
    }
}

class InvalidPriceExp extends Exception {
    public InvalidPriceExp(String message) {
        super(message);
    }
}

class TotalUnitSoldMinBoundExp extends Exception {
    public TotalUnitSoldMinBoundExp(String message) {
        super(message);
    }
}

class TotalUnitSoldMaxBoundExp extends Exception {
    public TotalUnitSoldMaxBoundExp(String message) {
        super(message);
    }
}
