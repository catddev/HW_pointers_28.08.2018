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
// case 3

// a.функция распределения динамической памяти
void allocation(int *&a, int n) {
	a = new int[n];
}

// b.функция инициализации динамического массива
void init(int *a, int n) {
	
	for (int i = 0; i < n; i++)
		cin >> a[i];
}

// c.функция печати динамического массива
void print(int *a, int n) {

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

// d.функцию удаления динамического массива
void delete_arr(int *&a) {
	delete[]a;
}

// e.функцию добавления элемента в конец массива
void insert_end(int *&a, int &n, int value) {
	int *tmp = new int[n + 1];
	for (int i = 0; i < n; i++)
		tmp[i] = a[i];

	tmp[n] = value;
	n += 1;
	delete[] a;
	a = tmp;
}


// f.функцию вставки элемента по указанному индексу
// case 6
void add_index(int *&a, int &n, int index) {
	int *tmp = new int[n + 1];
	for (int i = 0; i <= index; i++)
	{
		tmp[i] = a[i];
		if (i == index)
		{
			cout << "ввести значение элемента по индексу: ";
			cin >> tmp[i];
		}	
	}
	for (int i = index + 1; i < n + 1; i++)
		tmp[i] = a[i-1];
	
	n += 1;
	delete[] a;
	a = tmp;
}

// g.функцию удаления элемента по указанному индексу
// case 6
void del_index(int *&a, int &n, int index) {
	int *tmp = new int[n - 1];
	for (int i = 0; i < index; i++)
	{
		tmp[i] = a[i];
	}
	for (int i = index; i < n; i++)
		tmp[i] = a[i + 1];

	n -= 1;
	delete[] a;
	a = tmp;
}

// 4.	Написать функцию, которая получает указатель на динамический массив и его размер.
// Функция должна удалить из массива все отрицательные числа и вернуть указатель на новый динамический массив.
// case 4
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

// 5.	Даны два массива : А[N] и B[M](M и  N вводятся с клавиатуры).
// Необходимо создать третий массив минимально возможного размера,
// в котором нужно собрать элементы обоих массивов.
// case 5
void unit(int *a, int *b, int n, int m) {
	int *c = new int[n + m];
	for (int i = 0; i < n; i++)
			c[i] = a[i];

	for (int i = 0; i < m; i++)
			c[i+n] = b[i];

	for (int i = 0; i < n + m; i++)
		cout << c[i] << " ";
	cout << endl << endl;

	delete[] c;
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
			int p = 0, p1 = 1;
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
			int *a;
			int n = 5;
			allocation(a, n);
			init(a, n);
			print(a, n);

			insert_end(a, n, 10);
			print(a, n);

			delete_arr(a);

			cout << endl;
		}
		break;
		case 4:
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
			cout << endl << endl;
			delete[] a;
		}
		break;
		case 5:
		{
			int *a, *b;
			int n, m;
			cin >> n >> m;
			a = new int[n];
			b = new int[m];

			for (int i = 0; i < n; i++)
			{
				a[i] = rand() % 10;
				cout << a[i] << " ";
			}
			cout << endl;
			for (int i = 0; i < m; i++)
			{
				b[i] = rand() % 10;
				cout << b[i] << " ";
			}
			cout << endl << endl;

			unit(a, b, n, m);
		}
		break;
		case 6:
		{
			int n = 10;
			int *a;
			a = new int[n];
			
			for (int i = 0; i < n; i++)
			{
				a[i] = rand() % 10;
				cout << setw(4) << a[i] << " ";
			}
			cout << endl << endl;

			add_index(a, n, 5);
			for (int i = 0; i < n; i++)
				cout << setw(4) << a[i] << " ";
			cout << endl << endl;

			del_index(a, n, 7);
			for (int i = 0; i < n; i++)
				cout << setw(4) << a[i] << " ";
			cout << endl << endl;

			delete[] a;
		}
		break;
		default:
			cout << "нет такой задачи" << endl << endl;
		}
	}
	system("pause");
	return 0;
}