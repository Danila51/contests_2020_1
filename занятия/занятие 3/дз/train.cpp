class Train
{
private:
	double weight, // масса
		   speed, // скорость
		   coordinate; // координата
public:
	Train(double m) : weight(m), coordinate(0)
	{
	}

	void move(double dt){
		coordinate += dt * speed;
	}

	void accelerate(double dp){
		speed += dp / weight;
	}

	double getX() {
		return coordinate;
	}
};
