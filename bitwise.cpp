#include <iostream>
#include <bitset> // optional, for printing binary easily
#include <bits/stdc++.h>

using namespace std;


int main() {
    uint32_t value = 0xA5A5A5A5; // 32-bit value (10100101...)
    std::cout << "Initial value: " << std::bitset<32>(value) << std::endl;

    // Accessing each bit
    std::cout << "Bits individually:" << std::endl;
    for (int i = 31; i >= 0; --i) { // MSB to LSB
        bool bit = (value >> i) & 1; // Shift right and mask with 1
        std::cout << "Bit " << i << ": " << bit << std::endl;
    }

    // Setting a bit (make it 1)
    int setBitPos = 5;
    value |= (1 << setBitPos); // OR with 1 at position
    std::cout << "\nAfter setting bit " << setBitPos << ": " << std::bitset<32>(value) << std::endl;

    // Clearing a bit (make it 0)
    int clearBitPos = 7;
    value &= ~(1 << clearBitPos); // AND with NOT of 1 at position
    std::cout << "After clearing bit " << clearBitPos << ": " << std::bitset<32>(value) << std::endl;

    // Toggling a bit (flip 0→1 or 1→0)
    int toggleBitPos = 12;
    value ^= (1 << toggleBitPos); // XOR with 1 at position
    std::cout << "After toggling bit " << toggleBitPos << ": " << std::bitset<32>(value) << std::endl;

    // Writing a specific bit manually
    int writeBitPos = 10;
    bool newBitValue = 1; // set 1 or 0
    value &= ~(1 << writeBitPos);          // Clear the bit first
    value |= (newBitValue << writeBitPos); // Set the new value
    std::cout << "After writing bit " << writeBitPos << " = " << newBitValue 
              << ": " << std::bitset<32>(value) << std::endl;

    return 0;
}