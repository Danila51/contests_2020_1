#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <string>
using namespace std;

class Train
{
private:
	double weight, // масса
		   speed, // скорость
		   coordinate; // координата
public:
	Train(double weight_value)
		: weight(weight_value), coordinate(0) // список инициализации
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

class GasHolder
{
private:
	const float R = 8.31; // газова€ посто€нна€
	float temperature, // температура газа
		   pressure, // давление газа
		   molar_mass = 0, // мол€рна€ масса газа
		   mass = 0, // масса газа
		   volume; //объем

public:
	GasHolder(float v)
		:volume(v), temperature(273)
	{
	}

	~GasHolder()
	{
	}

	void inject(float m, float M)
	{
		if (mass != 0){
			molar_mass = (mass + m) / ((mass / molar_mass)+(m / M));
			mass += m;
		}
		else {
			molar_mass = M;
			mass = m;
		}
	}

	void heat(float dT)
	{
		temperature += dT;
	}

	void cool(float dT)
	{
		if (temperature - dT < 0)
			{
			temperature = 0;
		}
		else
		{
			temperature -= dT;
		}

	}

	float getPressure()
	{
		pressure = R * temperature * mass / (volume * molar_mass);
		return pressure;
	}
};


class SpacePort
{
private:
	bool *port;
	unsigned int portsize;

public:
	SpacePort(unsigned int size)
	{
		port = new bool[size]{};
		portsize = size;
	}

	~SpacePort()
	{
		delete[] port;
	}

	bool requestLanding(unsigned int dockNumber)
	{
		if ((dockNumber >= portsize) ||(port[dockNumber] == true))
		{
			return false;
		}
		else
		{
			port[dockNumber] = true;
			return true;
		}

	}

	bool requestTakeoff(unsigned int dockNumber)
	{
		if ((dockNumber >= portsize) ||(port[dockNumber] == false))
		{
			return false;
		}
		else
		{
			port[dockNumber] = false;
			return true;
		}
	}
};

int main() {
	SpacePort s(5);

cout << boolalpha << s.requestLanding(0) << endl;

cout << boolalpha << s.requestLanding(4) << endl;

cout << boolalpha << s.requestLanding(5) << endl;

cout << boolalpha << s.requestTakeoff(0) << endl;

cout << boolalpha << s.requestTakeoff(4) << endl;

cout << boolalpha << s.requestTakeoff(5) << endl;
	return 0;
}

