//==============================================================================
// Name        : BufferTextConversions.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (06/02/2020)
// Description : Header file of the buffer/text conversions functions
//==============================================================================

#ifndef BUFFERTEXTCONVERSIONS_H
#define BUFFERTEXTCONVERSIONS_H

#include <cstddef>
#include <cstdint>
#include <string>
#include <utility>

typedef std::pair<size_t, uint8_t*> Buffer;

const std::string bufferToBinaryText(const Buffer& buffer, const bool& spaces);
const std::string bufferToHexadecimalText(const Buffer& buffer, const bool& spaces);
const std::string bufferToText(const Buffer& buffer);
const Buffer binaryTextToBuffer(const std::string& binaryText, const bool& spaces);
const Buffer hexadecimalTextToBuffer(const std::string& hexadecimalText, const bool& spaces);
const Buffer textToBuffer(const std::string& text);

#endif /* BUFFERTEXTCONVERSIONS_H */
