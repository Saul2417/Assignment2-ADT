#include "Pseudorandom.h"
#include <time.h>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

Pseudorandom::Pseudorandom()
{
    seed = 1;
    multiplier = 40;
    increment = 725;
    modulus = 729;
}

void Pseudorandom::setSeed(int newSeed)
{
    seed = newSeed;
}
void Pseudorandom::setMultiplier(int newMultiplier)
{
    multiplier = newMultiplier;
}
void Pseudorandom::setIncrement(int newIncrement)
{
    increment = newIncrement;
}

void Pseudorandom::setModulus(int newModulus)
{
    modulus = newModulus;
}

void Pseudorandom::generateSeed()
{
    int newSeed = (multiplier * seed + increment) % modulus;
    setSeed(newSeed);
}

double Pseudorandom::generateNextIndirectNum()
{
    generateSeed();
    return static_cast<double>(seed) / modulus;
}

////precondition: going to get the math, using a vector argu so then went print out i can get the information 
////postcondition: going to get the sum , mean, and then return the standard deviation
//double Pseudorandom::generateGaussian(const vector<int> gaussian)
//{
//    double sum = 0.0;
//    //go through the data 
//    for (double i : gaussian) {
//        //going to be adding to get the sum
//        sum += i;
//    }
//    double mean = sum / gaussian.size();
//    double squaredSum = 0.0;
//    for (double i : gaussian) {
//        //going to use the pow(lets me square), add all the numbers in the data, call the getMean(mean) function
//        squaredSum += pow(i - mean, 2.0);
//    }
//    //going to then get the square sum and divide it by the size - 1 since thats the formula
//    double totalDev = squaredSum / (gaussian.size() - 1);
//    double standardDev = sqrt(totalDev);
//    return standardDev;
//}
////precondition: going to be able to display the information
////postcondition: going to call my member function generateGaussian() to get the gaussian, then show the information
//void Pseudorandom::displayGenerateGaussian() 
//{
//    const int SIZE = 10;
//    //keeping track of the number of occurrences, Size(10, and 0 is the initialize of the values
//    vector<int>numberOfOc(SIZE, 0.0);
//    //doing the srand() so it can change random numbers and not be the same
//    srand(time(0));
//    //using the generate function to get the beginning and end of the vector size, then 3rd argu makes it rand()
//    generate(numberOfOc.begin(), numberOfOc.end(), rand);
//    //using the rand() to get random numbers
//    setSeed(rand());
//    setMultiplier(rand());
//    setIncrement(rand());
//    setModulus(rand());
//    cout << "\n\t\texperiment of pseudorandom with random multiplier, increment and modulus: \n\n";
//    cout << "\t\t" << string(76, char(205));
//    cout << "\n\t\tmultiplier = " << getMultiplier() << ", increment = " << getIncrement() << ", modulus = " << getModulus();
//    cout << "\n\n\t\tRange \t\tNumber of Occurrences";
//
//    for (int i = 0; i < SIZE; i++) {
//        cout << "\n\t\t[" << i / static_cast<double>(SIZE) << " ... " << (i + 1) / static_cast<double>(SIZE) << ")\t" << numberOfOc[i];
//        numberOfOc[i] = static_cast<double>(rand()) / RAND_MAX;
//    }
//
//    double gaussianValue = generateGaussian(numberOfOc);
//    cout << "\n\n\t\tWith " << SIZE << " uniformly distributed rand number in the range[0...1.0),\n";
//    cout << "\t\tthe approximate Gaussian distribution is " << gaussianValue;
//}