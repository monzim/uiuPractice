import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        // NestKClass n = new NestKClass("NestKClass");

        // n.print();

        // NestKClass.InnerClass i = n.new InnerClass("InnerClass");

        // i.print();

        // n.innerClass.print();

        // Scanner scanner = new Scanner(System.in);

        // System.out.print("Enter the account holder's name: ");
        // String holderName = scanner.nextLine();

        // System.out.print("Enter the account number: ");
        // String accountNumber = scanner.nextLine();

        // System.out.print("Enter the balance: ");
        // double balance = scanner.nextDouble();

        // System.out.print("Enter the overdraft limit: ");
        // double overdraft = scanner.nextDouble();

        // BankAccount bankAccount = new BankAccount(holderName, accountNumber,
        // balance);
        // CheckingAccount checkingAccount = new CheckingAccount(holderName,
        // accountNumber, balance, overdraft);

        // System.out.println("\nBank Account Information:");
        // bankAccount.display();

        // System.out.println("\nChecking Account Information:");
        // checkingAccount.display();

        // scanner.close();

        // InputHelper inputHelper = new InputHelper();
        // Student student = inputHelper.getStudent();

        // student.print();

        // inputHelper.close();

        ErrorTest error = new ErrorTest();

        error.test();

    }
}

class ErrorTest {

    void test() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Hello World!");

        try {
            System.out.print("Enter a int: ");
            // int number = scanner.nextInt();

            // System.out.print("Your name is: " + number);

            throw new CustomError("Custom Error");

        } catch (CustomError e) {
            System.out.println("FUCK It");

        }

        catch (Exception e) {

            if (e instanceof CustomError) {
                System.out.println("I AM FRIM CUSK KSJ");

            }

            if (e instanceof java.util.InputMismatchException) {
                System.out.println("Error: InputMismatchException LOLOLOL");
            }

            System.out.println("Error: " + e);
        }

        scanner.close();

    }
}

class CustomError extends Exception {
    public CustomError(String message) {
        super(message);
    }
}

enum Subject {
    MATHS, PHYSICS, CHEMISTRY, BIOLOGY, ENGLISH, HINDI, SANSKRIT, HISTORY, GEOGRAPHY, CIVICS, ECONOMICS,

}

class Person {

    public String name;
    public int age;

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public void print() {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
    }
}

class Student extends Person {

    private double gpa;
    private Subject majorSubject;

    public Student(String name, int age, double gpa, Subject majorSubject) {
        super(name, age);

        this.gpa = gpa;
        this.majorSubject = majorSubject;
    }

    @Override
    public void print() {
        super.print();
        System.out.println("GPA: " + gpa);
        System.out.println("Major Subject: " + majorSubject);
    }

}

class InputHelper {
    private Scanner scanner;

    public InputHelper() {
        scanner = new Scanner(System.in);
    }

    Student getStudent() {
        System.out.print("Enter the name: ");
        String name = scanner.nextLine();

        System.out.print("Enter the age: ");
        int age = scanner.nextInt();

        System.out.print("Enter the GPA: ");
        double gpa = scanner.nextDouble();

        // Subject[] subjects = Subject.values();

        // for (int i = 0; i < subjects.length; i++) {
        // System.out.println((i + 1) + ". " + subjects[i]);
        // }

        System.out.print("Enter the major subject: ");
        String majorSubject = scanner.nextLine();

        return new Student(name, age, gpa, Subject.valueOf(majorSubject));
    }

    public void close() {
        scanner.close();
    }
}