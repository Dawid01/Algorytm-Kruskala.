#pragma once
#include <iostream>

using namespace std;

template <typename T>
class Heap
{
public:
	Heap() {}

	static void makeHeap(T*& tab, int size, bool (*cmp)(T, T)) {
		for (int i = size / 2; i > 0; i--) {
			shiftDown(tab, size, i, cmp);
		}
	}
	static void shiftDown(T*& tab, int size, int index, bool (*cmp)(T, T)) {
		int next = index * 2;
		while (next <= size)
		{
			if (next < size && cmp(tab[next], tab[next + 1])) {
				next++;
			}
			if (cmp(tab[index], tab[next])) {
				swap(tab[index], tab[next]);
				index = next;
				next *= 2;
			}
			else {
				next = size + 1;
			}
		}
	}
	static void shiftUp(T*& tab, int size, int index, bool (*cmp)(T, T)) {
		int next = index / 2;
		while (index > 1 && cmp(tab[next], tab[index]))
		{
			swap(tab[index], tab[next]);
			index = next;
			next /= 2;
		}
	}
	static void push(T*& tab, T t, int& size, bool (*cmp)(T, T)) {
		tab[++size] = t;
		shiftUp(tab, size, size, cmp);
	}
	static void pop(T*& tab, int& size, bool (*cmp)(T, T)) {
		swap(tab[1], tab[size--]);
		shiftDown(tab, size, 1, cmp);
	}
	static void sortHeap(T*& tab, int size, bool (*cmp)(T, T)) {
		makeHeap(tab, size, cmp);
		while (size > 1) {
			pop(tab, size, cmp);
		}
	}
};

