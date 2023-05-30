#pragma once

template <typename T>
struct Element
{
	T data;
	Element<T>* next;
	Element<T>* back;
};

template <typename T>
class LinkedList
{
private:
	Element<T>* first = nullptr;
	Element<T>* last = nullptr;
	int size = 0;


	//O(n)
	Element<T>* getElement(int index) {
		if (index < 0 || index >= size) {
			return nullptr;
		}

		if (index == size - 1) {
			return last;
		}

		Element<T>* temp = first;
		int i = 0;
		while (temp != nullptr && i < index) {
			temp = temp->next;
			i++;
		}

		return temp;
	}

public:

	LinkedList() {
		first = NULL;
		last = NULL;
	}
	//O(1)
	void add(T data) {
		Element<T>* newElement = new Element<T>;
		newElement->data = data;
		newElement->next = NULL;
		newElement->back = last;
		if (last != NULL) {
			last->next = newElement;
		}
		last = newElement;
		if (first == NULL) {
			first = last;
		}
		size++;
	}

	//O(n)
	void add(T data, int index) {

		if (index <= size) {
			Element<T>* newElement = new Element<T>;

			Element<T>* temp = first;
			int i = 0;
			while (temp != NULL && i < index - 1)
			{
				temp = temp->next;
				i++;
			}
			if (temp != NULL) {

				newElement->data = data;
				newElement->back = temp;
				newElement->next = temp->next;
				temp->next = newElement;
			}

			if (index == 0) {
				first = newElement;
			}
			else if (index == size) {
				last = newElement;
			}
		}

		Element<T>* newElement = new Element<T>;
		newElement->data = data;
		newElement->next = NULL;
		newElement->back = last;
		if (last != NULL) {
			last->next = newElement;
		}
		last = newElement;
		if (first == NULL) {
			first = last;
		}
		size++;
	}
	//O(n)
	T get(int index) {

		if (index == size - 1) {
			return last->data;
		}
		if (index < size) {
			Element<T>* temp = first;
			int i = 0;
			while (temp != NULL && i < index)
			{
				temp = temp->next;
				i++;
			}
			if (temp != NULL) {
				return temp->data;
			}
		}
		return T();
	}

	//O(n)
	void remove(int index) {
		if (index < 0 || index >= size) {
			return;
		}
		Element<T>* temp = first;
		if (index == 0) {
			first = temp->next;
			if (first != nullptr) {
				first->back = nullptr;
			}
		}
		else if (index == size - 1) {
			temp = last;
			last = temp->back;
			last->next = nullptr;
		}
		else {
			int currentIndex = 0;
			while (currentIndex < index) {
				temp = temp->next;
				currentIndex++;
			}
			temp->back->next = temp->next;
			temp->next->back = temp->back;
		}
		delete temp;
		size--;
	}

	int indexOf(T& data) {
		Element<T>* temp = first;
		int i = 0;
		while (temp != NULL && i < size)
		{
			if (temp->data == data) {
				return i;
			}
			temp = temp->next;
			i++;
		}
		return NULL;
	}

	//O(n)
	void replace(int index, T newData) {
		Element<T>* temp = first;
		int i = 0;
		while (temp != NULL && i < index)
		{
			temp = temp->next;
			i++;
		}
		if (temp != NULL) {
			temp->data = newData;
		}
	}

	//O(1)
	int getSize() {
		return size;
	}

	//O(1)
	bool isEmpty() {
		return size == 0;
	}

	void swap(int v1, int v2) {
		Element<T>* e1 = getElement(v1);
		Element<T>* e2 = getElement(v2);
		T temp = e1->data;
		e1->data = e2->data;
		e2->data = temp;
	}

	void quickSort(int left, int right, bool (*cmp)(T, T)) {
		if (left < right) {
			T pivot = get(left);
			int i = left + 1;

			for (int j = left + 1; j <= right; j++) {
				if (!cmp(get(j), pivot)) {
					swap(i, j);
					i++;
				}
			}
			int pivotIndex = i - 1;
			swap(left, i - 1);
			quickSort(left, pivotIndex - 1, cmp);
			quickSort(pivotIndex + 1, right, cmp);
		}
	}
};

