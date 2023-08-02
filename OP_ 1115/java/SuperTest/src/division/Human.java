package division;

abstract class HumanStruct {

    public abstract String getName();

    public int age;
}

public class Human extends HumanStruct {

    public String name;

    public Human(String n) {
        name = n;
    }

    @Override
    public String getName() {
        return name;
    }

    public void printAge() {
        age = 100;

        System.out.println(age);
    }
}