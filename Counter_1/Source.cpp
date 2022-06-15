#include"Counter.h"

int main()
{
	Counter p;
	p.SetMinCurrent(13);
	p.SetMaxCurrent(300);
	//p.CurrentOneUp();
	p.CurrentMoreUp(0);
	//p.CurrentStepUP();
	p.SetCurrentUpSpeed(10);

	p.Print();
	p.Speed();
}