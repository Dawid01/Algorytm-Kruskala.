#include "FileReader.h"

FileReaderResoult FileReader::getEdgesFromFile(string filename) {
	std::ifstream file;
    file.open(filename);

    regex regx(R"((\d+)\s+(\d+)\s+(\d+))");
    string line;
    int index = -1;
    Edge* edges = new Edge[0];
    int size = 10;
    while (!file.eof()) {
        getline(file, line);
        if (index == -1) {
            size = stoi(line);
            edges = new Edge[size];
        }
        else {
            smatch matches;
            if (regex_match(line, matches, regx)) {            
                int v1 = stoi(matches[1].str());
                int v2 = stoi(matches[2].str());
                int w = stoi(matches[3].str());
                edges[index] = Edge(v1, v2, w);       
            }
        }
        index++;
    }
    file.close();
    return FileReaderResoult(edges, size);
}