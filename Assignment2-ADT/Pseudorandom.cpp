#include "Pseudorandom.h"

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