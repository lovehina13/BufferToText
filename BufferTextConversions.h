#ifndef BUFFERTEXTCONVERSIONS_H
#define BUFFERTEXTCONVERSIONS_H

#include <cstddef>
#include <cstdint>
#include <string>
#include <utility>

typedef std::pair<size_t, uint8_t*> Buffer;

const std::string bufferToBinaryText(const Buffer& buffer);
const std::string bufferToHexadecimalText(const Buffer& buffer);
const std::string bufferToText(const Buffer& buffer);
const Buffer binaryTextToBuffer(const std::string& binaryText);
const Buffer hexadecimalTextToBuffer(const std::string& hexadecimalText);
const Buffer textToBuffer(const std::string& text);

#endif /* BUFFERTEXTCONVERSIONS_H */
