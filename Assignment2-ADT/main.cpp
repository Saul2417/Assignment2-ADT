#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
#include <vector>
#include <cmath>
#include "input.h"
#include "Rational.h"
#include "Pseudorandom.h"


using namespace std;
void pseudorandomMenu();
char pseudorandomMenuOption();
void generateIndirectNumTable(Pseudorandom&);
double* arrayAllocator(int size);
double arrayAverage(double* doubleArray, int size);
double arrayStandardDeviation(double* doubleArray, int size, double mean);
void calculateGaussianDistribution(double* doubleArray, int size);


//Precondition: None 
//Postcondition: Returns to the main menu once done.
int main()
{
    /*do
    {
        switch (menuOption())
        {
        case 0: exit(1); break;
        case 1: quadraticExpressionMenu(); break;
        case 2: pseudorandomMenu(); break;
        case 3: rationalNumMenu(); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");
    } while (true);

    return EXIT_SUCCESS;*/

    pseudorandomMenu();

}


//Precondition:
//Postcondition:
void pseudorandomMenu()
{
    Pseudorandom pseudorand1;

    do
    {
        switch (pseudorandomMenuOption())
        {
        case '0': return; break;
        case 'A': cout << "Seed: " << pseudorand1.getSeed(); break;
        case 'B': pseudorand1.setSeed(inputInteger("Enter Seed:")); break;
        case 'C': cout << "Multiplier: " << pseudorand1.getMultiplier(); break;
        case 'D': pseudorand1.setMultiplier(inputInteger("Enter Multiplier:")); break;
        case 'E': cout << "Modulus: " << pseudorand1.getModulus(); break;
        case 'F': pseudorand1.setModulus(inputInteger("Enter Modulus:")); break;
        case 'G': cout << "Increment: " << pseudorand1.getIncrement(); break;
        case 'H': pseudorand1.setIncrement(inputInteger("Enter Increment:")); break;
        case 'I': pseudorand1.generateSeed(); cout << pseudorand1.getSeed(); break;
        case 'J': cout << "Indirect Next Number: " << pseudorand1.generateNextIndirectNum();  break;
        case 'K': generateIndirectNumTable(pseudorand1);  break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");
    } while (true);
}

//Precondition: None
//Postcondition: Returns a character
char pseudorandomMenuOption()
{
    system("cls");
    cout << "2: Pseudorandom" << endl;
    cout << string(100, char(205)) << endl;
    cout << "A. Get Seed" << endl;  
    cout << "B. Set Seed"  << endl;                           
    cout << "C. Get Multiplier"  << endl;                           
    cout << "D. Set Multiplier" << endl;                              
    cout << "E. Get Modulus"  << endl;                             
    cout << "F. Set Modulus"  << endl;                               
    cout << "G. Get Increment" << endl;                                
    cout << "H. Set Increment" << endl;                             
    cout << "I. Get Next Number" << endl;                         
    cout << "J. Get Next Indirect Number" << endl;                             
    cout << "K. Run Experiment With Different Numbers (Mutliplier, Increment, and Modulus)" << endl;                
    cout << string(100, char(205)) << endl;
    cout << "0. Return" << endl;
    cout << string(100, char(205)) << endl;

    char option = toupper(inputChar("Option : "));
    return option;
}

//Precondition:
//Postcondition:
void generateIndirectNumTable(Pseudorandom& pseudorandom1)
{
    unsigned seed = pseudorandom1.getMultiplier();
    srand(seed);

    int count0 = 0, count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0, count6 = 0, count7 = 0, count8 = 0, count9 = 0;

    double* doubleArray = nullptr;
    int size = 1000000;
    doubleArray = arrayAllocator(size);
    
    //Randomize Multiplier, Increment, and Modulus
    /*pseudorandom1.setMultiplier(rand());
    pseudorandom1.setIncrement(rand());
    pseudorandom1.setModulus(rand());*/

    pseudorandom1.setMultiplier(16246);
    pseudorandom1.setIncrement(6965);
    pseudorandom1.setModulus(22896);

    cout << "Multiplier = " << pseudorandom1.getMultiplier() << ", Increment = " << pseudorandom1.getIncrement() << ", Modulus = " << pseudorandom1.getModulus() << endl;

    for (int index = 0; index < size; index++)
    {
        doubleArray[index] = pseudorandom1.generateNextIndirectNum();
        if (doubleArray[index] < 1.00000 && doubleArray[index >= 0.00000])
        {
            if (doubleArray[index] >= 0.900000)
            {
                count9++;
            }
            else if (doubleArray[index] >= 0.800000)
            {
                count8++;
            }
            else if (doubleArray[index] >= 0.700000)
            {
                count7++;
            }
            else if (doubleArray[index] >= 0.600000)
            {
                count6++;
            }
            else if (doubleArray[index] >= 0.500000)
            {
                count5++;
            }
            else if (doubleArray[index] >= 0.400000)
            {
                count4++;
            }
            else if (doubleArray[index] >= 0.300000)
            {
                count3++;
            }
            else if (doubleArray[index] >= 0.200000)
            {
                count2++;
            }
            else if (doubleArray[index] >= 0.100000)
            {
                count1++;
            }
            else
            {
                count0++;
            }
        }
    }

    cout << "Range " << setw(30) << " Number of Occurences:" << endl;
    cout << "[0.0 ... 0.1)" << setw(10) << count0 << endl;
    cout << "[0.1 ... 0.2)" << setw(10) << count1 << endl;
    cout << "[0.2 ... 0.3)" << setw(10) << count2 << endl;
    cout << "[0.3 ... 0.4)" << setw(10) << count3 << endl;
    cout << "[0.4 ... 0.5)" << setw(10) << count4 << endl;
    cout << "[0.5 ... 0.6)" << setw(10) << count5 << endl;
    cout << "[0.6 ... 0.7)" << setw(10) << count6 << endl;
    cout << "[0.7 ... 0.8)" << setw(10) << count7 << endl;
    cout << "[0.8 ... 0.9)" << setw(10) << count8 << endl;
    cout << "[0.9 ... 1.0)" << setw(10) << count9 << endl << endl;

    calculateGaussianDistribution(doubleArray, size);
    delete doubleArray;
}

//Precondition: Integer 
//Postcondition: Returns a double array
double* arrayAllocator(int size)
{
    double* newArray = nullptr;
    if (size <= 0)
        return nullptr;
    else
        return new double[size];
}

//Precondition: Reads a valid double array and integer
//Postcondition: Returns a double from the calculation of the average
double arrayAverage(double* doubleArray, int size)
{
    if (size == 0)
    {
        cout << "Array is empty. Select 1 to create an array.";
        exit(1);
    }

    double sum = 0.0;
    for (int index = 0; index < size; ++index)
    {
        sum += doubleArray[index];
    }

    return sum / size;
}

//Precondition: Reads a valid double array, an integer and a double
//Postcondition: Returns a double from the calculation of Standard Deviation
double arrayStandardDeviation(double* doubleArray, int size, double mean)
{

    if (size == 0)
    {
        cout << "Array is empty. Select 1 to create an array.";
        exit(1);
    }

    double sumOfSquares = 0;

    for (int index = 0; index < size; ++index)
    {
        sumOfSquares += (doubleArray[index] - mean) * (doubleArray[index] - mean);
    }

    return sqrt(sumOfSquares / size);
}

//Precondition: double array and integer
//Postcondition: none.
void calculateGaussianDistribution(double* doubleArray, int size)
{
    double mean = arrayAverage(doubleArray, size);
    double stdDeviation = arrayStandardDeviation(doubleArray, size, mean);
    double gaussianDistribution = ((1.0 / (stdDeviation * sqrt(2.0 * M_PI))) * (pow(M_E, (0.5 * pow( (mean * -1.0) / stdDeviation, 2.0)))));
    cout << "With 10 uniformly distributed rand number in the range[0...1.0), the approximate Gaussian distribution is " << gaussianDistribution;
    
}



