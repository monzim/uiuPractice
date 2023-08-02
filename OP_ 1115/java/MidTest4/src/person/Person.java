package person;

public class Person {
    static int iAmStatic = 100;

    String iAmDefault = "I am default";
    private String iAmPrivte;
    protected String iAmProtected;
    public String iAmPublic;

    public Person() {
        this.iAmPrivte = "I am private";
        this.iAmProtected = "Pasword";
        this.iAmPublic = "public";
    }

    String getPrivate() {
        return this.iAmPrivte;
    }

    public static void staticMethod() {
        System.out.println("I am static" + iAmStatic);
    }

    public void publicMethod() {
        System.out.println("I am public");
    }

    protected void protectedMethod() {
        System.out.println("I am protected");

        iAmPrivteMethod("protectedMethod");
    }

    private void iAmPrivteMethod(String from) {
        System.out.println("I am private " + from);
    }

}