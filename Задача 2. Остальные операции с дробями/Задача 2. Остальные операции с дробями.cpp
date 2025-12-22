// Задача 2. Остальные операции с дробями.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <algorithm>

class Fraction
{
private:
	int numerator_;
	int denominator_;
	
public:
    Fraction(int numerator, int denominator): numerator_{ numerator }, denominator_{ denominator }
	{}
	
    ~Fraction()
    {}
	
	Fraction& operator++()
	{
		numerator_ = numerator_+ denominator_;
		denominator_;
		return *this;
	}
		
	Fraction operator--(int)
	{
		Fraction temporary{ *this };
		numerator_ = numerator_ - denominator_;;
		denominator_;
		return temporary;
	}
public:
    int gcd(int numerator_, int denominator_)
	{
		numerator_ = abs(numerator_), denominator_ = abs(denominator_);
	    if (denominator_ == 0)return numerator_;
	    else return gcd(denominator_, numerator_ % denominator_);
    }
	void printFraction()
	{
	int x = gcd(numerator_, denominator_);
	numerator_ /= x;
	denominator_ /= x;
	std::cout << numerator_ << " / " << denominator_ << std::endl;
    }

public:
	friend Fraction operator+(const Fraction& f1, const Fraction& f2);
	friend Fraction operator-(const Fraction& f1, const Fraction& f2);
	friend Fraction operator*(const Fraction& f1, const Fraction& f2);
	friend Fraction operator/(const Fraction& f1, const Fraction& f2);

};
    Fraction operator+(const Fraction& f1, const Fraction& f2)
	{
		return Fraction(f1.numerator_ * f2.denominator_ + f1.denominator_ * f2.numerator_ , f1.denominator_ * f2.denominator_);
	}
	Fraction operator-(const Fraction& f1, const Fraction& f2)
	{
		return Fraction(f1.numerator_ * f2.denominator_ - f1.denominator_ * f2.numerator_, f1.denominator_ * f2.denominator_);
	}
	Fraction operator*(const Fraction& f1, const Fraction& f2)
	{
		return Fraction(f1.numerator_ * f2.numerator_, f1.denominator_ * f2.denominator_);
	}
	Fraction operator/(const Fraction& f1, const Fraction& f2)
	{
		return Fraction(f1.numerator_ * f2.denominator_ , f1.denominator_ * f2.numerator_);
	}
	

int main()
{
    int numerator1{}, numerator2{}, denominator1{}, denominator2{};
	
	std::cout << "Enter the numerator of the fraction 1:";
    std::cin >> numerator1;
    std::cout << "Enter the denominator of the fraction 1:";
    std::cin >> denominator1;
    Fraction f1(numerator1, denominator1);
    std::cout << "Enter the numerator of the fraction 1:";
    std::cin >> numerator2;
    std::cout << "Enter the denominator of the fraction 1:";
    std::cin >> denominator2;
    Fraction f2(numerator2, denominator2);
	Fraction f3{ f1 + f2 };
	std::cout << numerator1 << " / " << denominator1 << " + " << numerator2 << " / " << denominator2 << " = ";
	f3.printFraction();
	Fraction f4{ f1 - f2 };
	std::cout << numerator1 << " / " << denominator1 << " - " << numerator2 << " / " << denominator2 << " = ";
	f4.printFraction();
	Fraction f5{ f1 * f2 };
	std::cout << numerator1 << " / " << denominator1 << " + " << numerator2 << " / " << denominator2 << " = ";
	f5.printFraction();

	Fraction f6{ f1 / f2 };
	std::cout << numerator1 << " / " << denominator1 << " - " << numerator2 << " / " << denominator2 << " = ";
	f6.printFraction();
    
	Fraction f7{ (++f1)*f2};
	std::cout << "++" << numerator1 << " / " << denominator1 << " * " << numerator2 << " / " << denominator2 << " = ";
	f7.printFraction();

	std::cout << "The value of the fraction is 1 = ";
	f1.printFraction();

	Fraction f8{ (f1--) * f2 };
	std::cout << numerator1 << " / " << denominator1 << "-- * " << numerator2 << " / " << denominator2 << " = ";
	f8.printFraction();

	std::cout << "The value of the fraction is 1 = ";
	f1.printFraction();

	return EXIT_SUCCESS;

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
