//==============================================================================
// Name        : BufferTextConversions.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (06/02/2020)
// Description : Source file of the buffer/text conversions functions
//==============================================================================

#include "BufferTextConversions.h"

#include <cstring>
#include <iomanip>
#include <sstream>

const std::string bufferToBinaryText(const Buffer& buffer, const bool& spaces)
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
        stream << (spaces ? " " : "");
    }
    return stream.str();
}

const std::string bufferToHexadecimalText(const Buffer& buffer, const bool& spaces)
{
    std::stringstream stream;
    const size_t& size = buffer.first;
    const uint8_t* data = buffer.second;
    for (size_t itByte = 0; itByte < size; ++itByte)
    {
        const uint8_t byte = data[itByte];
        stream << std::setfill('0') << std::setw(2) << std::hex << (byte & 0xff) << (spaces ? " " : "");
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

const Buffer binaryTextToBuffer(const std::string& binaryText, const bool& spaces)
{
    // TODO const Buffer binaryTextToBuffer(const std::string& binaryText, const bool& spaces)
    size_t size = (spaces ? (binaryText.size() + 1) / 9 : binaryText.size() / 8);
    uint8_t* data = new uint8_t[size];
    std::memset(data, 0, size);
    return Buffer(size, data);
}

const Buffer hexadecimalTextToBuffer(const std::string& hexadecimalText, const bool& spaces)
{
    // TODO const Buffer hexadecimalTextToBuffer(const std::string& hexadecimalText, const bool& spaces)
    size_t size = (spaces ? (hexadecimalText.size() + 1) / 3 : hexadecimalText.size() / 2);
    uint8_t* data = new uint8_t[size];
    std::memset(data, 0, size);
    return Buffer(size, data);
}

const Buffer textToBuffer(const std::string& text)
{
    // TODO const Buffer textToBuffer(const std::string& text)
    size_t size = text.size();
    uint8_t* data = new uint8_t[size];
    std::memset(data, 0, size);
    return Buffer(size, data);
}
