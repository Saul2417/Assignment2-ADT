#include "Pseudorandom.h"

//Precondition: None
//Postcondition: None
Pseudorandom::Pseudorandom()
{
    seed = 1;
    multiplier = 40;
    increment = 725;
    modulus = 729;
}
//Precondition: A Positve or Negative Integer
//Postcondition: None 
void Pseudorandom::setSeed(int newSeed)
{
    seed = newSeed;
}

//Precondition: A Positive or Negative Integer
//Postcondition: None 
void Pseudorandom::setMultiplier(int newMultiplier)
{
    multiplier = newMultiplier;
}

//Precondition: A Positive or Negative Integer
//Postcondition: None 
void Pseudorandom::setIncrement(int newIncrement)
{
    increment = newIncrement;
}

//Precondition: A Positive or Negative Integer
//Postcondition: None
void Pseudorandom::setModulus(int newModulus)
{
    modulus = newModulus;
}

//Precondition: None
//Postcondition: None
void Pseudorandom::generateSeed() 
{
    int newSeed = (multiplier * seed + increment) % modulus;
    setSeed(newSeed);
}

//Precondition: None
//Postcondition: Returns a Double
double Pseudorandom::generateNextIndirectNum()
{
    generateSeed();
    return static_cast<double>(seed) / modulus;
}