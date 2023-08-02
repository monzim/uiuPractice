package other.place;

public class City extends Place {
    public String city;

    void show() {
        System.out.println("City " + placeName);
        super.placeName = "Dhaka";
    }
}