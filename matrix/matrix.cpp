#include "matrix.h"
#include <iostream>
using namespace std;


matrix::matrix(int x, int y)
{
	_x = x;
	_y = y;
	_mat = new int*[y];
	for (size_t i = 0; i < y; i++)
	{
		_mat[i] = new int[x];
		for (size_t j = 0; j < x; j++)
		{
			_mat[i][j] = 0;
		}
	}
}

matrix::matrix(const matrix& m)
{
	_x = m._x;
	_y = m._y;
	_mat = new int*[_y];
	for (size_t i = 0; i < _y; i++)
	{
		_mat[i] = new int[_x];
		for (size_t j = 0; j < _x; j++)
		{
			_mat[i][j] = m._mat[i][j];
		}
	}
}

matrix::~matrix()
{
	for (size_t i = 0; i < _y; i++)
	{
			delete[] _mat[i];
	}
	delete[] _mat;
	_mat = nullptr;
}

void matrix::getMatrix()
{
	for (size_t i = 0; i < _y; i++)
	{
		for (size_t j = 0; j < _x; j++)
		{
			cout << _mat[i][j] << " ";
		}
		cout << endl;
	}
	cout << "=========================================\n";
}

void matrix::writeToMatrix(int x, int y, int number)
{
	if (x < _x && y < _y){
		_mat[y][x] = number;
	}
	else{
		cerr << "Error : your x > _x or your y > _y\n";
	}
}

void matrix::transposition()
{
	for (size_t i = 0; i < _y; i++)
	{
		for (size_t j = i; j < _x; j++)
		{
			if (i != j)
			{
				_mat[i][j] = _mat[i][j] - _mat[j][i];
				_mat[j][i] = _mat[j][i] + _mat[i][j];
				_mat[i][j] = _mat[j][i] - _mat[i][j];
			}
		}
	}
}

matrix& matrix::operator=(const matrix& m1)
{
	if (_x == m1._x && _y == m1._y)
	{
		for (size_t i = 0; i < _y; i++)
		{
			for (size_t j = i; j < _x; j++)
			{
					_mat[i][j] = m1._mat[i][j];
			}
		}
	}
	else{
	}
	return *this;
}

matrix operator+ (const matrix& m1, const matrix& m2)
{
	if (m1._x == m2._x && m1._y == m2._y)
	{
		matrix res(m1._x, m1._y);
		for (size_t i = 0; i < m1._y; i++)
		{
			for (size_t j = 0; j < m1._x; j++)
			{
				res._mat[i][j] = m1._mat[i][j] + m2._mat[i][j];
			}
		}
		return res;
	}
	else{
		cerr << "You can't do it!\n";
	}
}

matrix operator- (const matrix& m1, const matrix& m2)
{
	if (m1._x == m2._x && m1._y == m2._y)
	{
		matrix res(m1._x, m1._y);
		for (size_t i = 0; i < m1._y; i++)
		{
			for (size_t j = 0; j < m1._x; j++)
			{
				res._mat[i][j] = m1._mat[i][j] - m2._mat[i][j];
			}
		}
		return res;
	}
	else{
		cerr << "You can't do it!\n";
	}
}

matrix operator- (const matrix& m1)
{
	matrix res = m1;
	for (size_t i = 0; i < m1._y; i++)
	{
		for (size_t j = 0; j < m1._x; j++)
		{
			res._mat[i][j] = m1._mat[i][j] * (-1);
		}
	}
	return res;
}

matrix operator*(const matrix& m1, const matrix& m2)
{
	if (m1._x == m2._x && m2._y == m1._y)
	{

	}
	else{

	}
	if (m1._x == m2._y){
		matrix res(m2._x, m1._y);
		for (size_t i = 0; i < m1._y; i++)
		{
			for (size_t j = 0; j < m2._x; j++)
			{
				for (size_t z = 0; z < m1._x; z++)
				{
					res._mat[i][j] = res._mat[i][j] + m1._mat[i][z] * m2._mat[z][j];
				}
			}
		}
		return res;
	}
}

matrix operator*(int num, const matrix& m2)
{
	matrix res(m2._x, m2._y);
	for (size_t i = 0; i < m2._y; i++)
	{
		for (size_t j = 0; j < m2._x; j++)
		{
			res._mat[i][j] = m2._mat[i][j] * num;
		}
	}
	return res;
}

matrix operator*(const matrix& m1, int num)
{
	matrix res = num * m1;
	return res;
}