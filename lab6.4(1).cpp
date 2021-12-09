#include <iostream>
#include <iomanip>
#include <time.h>
#include <Windows.h>

using namespace std;

void Create(double*& a, const int size, const double Low, const double High)
{
	a = new double[size];
	for (int i = 0; i < size; i++)
		a[i] = (High-Low) * rand()/RAND_MAX + Low;
}
void Print(double* a, const int size)
{
	for (int i = 0; i < size; i++)
		cout << setw(10)<< a[i];
	cout << endl;
}
void Sum(double* a, const int size, double& s, int& k)
{
	for (int i = 0; i < size; i++)
	{
		if (a[i] > 0) {
			s += a[i];
			k++;
		}
	}
}
void IndMax(double* a, const int size, int& indexmax, double& max)
{
	for (int i = 0; i < size; i++)
	{
		if (abs(a[i]) > abs(max))
		{
			max = a[i];
			indexmax = i;
		}
	}
		
}
void IndMin(double* a, const int size, int& indexmin, double& min)
{
	min = a[0];
	for (int i = 0; i < size; i++)
	{
		if (abs(a[i]) < abs(min))
		{
			min = a[i];
			indexmin = i;
		}
	}

}
void Product(double* a, const int size, int& indexmin, int& indexmax, double& product)
{
	if (indexmin > indexmax)
	{
		for (int i = indexmax+1; i < indexmin; i++)
		{
			product *= a[i];
		}
	}
	else
	{
		for (int i = indexmin+1; i < indexmax; i++)
		{
			product *= a[i];
		}
	}
}
void Sort(double* a, const int size) 
{
	for (int i = 1; i < size; i++) 
	for (int j = 0; j < size - i; j++) 
			if (a[j] < a[j + 1])
			{ 
				double tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
}
int main()
{
	SetConsoleOutputCP(1251);

	srand((unsigned)time(NULL));

	int n;
	cout << "Кількість елементів масиву ="; cin >> n;
	double* a;

	double s = 0;
	int k = 0;

	double Low = -30.5;
	double High = 100.5;

	int indexmin = 0;
	int indexmax = 0;
	double min;
	double max = 0;

	double d = 0;
	double product = 1;
	Create(a, n, Low, High);
	cout << "Масив: "; Print(a, n);
	Sum(a, n, s, k);
	cout << "Сума додатних елементів = "<< s<< endl;
	IndMax(a, n, indexmax, max);
	cout << "Індекс максимального елемента =" << indexmax<< endl;
	IndMin(a, n, indexmin, min);
	cout << "Індекс мінімального елемента =" << indexmin<< endl;
	Product(a, n, indexmin, indexmax, product);
	cout << "Добуток =" << product<<endl;
	Sort(a, n);
	cout << "Впорядкований за спаданням масив:"; Print(a, n);

}