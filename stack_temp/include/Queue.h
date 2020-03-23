#pragma once
#include "iostream"
#include "stdio.h"
using namespace std;
class Queue
{
	int end;
	int begin;
	int* Arr;
	int size;
	int counter;
public:
	Queue() 
	{
		size = 2;
		Arr = new int[size];
		begin = 0;
		end = 1;
	}

	Queue(int _size)
	{
		if (_size <= 1)
			throw 0;
		else {
			size = _size;
			Arr = new int[size];
			begin = 0;
			end = 1;
		}
	}

	int Size()
	{
		return size;
	}

	void Push(int a)
	{
		if (begin == end)
		{
			int* Tmp = new int[size + size / 3 + 1];
			for (int i = 0; i < size; ++i)
				Tmp[i] = Arr[(begin + i) % size];
			delete[] Arr;
			Arr = Tmp;
			begin = 0;
			end = size;
			size = size + size / 3 + 1;
		}
		Arr[(end - 1) % size] = a;
		end = (end + 1) % size;
		++counter;
	}

	int top()
	{
		if (empty())
			throw 0;
		return Arr[begin];
	}

	int pop()
	{
		if (empty())
			throw 0;
		begin = (begin + 1) % size;
		--counter;
	}

	bool empty()
	{
		if (counter == 0)
			return true;
		else
			return false;
	}

	~Queue()
	{
		delete[] Arr;
	}
};


