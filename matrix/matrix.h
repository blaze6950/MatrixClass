#pragma once
class matrix
{
public:
	friend matrix operator+ (const matrix& m1, const matrix& m2);
	friend matrix operator- (const matrix& m1, const matrix& m2);
	friend matrix operator- (const matrix& m1);
	friend matrix operator*(const matrix& m1, const matrix& m2);
	friend matrix operator*(int num, const matrix& m2);
	friend matrix operator*(const matrix& m1, int num);
	matrix& operator=(const matrix& m1);

	matrix(int x, int y);
	matrix(const matrix& m);//����������� �����������
	~matrix();

	void getMatrix();
	void writeToMatrix(int x, int y, int number);
	void transposition();

private:
	int** _mat = nullptr;// ��������� �� ��������� ������, �.�. �������
	int _x, _y;//������ � ������
};

