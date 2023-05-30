#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Edge.h"
#include <regex>

using namespace std;

struct FileReaderResoult
{
	Edge* edges;
	int size;

	FileReaderResoult(Edge* edges, int size) {
		this->edges = edges;
		this->size = size;
	}
};

class FileReader
{
public:
	static FileReaderResoult getEdgesFromFile(string filename);
};

