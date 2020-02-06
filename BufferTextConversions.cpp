#include "BufferTextConversions.h"

#include <iomanip>
#include <sstream>

const std::string bufferToBinaryText(const Buffer& buffer)
{
    std::stringstream stream;
    const size_t& size = buffer.first;
    const uint8_t* data = buffer.second;
    for (size_t itByte = 0; itByte < size; ++itByte)
    {
        const uint8_t byte = data[itByte];
        for (int8_t itBit = 7; itBit >= 0; --itBit)
        {
            const bool bit = static_cast<bool>((byte >> itBit) & 0x1);
            stream << bit;
        }
        stream << " ";
    }
    return stream.str();
}

const std::string bufferToHexadecimalText(const Buffer& buffer)
{
    std::stringstream stream;
    const size_t& size = buffer.first;
    const uint8_t* data = buffer.second;
    for (size_t itByte = 0; itByte < size; ++itByte)
    {
        const uint8_t byte = data[itByte];
        stream << std::setfill('0') << std::setw(2) << std::hex << (byte & 0xff) << " ";
    }
    return stream.str();
}

const std::string bufferToText(const Buffer& buffer)
{
    std::stringstream stream;
    const size_t& size = buffer.first;
    const uint8_t* data = buffer.second;
    for (size_t itByte = 0; itByte < size; ++itByte)
    {
        const uint8_t byte = data[itByte];
        stream << byte;
    }
    return stream.str();
}

const Buffer binaryTextToBuffer(const std::string& binaryText)
{
    // TODO const Buffer binaryTextToBuffer(const std::string& binaryText)
    Buffer buffer;
    size_t size = 0;
    uint8_t* data = nullptr;
    buffer.first = size;
    buffer.second = data;
    return buffer;
}

const Buffer hexadecimalTextToBuffer(const std::string& hexadecimalText)
{
    // TODO const Buffer hexadecimalTextToBuffer(const std::string& hexadecimalText)
    Buffer buffer;
    size_t size = 0;
    uint8_t* data = nullptr;
    buffer.first = size;
    buffer.second = data;
    return buffer;
}

const Buffer textToBuffer(const std::string& text)
{
    // TODO const Buffer textToBuffer(const std::string& text)
    Buffer buffer;
    size_t size = 0;
    uint8_t* data = nullptr;
    buffer.first = size;
    buffer.second = data;
    return buffer;
}
