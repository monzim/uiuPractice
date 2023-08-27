
class BankAccount {
    protected String holderName;
    protected String accountNumber;
    protected double balance;

    public BankAccount(String holderName, String accountNumber, double balance) {
        this.holderName = holderName;
        this.accountNumber = accountNumber;
        this.balance = balance;
    }

    public void display() {
        System.out.println("Account Holder: " + holderName);
        System.out.println("Account Number: " + accountNumber);
        System.out.println("Balance: " + balance);
    }
}

class CheckingAccount extends BankAccount {
    private double overdraft;

    public CheckingAccount(String holderName, String accountNumber, double balance, double overdraft) {
        super(holderName, accountNumber, balance);
        this.overdraft = overdraft;
    }

    @Override
    public void display() {
        super.display();
        System.out.println("Overdraft Limit: " + overdraft);
    }
}

abstract class Shape {
    protected String color;
    protected String name;

    public Shape(String color, String name) {
        this.color = color;
        this.name = name;
    }

    abstract double calculateArea();
}

class Circle extends Shape {

    private double radius;

    public Circle(String color, String name, double radius) {
        super(color, name);
        this.radius = radius;
    }

    @Override
    double calculateArea() {
        return Math.PI * radius * radius;
    }
}

class Rectangle extends Shape {

    private double width;
    private double height;

    public Rectangle(String color, String name, double width, double height) {
        super(color, name);
        this.width = width;
        this.height = height;
    }

    @Override
    double calculateArea() {
        return width * height;
    }
}