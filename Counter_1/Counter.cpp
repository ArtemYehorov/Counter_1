#include "Counter.h"

Counter::Counter() : Counter(300, 0, 0, 3, 1) {}
Counter::Counter(int Max_C, int Min_C) : Counter(Max_C, Min_C, Min_C, 3, 1) {}
Counter::Counter(int Max_C, int Min_C, int C, int C_Up, int C_Down)
{
	current = C;
	maxCurrent = Max_C;
	minCurrent = Min_C;
	currentUP = C_Up;
	currentDown = C_Down;
}

void Counter::Print()
{
	cout << "Vehicle speed - " << GetCurrent() << endl;
	cout << "Maximum vehicle speed - " << GetMaxCurrent() << endl;
	cout << "Minimum vehicle speed - " << GetMinCurrent() << endl;
}

void Counter::Speed()
{
	for (int i = minCurrent; i < maxCurrent;)
	{
		if (_getch() == 'w')
		{
			if (current < maxCurrent)
			{
				current += currentUP;
			}
			else if (current == maxCurrent)
			{
				continue;
			}
		}
		else if (_getch() == 's')
		{
			if (current == minCurrent)
			{
				continue;
			}
			else if (current - currentDown >= minCurrent)
			{
				current--;
			}
			else
			{
				current -= 10;
				system("cls");
				Print();
			}
		}
		else
		{
			if (current <= minCurrent)
			{
				continue;
			}
			else current--;
		}
		system("cls");
		Print();
		if (current == maxCurrent || current > maxCurrent)
		{
			HardBraking();
		}
	}
}

int Counter::CurrentOneUp()
{
	current += 1;
	return current;
}

int Counter::CurrentMoreUp(int Num)
{
	current += Num;
	return current;
}

int Counter::CurrentStepUP()
{
	current += currentUP;
	return current;
}

//Getters
int Counter::GetCurrent () const
{
	return current;
}
int Counter::GetMaxCurrent() const
{
	return maxCurrent;
}
int Counter::GetMinCurrent() const
{
	return minCurrent;
}

//Setters
void Counter::SetCurrentUpSpeed(int Up)
{
	currentUP = Up;
}
void Counter::SetMinCurrent(int Min)
{
	if (Min >= 0 && Min <= maxCurrent / 2)
	{
		minCurrent = Min;
	}
	else
	{
		cout << "Incorrect current!" << endl;
		Min = 0;
	}
}
void Counter::SetMaxCurrent(int Max)
{
	if (Max >= 0 && Max <= 300)
	{
		maxCurrent = Max;
	}
	else
	{
		cout << "Incorrect current!" << endl;
		Max = 200;
	}
}

int Counter::HardBraking()
{
	while (current > minCurrent)
	{
		int Stop = maxCurrent / 10;
		current -= Stop;
		system("cls");
		cout << "Hard braking!" << endl;
		Print();
	}
	current = minCurrent;
	system("cls");
	Print();
	return current;
}

