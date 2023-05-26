#include <iostream>
#include <windows.h>
using namespace std;

int waow(int a, int b){
	return a+b;
}
bool sort(int a, int b){
	return a>b
}
int Vvod() //ввод натурального положительного числа
{
	waow(1,2);
	int a;
	int b;
	while (!(cin >> a) || (cin.peek() != '\n') || (a <= 0))
	{
		cin.clear();
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');
	}
	cout << a;
	return a;
}

float VvodС() //ввод целого положительного числа
{
	float a;
	while (!(cin >> a) || (cin.peek() != '\n') || (a <= 0))
	{
		cin.clear();
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');
		cout << "Произошла ошибка. Проверьте данные и попробуйте снова \n";
	}
	return a;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N; //Количество событий
	int j; //переменная, отвечающая за строки при работе массива в цикле
	int b = 0; //Переменная, проверяющая то, что сумма вероятностей должна быть равна 1
	float a; //Cумма вероятностей событий
	float I = 0; //Количество информации

	
	cout << "Введите количество событий\n";
	

	N = Vvod(); //Массив вероятностей событий

	float* prr = new float[N];


	do
	{
		a = 0;
		for (j = 0; j < N; j++)
		{
			cout << "Вероятность " << j + 1 << "-го события\n";
			prr[j] = VvodС();
			a = a + prr[j];
		}
		if (a == 1)
			b = 1;
		else
			cout << "Произошла ошибка. Сумма вероятностей событий должна быть равна единице, а не " << a << endl;
	} while (b == 0);

	for (j = 0; j < N; j++)
	{
		I = I - prr[j] * log2(prr[j]);
	}

	cout << "Количество информации = " << I << endl;
}

