#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

//Precondition none
//Postcondition: Rational class will help us create rational numbers from user integer input data
//The class will also have a exception class that will help us validate for zero denominator integer inputs
//The class will also have overloaded operators and a friend function
class Rational
{
private:
	int numerator;//numerator will hold numerator data inputs
	int denominator;//denominator will hold denominator data inputs

	//Precondition none
	//Postcondition: int gcd will be called to acquire the greatest common denominator of our rational numbers
	int gcd(int a, int b)
	{

		if (a == 0)
			return b;
		else if (b == 0)
			return a;
		else if (a == b)
			return a;
		else if (a > b)
			return gcd(a - b, b);
		else return gcd(a, b - a);

	}

	//precondition none
	//Postcondition: normalize function will help us create our rational numbers
	void normalize()
	{
		if (denominator < 0)//will accept negative numbers
		{
			denominator *= -1;
			numerator *= -1;
		}

		if (numerator != 0)//will create rational numbers
		{
			int temp = gcd(abs(numerator), abs(denominator));
			numerator /= temp;
			denominator /= temp;

		}


	}



public:
	
	//Precondition none
	//Postcondition: if user inputs a zro denominator then an exception will be thrown and user will have enter a new denominator
	class ZeroDenominator 
	{
	private:
		string rational;//will hold rational input data
	public:
		
		//Precondition none
		//Postcondition: we will initialize our ZeroDenominator default constructor
		ZeroDenominator()
		{}

		//Precondition none
		//Postcondition: we will initialize our ZeroDenominator constructor that will accept arguments
		ZeroDenominator(Rational r)
		{
			rational = r.toString();
		}

		//Precondition none
		//Postcondition: toString function will return our rational numbers and display them
		string toString()
		{
			return rational;
		}

	};

	//Precondition none
	//Postcondition: we will initialize our Rational default constructor
	Rational()
	{
		numerator = 0;
		denominator = 1;
	}

	//Precondition none
	//Postcondition: function toString will be used to display our rational numbers
	string toString()
	{
		return to_string(numerator) + "/" + to_string(denominator);
	}

	//Precondition none
	//Postcondition: We will initialize our Rational constructor that will accept integer input arguments
	Rational(int newN, int newD)
	{
		numerator = newN;
		denominator = newD;
		if (denominator == 0)
			throw ZeroDenominator(*this);//if there is zero denominator input then the exception will be thrown

		normalize();//we will call normalize function to create our rational numbers
	}



	//Precondition none
	//Postcondition: We will initialize our getter/accessor function for numerator class member
	int getNumerator() const
	{
		return numerator;
	}

	//Precondition none
	//Postcondition: We will initialize our setter/mutator function for numerator class member
	void setNumerator(int newN)
	{
		numerator = newN;
		normalize();
	}

	//Precondition none
	//Postcondition: We will initialize our getter/accessor function for denominator class member
	int getDenominator() const
	{
		return denominator;
	}

	//Precondition none
	//Postcondition: We will initialize our setter/mutator function for denominator class member
	void setDenominator(int newD)
	{
		denominator = newD;
		if (denominator == 0)
			throw ZeroDenominator(*this);

		normalize();
	}

	Rational operator*(const Rational& obj)
	{

		Rational r3;

		r3.numerator = numerator * obj.numerator;

		r3.denominator = denominator * obj.denominator;

		r3.normalize();

		return r3;
	
	
	}

	Rational operator/(const Rational& obj)
	{

		Rational r4;

		r4.numerator = numerator / obj.numerator;

		r4.denominator = denominator / obj.denominator;

		r4.normalize();

		return r4;


	}

	Rational operator+(const Rational& obj)
	{

		Rational r5;

		r5.numerator = numerator / obj.numerator;

		r5.denominator = denominator / obj.denominator;

		r5.normalize();

		return r5;


	}

	Rational operator-(const Rational& obj)
	{

		Rational r7;

		r7.numerator = numerator / obj.numerator;

		r7.denominator = denominator / obj.denominator;

		r7.normalize();

		return r7;

	}
	
	//Precondition none
	//Postcondition: We will initalize our == loaded operator that will help us compare different rational numbers
	friend bool operator ==(const Rational& obj1, const Rational& obj2)
	{
		return (obj1.numerator * obj2.denominator) == (obj2.numerator * obj1.denominator);
	}
	
	//Precondition none
	//Postcondition: We will initalize our < loaded operator that will help us compare different rational numbers
	friend bool operator <(const Rational& obj1, const Rational& obj2)
	{
		return (obj1.numerator * obj2.denominator) < (obj2.numerator * obj1.denominator);
	}

	//Precondition none
	//Postcondition: we will initialize our friend function that will help us display our rational numbers
	friend ostream& operator << (ostream& out,  Rational obj)
	{
		out << obj.toString();
		return out;
	}


};