#include <iostream>
#include <iomanip> 
#include <vector>
#include <cstdint> 
#include <windows.h>

float ieee754ToDecimal(uint32_t ieee754) {
    float result;
    std::memcpy(&result, &ieee754, sizeof(result)); 
    return result;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    std::vector<uint32_t> numbers = {
        0x7ED00000, 
        0x7D800000, 
        0x7F800000, 
        0x80000000  
    };

    std::cout << "Числа в формате IEEE 754 и их десятичные значения:\n";
    float sum = 0.0f; 

  
    for (uint32_t number : numbers) {
        float decimalValue = ieee754ToDecimal(number);
        std::cout << "0x" << std::hex << number << " = " << std::dec << std::setprecision(8) << decimalValue << std::endl;
        sum += decimalValue; 
    }

    std::cout << "\nСумма чисел: " << std::setprecision(8) << sum << std::endl;

    return 0;
}
