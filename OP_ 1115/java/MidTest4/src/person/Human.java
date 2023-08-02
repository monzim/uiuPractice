package person;

public class Human {
    public Human() {
        Person person = new Person();

        person.iAmPublic = "I am public from Human";
        System.out.println("I am a human");
    }

}
