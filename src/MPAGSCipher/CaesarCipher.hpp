#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

#include <string>
#include "CipherMode.hpp"
#include <vector>
#include <cstddef>

/// Encrypt or decrypt text using the Caesar cipher with the given key

class CaesarCipher {
    public:
    // Create a new CaesarCipher, with the given key
    explicit CaesarCipher(const std::size_t key);

    // Create a new CaesarCipher, converting the given string into the key
    explicit CaesarCipher(const std::string& key);

    std::string applyCipher(const std::string& inputText, const CipherMode ciphermode) const;

    private:
    const std::vector<char> alphabet_ = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    const std::size_t alphabetSize_{alphabet_.size()};

    std::size_t key_{0};
};



#endif    // MPAGSCIPHER_CAESARCIPHER_HPP