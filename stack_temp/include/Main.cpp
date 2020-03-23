#include "Heap.h"

int main() {
	Heap a;
	El aa, bb,cc, dd, ee;
	aa.priority = 2;
	aa.data = 111;
	bb.priority = 1;
	bb.data = 222;
	cc.data = 333;
	cc.priority = 5;
	dd.data = 555;
	dd.priority = 4;
	ee.data = 666;
	ee.priority = 6;
	a.Insert(aa);
	a.Insert(bb);
	a.Insert(cc);
	a.Insert(dd);
	a.Insert(ee);
	a.Delete(1);
	cout << a;
}