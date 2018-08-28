#include <iostream>
#include <iomanip>
#include<math.h>
#include<ctime>

using namespace std;

// 1.	Написать функцию, которая получает указатель на массив и его размер,
// и возвращает сумму и произведение его элементов в двух параметрах - указателях.

void func1(int *a, int n, int *sum, int *prod) {
	for (int i = 0; i < n; i++)
	{
		*sum += a[i];
		*prod *= a[i];
	}
}

// 2.	Написать функцию, которая получает указатель на массив и его размер,
// и возвращает количество отрицательных, положительных и нулевых элементов массива.

void func2(int *a, int n) {
	int p = 0, m = 0, z = 0;

	for (int i = 0; i < n; i++)
	{
		if (a[i]>0) p++;
		else if (a[i]<0) m++;
		else z++;
	}

	cout << "Положительных элементов: " << p << endl;
	cout << "Отрицательных элементов: " << m << endl;
	cout << "Нулевых элементов: " << z << endl << endl;
}

// 3.	Написать следующие функции для работы с динамическим массивом:

// a.функция распределения динамической памяти


// b.функция инициализации динамического массива
// case 4
void init(int *a, int n) {
	a = new int[n];

	/*delete[] a;*/
}

// c.функция печати динамического массива
// case 5
void print(int *a, int n) {
	a = new int[n];
	
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 21;
		cout << a[i] << " ";
	}
	cout << endl;

	delete[] a;
}

// d.функцию удаления динамического массива
void delete_arr(int *a) {
	delete[]a;
}

// e.функцию добавления элемента в конец массива


// f.функцию вставки элемента по указанному индексу


// g.функцию удаления элемента по указанному индексу



// 4.	Написать функцию, которая получает указатель на динамический массив и его размер.
// Функция должна удалить из массива все отрицательные числа и вернуть указатель на новый динамический массив.

void erase_neg(int *&a, int &n) {
	int *tmp;
	int k = 0;
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0)
			k++;
	}
	tmp = new int[k];

	for (int i = 0; i < n; i++)
		if (a[i] > 0)
			tmp[j++] = a[i];

	delete[] a;
	a = tmp;
	n = k;
}

int main()
{
	srand(time(NULL));

	setlocale(LC_ALL, "Rus");

	int tn = 0;

	while (true)
	{
		cout << "Задача № ";
		cin >> tn;

		switch (tn)
		{
		case 1:
		{
			int n = 5;
			int *a;
			a = new int[n];
			int p=0, p1=1;
			for (int i = 0; i < n; i++)
			{
				a[i] = rand() % 10 - 3;
				cout << setw(4) << *(a + i) << " ";
			}
			cout << endl;

			func1(a, n, &p, &p1);
			cout << p << endl;
			cout << p1 << endl << endl;

			delete[] a;
		}
		break;
		case 2:
		{
			int n = 5;
			int *a;
			a = new int[n];
			int p = 0, p1 = 1;
			for (int i = 0; i < n; i++)
			{
				a[i] = rand() % 10 - 3;
				cout << setw(4) << *(a + i) << " ";
			}
			cout << endl;

			func2(a, n);

			delete[] a;
		}
		break;
		case 3:
		{
			
		}
		break;
		case 4:
		{
			int n = 5;
			int a;
			int *p = &a;

			init(p, n);

			for (int i = 0; i < n; i++)
			{
				p[i] = rand() % 21;
				cout << p[i] << " ";
			}
			cout << endl;
		}
		break;
		case 5:
		{
			int n = 5;
			int *p=&n;

			print(p, n);
		}
		break;
		case 6:
		{

		}
		break;
		case 7:
		{

		}
		break;
		case 8:
		{

		}
		break;
		case 9:
		{

		}
		break;
		case 10:
		{
			int *a;
			int n = 10;
			a = new int[n];

			for (int i = 0; i < n; i++)
			{
				a[i] = rand() % 10 - 3;
				cout << a[i] << " ";
			}
			cout << endl;

			erase_neg(a, n);

			for (int i = 0; i < n; i++)
			{
				cout << a[i] << " ";
			}
			cout << endl;
			delete[] a;
		}
		break;
		case 12:
		{
			// 5.	Даны два массива : А[N] и B[M](M и  N вводятся с клавиатуры).
			// Необходимо создать третий массив минимально возможного размера,
			// в котором нужно собрать элементы обоих массивов.

			int *a, *b;
			int n, m;
			cin >> n >> m;

			a = new int[n];
			b = new int[m];

			/*if (m > n) swap(*a, *b);*/

			for (int i = 0; i < n; i++)
			{
				a[i] = rand() % 21;
				cout << a[i] << " ";
			}
			cout << endl;
			for (int i = 0; i < m; i++)
			{
				b[i] = rand() % 21;
				cout << b[i] << " ";
			}
			cout << endl;

			int k = 0, c=0;
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (b[i] == a[j])
						k++;
				}
			}
			k = n - k;
			int *tmp = new int[k];

			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (b[i] == a[j]) break;

					tmp[c] = a[i];
					tmp[c + 1] = b[i];
					c++;
				}
			}

			for (int i = 0; i < k; i++)
				cout << tmp[i] << " ";
			cout << endl << endl;

			delete[] a;
			delete[] b;
			delete[] tmp;
		}
		break;
		default:
			cout << "нет такой задачи" << endl << endl;
		}
	}
	system("pause");
	return 0;
}