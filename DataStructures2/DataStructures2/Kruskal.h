#pragma once
#include "PriorityQueue.h"
#include "LinkedList.h"
#include "Edge.h"
#include "ResoultMST.h"
#include <vector>
#include <chrono>

using namespace std;

class Kruskal
{

private:
	static ResoultMST getMiniTreeQueue(Edge* tab, int size);
	static ResoultMST getMiniTreeList(Edge* tab, int size);
public:

	static const int QUEUE = 0;
	static const int LIST = 1;

	static ResoultMST getMiniTree(Edge* tab, int size, const int metod);

};

