import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        try (Scanner scanner = new Scanner(System.in)) {
            float total_amount = 0.0f;
            float interest_rate = 0.0f;
            int years = 0;
            float result = 0.0f;

            System.out.print("Enter the total amount: ");
            total_amount = scanner.nextFloat();

            System.out.print("Enter the interest rate: ");
            interest_rate = scanner.nextFloat();

            System.out.print("Enter the number of years: ");
            years = scanner.nextInt();

            CalCulateMotgage obj = new CalCulateMotgage();
            result = obj.calculateMotgage(total_amount, interest_rate, years);

            // print mortgage
            System.out.println("Mortgage: " + result);
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }

    }

}