
/**
 * NestClass
 */
public class NestKClass {

    public String name;

    public InnerClass innerClass;

    public void print() {
        System.out.println("NestKClass: " + name);
    }

    public NestKClass(String name) {
        this.name = name;
        this.innerClass = new InnerClass("InnerClass");
    }

    class InnerClass {
        public String name;

        public InnerClass(String name) {
            this.name = name;
        }

        public void print() {
            System.out.println("InnerClass: " + name);
        }
    }

}