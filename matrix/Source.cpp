#include "matrix.h"
#include <iostream>
using namespace std;

void main()
{
	matrix m1(4, 4);
	m1.writeToMatrix(0, 0, 2);
	m1.writeToMatrix(0, 1, 4);
	m1.writeToMatrix(0, 2, 6);
	m1.writeToMatrix(0, 3, 3);

	m1.writeToMatrix(1, 0, 1);
	m1.writeToMatrix(1, 1, 3);
	m1.writeToMatrix(1, 2, 5);
	m1.writeToMatrix(1, 3, 4);

	m1.writeToMatrix(2, 0, 7);
	m1.writeToMatrix(2, 1, 8);
	m1.writeToMatrix(2, 2, 9);
	m1.writeToMatrix(2, 3, 2);

	m1.writeToMatrix(3, 0, 2);
	m1.writeToMatrix(3, 1, 9);
	m1.writeToMatrix(3, 2, 8);
	m1.writeToMatrix(3, 3, 7);
	m1.getMatrix();

	matrix m2(4, 3);
	m2.writeToMatrix(0, 0, 1);
	m2.writeToMatrix(0, 1, 2);
	m2.writeToMatrix(0, 2, 3);
	//m2.writeToMatrix(0, 3, 4);

	m2.writeToMatrix(1, 0, 5);
	m2.writeToMatrix(1, 1, 6);
	m2.writeToMatrix(1, 2, 7);
	//m2.writeToMatrix(1, 3, 8);

	m2.writeToMatrix(2, 0, 9);
	m2.writeToMatrix(2, 1, 0);
	m2.writeToMatrix(2, 2, 1);
	//m2.writeToMatrix(2, 3, 2);

	m2.writeToMatrix(3, 0, 3);
	m2.writeToMatrix(3, 1, 4);
	m2.writeToMatrix(3, 2, 5);
	//m2.writeToMatrix(3, 3, 6);

	m2.getMatrix();

	matrix m3 = m2 * m1;
	m3.getMatrix();
}