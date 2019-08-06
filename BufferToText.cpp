#include <cstdint>
#include <iomanip>
#include <sstream>
#include <string>

const std::string bufferToBinaryText(const uint8_t* data, const size_t size)
{
    std::stringstream ss;
    for (size_t itByte = 0; itByte < size; ++itByte)
    {
        const uint8_t byte = data[itByte];
        for (int8_t itBit = 7; itBit >= 0; --itBit)
        {
            const bool bit = static_cast<bool>((byte >> itBit) & 0x1);
            ss << bit;
        }
        ss << " ";
    }
    return ss.str();
}

const std::string bufferToHexadecimalText(const uint8_t* data, const size_t size)
{
    std::stringstream ss;
    for (size_t itByte = 0; itByte < size; ++itByte)
    {
        const uint8_t byte = data[itByte];
        ss << std::setfill('0') << std::setw(2) << std::hex << (byte & 0xff) << " ";
    }
    return ss.str();
}

const std::string bufferToText(const uint8_t* data, const size_t size)
{
    std::stringstream ss;
    for (size_t itByte = 0; itByte < size; ++itByte)
    {
        const uint8_t byte = data[itByte];
        ss << byte;
    }
    return ss.str();
}

#include <cstdlib>
#include <iostream>

int main()
{
    const size_t size = 3;
    uint8_t data[size];
    data[0] = 0x2A;
    data[1] = 0x7F;
    data[2] = 0xFF;
    std::cout << bufferToBinaryText(data, size) << std::endl;
    std::cout << bufferToHexadecimalText(data, size) << std::endl;
    std::cout << bufferToText(data, size) << std::endl;
    return EXIT_SUCCESS;
}
