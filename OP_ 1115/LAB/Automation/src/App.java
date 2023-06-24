public class App {
    public static void main(String[] args) {
        Car car = new Car("Automatic");
        car.SetInitialPosition(new Coordinate(10, 30));
        car.SetInitialDirection(new Coordinate(10, 30));
        car.TurnLeft();
        car.Move();
        car.Move();
        car.Move();
        car.TurnRight();
        car.IncreaseSpeed();

        Truck truck = new Truck("manual");
        truck.Move();
        truck.ShiftGearUp();
        truck.IncreaseSpeed();
        truck.IncreaseSpeed();
        truck.Move();
        truck.IncreaseSpeed();
        truck.IncreaseSpeed();
        truck.IncreaseSpeed();
        truck.IncreaseSpeed();

        System.out.println("Car: " + car.toString());
        System.out.println("Truck: " + truck.toString());

        SUV suv = new SUV("Automatic");
        suv.SetInitialPosition(new Coordinate(10, 30));
        suv.SetInitialDirection(new Coordinate(10, 30));
        suv.TurnLeft();
        suv.Move();
        suv.Move();
        suv.Move();
        suv.TurnRight();
        suv.IncreaseSpeed();

        Bus bus = new Bus("manual");
        bus.Move();
        bus.ShiftGearUp();
        bus.IncreaseSpeed();
        bus.IncreaseSpeed();
        bus.Move();
        bus.IncreaseSpeed();
        bus.IncreaseSpeed();
        bus.IncreaseSpeed();
        bus.IncreaseSpeed();

        System.out.println("SUV: " + suv.toString());
        System.out.println("Bus: " + bus.toString());

    }
}

class Car extends Automobile {

    Car(String type) {
        super(type);

        fuel = 30;
    }

    @Override
    void TurnLeft() {
        direction.rotateDirection(5);
    }

    @Override
    void TurnRight() {
        direction.rotateDirection(-5);
    }

    @Override
    void IncreaseSpeed() {
        if (speed + 10 <= 120) {
            speed += 10;
        }
    }

    @Override
    void DecreaseSpeed() {
        if (speed - 10 >= 0) {
            speed -= 10;
        }
    }

    @Override
    void Move() {
        double amount = speed / 3600.0;
        position.setX(position.getX() + direction.getX() * amount);
        position.setY(position.getY() + direction.getY() * amount);
        fuel -= amount * 8;
    }

}

class SUV extends Automobile {

    SUV(String type) {
        super(type);

        fuel = 50;
    }

    @Override
    void TurnLeft() {
        direction.rotateDirection(10);
    }

    @Override
    void TurnRight() {
        direction.rotateDirection(-10);
    }

    @Override
    void IncreaseSpeed() {
        if (speed + 8 <= 100) {
            speed += 8;
        }
    }

    @Override
    void DecreaseSpeed() {
        if (speed - 8 >= 0) {
            speed -= 8;
        }
    }

    @Override
    void Move() {
        double amount = speed / 3600.0;
        position.setX(position.getX() + direction.getX() * amount);
        position.setY(position.getY() + direction.getY() * amount);
        fuel -= amount * 6;
    }

}

class Bus extends AutomobileWithManualXmission {

    Bus(String type) {
        super(type);

        fuel = 80;
        position = new Coordinate();
        direction = new Coordinate();
    }

    @Override
    void TurnLeft() {
        direction.rotateDirection(15);
    }

    @Override
    void TurnRight() {
        direction.rotateDirection(-15);
    }

    @Override
    void IncreaseSpeed() {
        if (speed + 6 <= 80) {
            speed += 6;
        }
    }

    @Override
    void DecreaseSpeed() {
        if (speed - 6 >= 0) {
            speed -= 6;
        }
    }

    @Override
    void Move() {
        double amount = speed / 3600.0;
        position.setX(position.getX() + direction.getX() * amount);
        position.setY(position.getY() + direction.getY() * amount);
        fuel -= amount * 4;
    }

}

class Truck extends AutomobileWithManualXmission {

    Truck(String type) {
        super(type);

        fuel = 100;
        position = new Coordinate();
        direction = new Coordinate();
    }

    @Override
    void TurnLeft() {
        direction.rotateDirection(25);
    }

    @Override
    void TurnRight() {
        direction.rotateDirection(-25);
    }

    @Override
    void IncreaseSpeed() {
        int currentHighLimit = getHighLimitForGearPosition(gearPosition);
        if (speed + 10 <= currentHighLimit) {
            speed += 10;
        }
    }

    @Override
    void DecreaseSpeed() {
        int currentLowLimit = getLowLimitForGearPosition(gearPosition);
        if (speed - 10 >= currentLowLimit) {
            speed -= 10;
        }
    }

    @Override
    void Move() {
        if (gearPosition == 0) {
            System.out.println("Please shift gear up.");
            return;
        }

        double amount = speed / 3600.0;
        position.setX(position.getX() + direction.getX() * amount);
        position.setY(position.getY() + direction.getY() * amount);
        fuel -= amount * 2;
    }

    private int getHighLimitForGearPosition(int gearPosition) {
        switch (gearPosition) {
            case 1:
                return 10;
            case 2:
                return 25;
            case 3:
                return 35;
            case 4:
                return 50;
            case 5:
                return 60;
            default:
                return 0;
        }
    }

    private int getLowLimitForGearPosition(int gearPosition) {
        switch (gearPosition) {
            case 1:
                return 0;
            case 2:
                return 10;
            case 3:
                return 25;
            case 4:
                return 35;
            case 5:
                return 50;
            default:
                return 0;
        }
    }

}
