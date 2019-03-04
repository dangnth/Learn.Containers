#include <iostream>

using namespace std;

class Vector {
public:
	Vector(int size = 0);
	~Vector();

	void PushBack(int value);
	int GetBegin();
	int GetEnd();
	int GetMaxSize();
	Vector GetIter(int index);
private:
	int m_iSize;
	int *m_iArray;
};

Vector Vector::GetIter(int index) {
	return this->m_iArray[index];
}

Vector::Vector(int size = 0) {
	this->m_iArray = new int[size];
	this->m_iSize = size;
}

Vector::~Vector() {
	delete[] this->m_iArray;
	this->m_iArray = nullptr;
	this->m_iSize = 0;
}

int Vector::GetBegin() { return 0; };
int Vector::GetEnd() { return this->m_iSize; };
int Vector::GetMaxSize() { return this->m_iSize * 2; };

void Vector::PushBack(int value) {
	this->m_iSize++;
	this->m_iArray[this->m_iSize] = value;
}

void main() {
	Vector Arr(100);
	for (auto i = Arr.GetBegin(); i < Arr.GetEnd(); i++)
		Arr.PushBack(i);

	system("pause");
}