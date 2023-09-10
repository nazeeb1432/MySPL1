#include<iostream>
#include<cstring>
#include<cassert>
using namespace std;

// Function to rotate bits of a 32-bit integer to the right
uint32_t RotateRight(uint32_t x, size_t numOfBitsToBeShifted)
{
    return (x >> numOfBitsToBeShifted) | (x << (32 - numOfBitsToBeShifted));
}

// Function to shift bits of a 32-bit integer to the right
uint32_t ShiftRight(uint32_t x, size_t numOfBitsToBeShifted)
{
    return x >> numOfBitsToBeShifted;
}

// Function implementing the "choice" operation
uint32_t Choice(uint32_t x, uint32_t y, uint32_t z)
{
    
    return (x & y) ^ (~x & z);
}

// Function implementing the "majority" operation
uint32_t Majority(uint32_t x, uint32_t y, uint32_t z)
{
    // The result takes the bit which occurs more frequently among x, y, z.
    
    return (x & y) ^ (x & z) ^ (y & z);
}


uint32_t Epsilon0(uint32_t x)
{
    return RotateRight(x, 2) ^ RotateRight(x, 13) ^ RotateRight(x, 22);
}


uint32_t Epsilon1(uint32_t x)
{
    return RotateRight(x, 6) ^ RotateRight(x, 11) ^ RotateRight(x, 25);
}


uint32_t Sigma0(uint32_t x)
{
    return RotateRight(x, 7) ^ RotateRight(x, 18) ^ ShiftRight(x, 3);
}


uint32_t Sigma1(uint32_t x)
{
    return RotateRight(x, 17) ^ RotateRight(x, 19) ^ ShiftRight(x, 10);
}