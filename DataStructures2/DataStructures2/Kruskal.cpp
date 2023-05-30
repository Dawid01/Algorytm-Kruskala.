#include "Kruskal.h"

struct UnionFind
{
	vector<int> parent;
	vector<int> rank;

	UnionFind(int n) {
		parent.resize(n);
		rank.resize(n, 0);
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}

	int find(int x) {
		if (parent[x] != x) {
			parent[x] = find(parent[x]);
		}
		return parent[x];
	}

	void unionSets(int x, int y) {
		int rootX = find(x);
		int rootY = find(y);
		if (rootX != rootY) {
			if (rank[rootX] < rank[rootY]) {
				parent[rootX] = rootY;
			}
			else if (rank[rootX] > rank[rootY]) {
				parent[rootY] = rootX;
			}
			else {
				parent[rootY] = rootX;
				rank[rootX]++;
			}
		}
	}
};

ResoultMST Kruskal::getMiniTree(Edge* tab, int size, const int method) {
	switch (method)
	{
		case Kruskal::LIST:
			return getMiniTreeList(tab, size);
			break;
		case Kruskal::QUEUE:
			return getMiniTreeQueue(tab, size);
			break;
	}
	return ResoultMST();
}

ResoultMST Kruskal::getMiniTreeQueue(Edge* tab, int size) {
	PriorityQueue<Edge> queue = PriorityQueue<Edge>(size, Edge::ASC);
	Edge* resoult = new Edge[size];
	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < size; i++) {
		queue.push(tab[i]);
	}
	int count = 0, index = 0, weight = 0;
	UnionFind uf(size);
	while (index < size)
	{
		Edge edge = queue.top();
		queue.pop();

		int rootV1 = uf.find(edge.getV1());
		int rootV2 = uf.find(edge.getV2());
		if (rootV1 != rootV2) {
			resoult[count] = edge;
			weight += edge.getW();
			count++;
			uf.unionSets(rootV1, rootV2);
		}
		index++;
	}
	auto end = std::chrono::high_resolution_clock::now();
	auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	return ResoultMST(weight, resoult, count, time.count());
}

ResoultMST Kruskal::getMiniTreeList(Edge* tab, int size) {
	LinkedList<Edge> list = LinkedList<Edge>();
	Edge* resoult = new Edge[size];
	for (int i = 0; i < size; i++) {
		list.add(tab[i]);
	}
	auto start = std::chrono::high_resolution_clock::now();
	int left = 0;
	int right = list.getSize() - 1;
	list.quickSort(left, right, Edge::ASC);
	int count = 0, index = 0, weight = 0;
	UnionFind uf(size);
	while (index < size)
	{
		Edge edge = list.get(0);
		list.remove(0);

		int rootV1 = uf.find(edge.getV1());
		int rootV2 = uf.find(edge.getV2());
		if (rootV1 != rootV2) {
			resoult[count] = edge;
			weight += edge.getW();
			count++;
			uf.unionSets(rootV1, rootV2);
		}
		index++;
	}
	auto end = std::chrono::high_resolution_clock::now();
	auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	return ResoultMST(weight, resoult, count, time.count());
}




