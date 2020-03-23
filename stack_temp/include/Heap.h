#pragma once

#include <iostream>
using namespace std;

struct El {
	int data;
	int priority = 0;
};

class Heap
{
	El* Arr;
	int size;
	int end;

public:

	Heap() {
		Arr = new El[1];
		int end = 0;
		size = 10;
	}

	int leftchild(int _i) {
		return 2 * _i + 1;
	}

	int rightchild(int _i) {
		if ((2 * _i + 2) > end - 1)
			return 2 * _i + 1;
		else
		return 2 * _i + 2;
	}

	int parent(int _i) {
		return (_i - 1)/2;
	}

	int minchild(int _i) {
		if (Arr[leftchild(_i)].priority < Arr[rightchild(_i)].priority)
			return leftchild(_i);
		else
			return rightchild(_i);
	}

	void diving(int i){
		int j1, j2;
		j1 = i;
		j2 = minchild(i);
		while (Arr[j1].priority > Arr[j2].priority && j2 < end) {
			swap(Arr[j1], Arr[j2]);
			j1 = j2;
			j2 = minchild(j1);
		}
	}

	void emersion(int i) {
		int j1, j2;
		j1 = i;
		j2 = parent(i);
		while (Arr[j1].priority < Arr[j2].priority&& j2 >= 0) {
			swap(Arr[j1], Arr[j2]);
			j1 = j2;
			j2 = parent(j1);
		}
	}

	void Insert(El a) {
		if (end < size - 1) {
			Arr[end] = a;
			emersion(end);
			end++;
		}
		else {
			El* Tmp = new El[size + size / 3 + 1];
			for (int i = 0; i < size; ++i)
				Tmp[i] = Arr[i];
			delete[] Arr;
			Arr = Tmp;
			Arr[end] = a;
			emersion(end);
			end++;
		}
	}

	void DeleteMin(int i) {
		swap(Arr[0], Arr[end-1]);
		end--;
		diving(0);
	}

	void decreaseWeight(int i,int delta) {
		Arr[i].priority = Arr[i].priority - delta;
		emersion(i);
	}

	void Delete(int i) { 
		decreaseWeight(i,Arr[i].priority);
		DeleteMin(i);
	}


	friend ostream& operator<<(ostream& out, Heap& v)
	{
		for (int i = 0; i < v.end; i++)
			out << v.Arr[i].data;
		return out;
	}

};

