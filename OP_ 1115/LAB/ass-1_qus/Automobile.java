package test;
/**
 * @author Mahbub
 *
 */

class Coordinate{
	double x;
	double y;
	
	public Coordinate(double x, double y) {
		this.x = x;
		this.y = y;
	}

	public Coordinate() {
		
	}

	public double getX() {
		return x;
	}

	public void setX(double x) {
		this.x = x;
	}

	public double getY() {
		return y;
	}

	public void setY(double y) {
		this.y = y;
	}
	
	// positive angle rotates left. rotateDirection(30)
    // negative angel rotates right. rotateDirection(-30)
    void rotateDirection(double angle) {
    	double theta = (3.1416*angle)/180;
    	double px = this.x*Math.cos(theta) - this.y*Math.sin(theta);
    	double py = this.x*Math.sin(theta) + this.y*Math.cos(theta);
    	
    	this.x = px;
    	this.y = py;
    }
}

public class Automobile {
	String type; // Stores the type of the automobile
    Coordinate position;    // Distance between origin and center position of automobile, along Y-axis (in cm)
    Coordinate direction; // Direction vector
    double speed;   // Stores speed of the automobile
    double fuel;    // Stores remaining fuel

    Automobile(String type)
    {
        this.type = type;
    }
    public Automobile() {
		
	}    
    void SetInitialPosition(Coordinate initPos)
    {
        this.position = initPos;
    }

    void SetInitialDirection(Coordinate direction)
    {
        this.direction = direction;
    }

    String GetType()
    {
        return this.type;
    }

    double GetFuel()
    {
        return fuel;
    }
    
    double GetSpeed()
    {
        return speed;
    }

    Coordinate GetPosition()
    {
        return this.position;
    }

    Coordinate GetDirection()
    {
        return this.direction;
    }

    //
    // The following functions should be overridden in derived classes.
    //
     
    // Turn left (counter clockwise) by angle mentioned in the chart, without moving forward.
	//call the rotateDirection() functions with a positive angle
    void TurnLeft() {};

    // Turn right (clockwise) by angle mentioned in the chart, without moving forward.
	//call the rotateDirection() functions with a negative angle
    void TurnRight() {};

    // Increase speed by amount mentioned in the chart, but don't move forward yet
    void IncreaseSpeed() {};

    // Decrease speed by amount mentioned in the chart, but don't move forward yet
    void DecreaseSpeed() {};

    // move forward 1 second's worth of distance
	// amount = speed * time in hour.
	// position.x = position.x + direction.x*amount 
	// position.y = position.y + direction.y*amount 
    // fuel = fuel - amount*fuel_efficiency
    void Move() {};
}

class AutomobileWithManualXmission extends Automobile{

    int gearPosition;   // Stores the current gear position

    AutomobileWithManualXmission(String type)
    {
    	super(type);
        gearPosition = 0;
    }

    void ShiftGearUp()
    {
        if (gearPosition < 5)
            gearPosition++;
    }
    void ShiftGearDown()
    {
        if (gearPosition > 0)
            gearPosition--;
    }
    
    int GetGearPosition()
    {
        return gearPosition;
    }
};