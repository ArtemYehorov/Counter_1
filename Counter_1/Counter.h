#include<iostream>
#include<conio.h>
#include<Windows.h>

#pragma once

using namespace std;

class Counter
{
	int current;
	int maxCurrent;
	int minCurrent;
	int currentUP;
	int currentDown;

public:
	Counter();
	Counter(int Max_C, int Min_C);
	Counter(int Max_C, int Min_C, int C, int C_Up, int C_Down);

	void Print();
	void Speed();

	int CurrentOneUp();
	int CurrentMoreUp(int Num);
	int CurrentStepUP();

	void SetCurrentUpSpeed(int Up);
	void SetMaxCurrent(int Max);
	void SetMinCurrent(int Min);

	int GetCurrent() const;
	int GetMaxCurrent() const;
	int GetMinCurrent() const;


private:

	int HardBraking();
};

