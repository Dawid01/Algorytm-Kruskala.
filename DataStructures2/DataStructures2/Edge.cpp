#include "Edge.h"

Edge::Edge() {}

Edge::Edge(int v1, int v2, int w) {
	this->v1 = v1;
	this->v2 = v2;
	this->w = w;
}


bool Edge::ASC(Edge e1, Edge e2) { return e1.w > e2.w; }
bool Edge::DSC(Edge e1, Edge e2) { return e1.w < e2.w; }

int Edge::getV1() { return v1; }
int Edge::getV2() { return v2; }
int Edge::getW() { return w; }

string Edge::toString() {
	return "[" + to_string(v1) + ", " + to_string(v2) + ", " + to_string(w) + "]";
}
