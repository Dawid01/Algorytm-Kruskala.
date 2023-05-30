#pragma once
#include "Edge.h"
#include <string> 
#include <sstream>

class ResoultMST
{
private:
	int weight, size, time;
	Edge* resoult;
public:
	ResoultMST();
	ResoultMST(int w, Edge* resoult, int size, int time);
	int getWeight();
	Edge* getResoult();
	string toString(bool printMSTEdges);
	int getTime();
};

