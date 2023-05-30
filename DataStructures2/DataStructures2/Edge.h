#pragma once
#include <iostream>
#include <string> 
#include <sstream>

using namespace std;
class Edge
{
private:
	int v1, v2, w;
public:
	Edge();
	Edge(int v1, int v2, int w);

	static bool ASC(Edge e1, Edge e2);
	static bool DSC(Edge e1, Edge e2);

	int getV1();
	int getV2();
	int getW();

	string toString();
};

