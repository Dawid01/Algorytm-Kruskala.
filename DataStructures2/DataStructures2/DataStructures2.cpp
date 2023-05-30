#include <iostream>
#include "Kruskal.h"
#include "PriorityQueue.h"
#include "Edge.h"
#include "FileReader.h"

using namespace std;


int main()
{

   cout << "WCZYTYWANIE DANYCH Z PLIKU..." << endl;
   FileReaderResoult resoult = FileReader::getEdgesFromFile("Graphs/g1.txt");
   system("CLS");
   /*for (int i = 100; i <= 4000; i += 100) {

	   /*cout << "KOLEJKA" << endl;
	   ResoultMST mstQ = Kruskal::getMiniTree(resoult.edges, i, Kruskal::QUEUE);
	   cout << mstQ.toString(false) << endl;
	   /*cout << "LISTA" << endl;
	   ResoultMST mstL = Kruskal::getMiniTree(resoult.edges, i, Kruskal::LIST);
	   cout << mstL.toString(false) << endl;
	   ResoultMST mst = Kruskal::getMiniTree(resoult.edges, i, Kruskal::QUEUE);
	   cout << to_string(i) << " " << mst.getTime() << endl; 
   }*/

   ResoultMST mst = Kruskal::getMiniTree(resoult.edges, resoult.size, Kruskal::QUEUE);
   cout << mst.toString(true) << endl;
   mst = Kruskal::getMiniTree(resoult.edges, resoult.size, Kruskal::LIST);
   cout << mst.toString(true) << endl;

   cout << endl << "KONIEC";
   return 0;
}


