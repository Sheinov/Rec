#include<iostream>
#include<math.h>

using namespace std;


int fib(int n)
{
	if (n == 1 || n == 2) return 1;
	return fib(n - 1) + fib(n - 2);
}






// Метод решения уравнения. Дихотомия 

double func(double x) {
	double f;
	f = cos(2.0/x)-2.0*sin(1.0/x)+1.0/x;
	return f;
}

double Dih(double a, double b)
{
	double c = (a + b) / 2;
	if (func(a) * func(c) > 0)
		b = c;
	else
		a = c;

	if (abs(b - a) > 0.0001 /*&& func(c) != 0*/)
		return Dih(a, b);
	else
		return c;
}
// Поиск квадратного корня числа с заданной точностью
double kor(double a, double b, double x)
{
	double eps = 0.0001;
	double c = a + (b - a) / 2;
	double A = c * c;
	if (A > x)
		b = c;
	else
		a = c;

	if (abs(A - x) > eps)
		return kor(a, b, x);
	else
		return c;
}
// Ступеньки
int St(int n)
{
	int k = 0;
	if (n == 1 || n == 0) return 1;
	if (n > 1) k += St(n - 1);
	if (n >= 2) k += St(n - 2);
	if (n >= 3) k += St(n - 3);
	return k;
}

//Числа
int Ch(int n, int x, int k)
{
	if (x > 9999 && x < 100000)
	{
		if (x % n == 0)
			k++;
		return k;
	}
	if (x < 10000)
		return Ch(n, 10 * x + 2, k) + Ch(n, 10 * x + 3, k) + Ch(n, 10 * x + 5, k);
}
int sumcube(int n) 
{ 
	int d = n % 10;
	return n ? d * d * d + sumcube(n / 10) : 0; 
}
int test(int n) 
{ 
	int m = sumcube(n); 
	return m == n ? m : test(m); 
}
int main(void)
{
	int k = 0, n;
	setlocale(LC_ALL, "Russian");
	for (;;)
	{
		cout << "Выберите задание\n1-Найти n-член последовательности Фибоначчи\n2-Поиск решения уравнения f(x)=0 на отрезке [a,b], где функция непрерывно монотонна на отрезке [a,b] и имеет на концах этого отрезка значения разных знаков. Метод дихотомии.\n3-Поиск квадратного корня числа с заданной точностью.\n4-Лестничный пролет включает n ступеней. По лестнице можно подниматься, наступая на каждую ступеньку или перепрыгивая через одну или две ступени. Сколько существует способов подняться по лестнице.\n5-Сколько пятизначных чисел, записанных только с помощью цифр 2,3,5 кратны заданному числу?\n6-Дано натуральное число, кратное 3. Получите сумму кубов цифр этого числа, затем сумму кубов цифр получившегося числа и т.д." << endl;
		int f;
		cin >> f;
		switch (f)
		{
		case 1:
			cout << "Введите число " << endl;
			cin >> f;
			cout << fib(f);
			break;
		case 2:
			cout << "Введите отрезок[a:b] " << endl;
			double a, b;
			cout << "Введите a " << endl;
			cin >> a;
			cout << "Введите b " << endl; 
			cin >> b;
			if (b > a)
				cout << Dih(a, b)<<endl;
			else
				cout << "a болжно быть меньше b" << endl;
			
			break;
		case 3:
			cout << "Введите число из которого будет вычисляться квадратный корень: ";
			double x;
			cin >> x;
			if (x < 0) cout << "Квадратный корень может быть только из положительного числа " << endl;
			else
			{
				if (x == 0) cout << "Квадратный корень из 0 = 0" << endl;
				else
				{
					a = 1;
					b = x;
					cout << kor(a, b, x) << endl;
				}
			}
			break;
		case 4:
			cout << "Введите количество ступеей в лестнице" << endl;
			cin >> n;
			if (n < 1)
				cout << "Число ступенек в лестнице меньше или равно 0" << endl;
			else
			{
				cout << St(n) << endl;
			}
			
			break;
		case 5:
			
			cout << "Введите число которому кратно пятизначное ";
			cin >> n;
			cout << "Количесто таких пятизначных чисел: ";
			cout << Ch(n, 0,0);
			break;
		case 6:
			
			cout << "Введите натуральное число кратное 3" << endl;
			cin >> n;
			if (n < 1)
				cout << "Число не является натуральным!!" << endl;
			else
			{
				if(n%3==0)
					cout << test(n);
				else
				{
					cout << "Число не является кратным 3" << endl;;
				}
			}

			
			break;
		default:cout << "Такого варианта нет!!!";
			break;
		}
	}
	
}