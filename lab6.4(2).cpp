#include <iostream>
#include <iomanip>
#include <time.h>
#include <Windows.h>

using namespace std;

void Create(double*& a, const int size, const double Low, const double High, int i)
{
	if (i == 0)
	a = new double[size];
	if (i < size)
	{
		a[i] = (High - Low) * rand() / RAND_MAX + Low;
		return Create(a, size, Low, High, ++i);
	}

}
void Print(double*& a, const int size, int i)
{
	cout << setw(10) << a[i];
	if (i < size-1)
		Print(a, size, i+1);
	else
		cout << endl;
}
void Sum(double* a, const int size, double& s, int& k, int i)
{
	if (a[i] > 0) {
		s += a[i];
		k++;
	}
	if (i < size - 1) 
	{
		Sum(a, size, s, k, i + 1);
	}
}
void IndMax(double* a, const int size, int& indexmax, double& max, int i)
{
	if (abs(a[i]) > abs(max))
	{
		max = a[i];
		indexmax = i;
	}
	if (i < size - 1)
	{
		IndMax(a, size, indexmax, max, i + 1);
	}
}
void IndMin(double* a, const int size, int& indexmin, double& min, int i)
{
	min = a[0];
	if (abs(a[i]) < abs(min))
	{
		min = a[i];
		indexmin = i;
	}
	if (i < size - 1)
	{
		IndMin(a, size, indexmin, min, i + 1);
	}
}
void Product(double* a, const int size, int& indexmin, int& indexmax, double& product)
{
	if (indexmin > indexmax)
	{
		for (int i = indexmax + 1; i < indexmin; i++)
		{
			product *= a[i];
		}
	}
	else
	{
		for (int i = indexmin + 1; i < indexmax; i++)
		{
			product *= a[i];
		}
	}
}
void Sort(double* a, const int size, int i) 
{
	for (int j = 0; j < size - i; j++) 
		if (a[j] < a[j + 1]) 
		{ 
			double tmp = a[j];
			a[j] = a[j + 1];
			a[j + 1] = tmp;
		}
	if (i < size) 
		Sort(a, size, ++i);
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
	double product = 1;
	Create(a, n, Low, High, 0);
	cout << "Масив: "; Print(a, n, 0);
	Sum(a, n, s, k, 0);
	cout << "Сума додатних елементів = " << s << endl;
	IndMax(a, n, indexmax, max, 0);
	cout << "Індекс максимального елемента =" << indexmax << endl;
	IndMin(a, n, indexmin, min, 0);
	cout << "Індекс мінімального елемента =" << indexmin << endl;
	Product(a, n, indexmin, indexmax, product);
	cout << "Добуток =" << product << endl;
	Sort(a, n, 0);
	cout << "Впорядкований за спаданням масив:"; Print(a, n, 0);

}