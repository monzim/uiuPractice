public class Truck extends AutomobileWithManualXmission{

	Truck(String type) {
		super(type);
		// initialize fuel
		fuel = 100;
	}
	
	@Override
	void TurnLeft() {
		// TODO Auto-generated method stub
		super.TurnLeft();
	}
	
	@Override
	void TurnRight() {
		// TODO Auto-generated method stub
		super.TurnRight();
	}
	
	@Override
	void IncreaseSpeed() {
		// you can not increase your speed beyond current gear position's high limit.
		//if(speed + amount > currentHighLimit) error
		switch (gearPosition) {
			case 0:
				
				break;
			case 1:
				
						
				break;
			case 2:
				
				break;
			case 3:
				
				break;
			case 4:
				
				break;
				
			case 5:
				
				break;
			default:
				break;
		}
	}
	
	@Override
	void DecreaseSpeed() {
		// you can not decrease your speed below current gear position's low limit.
		//if(speed - amount < currentLowLimit) error
		switch (gearPosition) {
			case 0:
				
				break;
			case 1:
				
						
				break;
			case 2:
				
				break;
			case 3:
				
				break;
			case 4:
				
				break;
				
			case 5:
				
				break;
			default:
				break;
		}
	}
	
	//check for gear position. if it is 0 then print that you need to increase your gear first.
	@Override
	void Move() {
		
	}

}
