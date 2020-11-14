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
	GasHolder(float v) : volume(v), temperature(273)
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
