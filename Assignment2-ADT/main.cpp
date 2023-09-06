#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
#include "input.h"
#include "Rational.h"
#include "Pseudorandom.h"

using namespace std;
int menuOption();
void quadraticExpressionMenu();
char quadraticExpressionMenuOption();
void pseudorandomMenu();
char pseudorandomMenuOption();
void generateIndirectNumTable(Pseudorandom);
void rationalNumMenu();
char rationalNumMenuOption();


int main()
{
    do
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

    return EXIT_SUCCESS;
}

int menuOption()
{
    system("cls");
    cout << "CMPR131 Chapter 2: ADT's by Saul Merino" << endl;
    cout << string(100, char(205)) << endl;

    cout << "1. Quadratic Expression" << endl;
    cout << string(100, char(196)) << endl;

    cout << "2. Pseudorandom" << endl;
    cout << string(100, char(196)) << endl;

    cout << "3. Rational Number" << endl;
    cout << string(100, char(196)) << endl;

    cout << "0. Quit" << endl;
    cout << string(100, char(205)) << endl;
    int option = inputInteger("Option : ", 0, 3);
    return option;
}

void quadraticExpressionMenu()
{
    /*string textString;
    string convertedNumString;
    do
    {
        switch (quadraticExpressionMenuOption())
        {
        case 0: return; break;
        case 1: textString = newStringInput(); break;
        case 2: convertedNumString = textToNumConvert(textString); break;
        case 3: numStringWrite(convertedNumString); break;
        case 4: numStringRead(convertedNumString); break;
        case 5: convertedNumString = textToNumConvert(textString); break;
        case 6: numStringWrite(convertedNumString); break;
        case 7: numStringRead(convertedNumString); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");
    } while (true);*/
}

char quadraticExpressionMenuOption()
{
    return '0';
}

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

void generateIndirectNumTable(Pseudorandom pseudorandom1)
{
    pseudorandom1.setMultiplier(21);
}

void rationalNumMenu()
{
    /*Rational rational1;
    do
    {
        switch (rationalNumMenuOption())
        {
        case '0': return; break;
        case 'A': rational1.setNumerator(); break;
        case 'B': rational1.getNumerator(); break;
        case 'C': rational1.setDenominator(); break;
        case 'D': rational1.getDenominator(); break;
        case 'E': convertedNumString = textToNumConvert(textString); break;
        case 'F': numStringWrite(convertedNumString); break;
        case 'G': numStringRead(convertedNumString); break;
        case 'H': convertedNumString = textToNumConvert(textString); break;
        case 'I': cout << "R1 (" << rational1.getNumerator() << ") == R2 (" << rational1.getDenominator()"): " break;
        case 'J': numStringRead(convertedNumString); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");
    } while (true);*/
}

char rationalNumMenuOption()
{
    return 'A';
}

bool numeratorGreaterThanDenominator(Rational)
{
    return true;
}