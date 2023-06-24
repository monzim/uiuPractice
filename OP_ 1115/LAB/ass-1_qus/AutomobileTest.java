
public class AutomobileTest {
	public static void main(){
		Car car = new Car("Automatic");
		car.SetInitialPosition(new Coordinate(10,30));
		car.SetInitialDirection(new Coordinate(10,30));
		car.TurnLeft();
		car.Move();
		car.Move();
		car.Move();
		car.TurnRight();
		car.IncreaseSpeed();
		
		Truck truck = new Truck("manual");
		truck.Move(); // error
		truck.ShiftGearUp();
		truck.IncreaseSpeed();//4
		truck.IncreaseSpeed();//8
		truck.Move();
		truck.IncreaseSpeed();//12
		truck.IncreaseSpeed();//16
		truck.IncreaseSpeed();//20
		truck.IncreaseSpeed();//24 error.
	}
}
