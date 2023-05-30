#pragma once
#include "Heap.h"
template <typename T>
class PriorityQueue
{
private:
	T* tab = new T[100];
	int size = 0;
	bool (*cmp)(T, T);

public:
	PriorityQueue(int maxSize, bool (*c)(T, T)) {
		tab = new T[maxSize];
		cmp = c;
	}
	
	void push(T value) {
		Heap<T>::push(tab, value, size, cmp);
	}
	void pop() {
		Heap<T>::pop(tab, size, cmp);
	}
	T top() {
		return tab[1];
	}

	void setTab(T* tab, int size) {
		this->tab = tab;
		this->size = size;
	}

	void changeComperator(bool (*c)(T, T)) {
		cmp = c;
	}

	int getSize() {
		return size;
	}

	T getFromTab(int index) {
		return tab[index];
	}
};

