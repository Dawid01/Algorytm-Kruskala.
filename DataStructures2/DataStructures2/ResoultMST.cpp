#include "ResoultMST.h"

ResoultMST::ResoultMST() {}

ResoultMST::ResoultMST(int w, Edge* resoult, int size, int time) {
	this->weight = w;
	this->resoult = resoult;
	this->size = size;
	this->time = time;
}

int ResoultMST::getWeight() { return weight; }
Edge* ResoultMST::getResoult() { return resoult; }
string ResoultMST::toString(bool printMSTEdges) {
	string value = "Waga MST: " + to_string(weight) + "\n";
	if (printMSTEdges) {
		for (int i = 0; i < size; i++) {
			if (i == 0) {
				value = value + resoult[i].toString();
			}
			else
			{
				value = value + ", " + resoult[i].toString();
			}
		}
		value = value + "\n" + "Czas liczenia: " + to_string(time) + "ms\n";
	}
	else
	{
		value = value + "Czas liczenia: " + to_string(time) + "ms\n";

	}
	return value;
}

int ResoultMST::getTime() { return time; }