//! Unit Tests for MPAGSCipher transformChar interface
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "iostream"
#include "CaesarCipher.hpp"
#include "CipherMode.hpp"
#include "ProcessCommandLine.hpp"
#include "TransformChar.hpp"

TEST_CASE("Testing Caesar Cipher", "[alphanumeric]"){

    const std::string upper{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

    SECTION("Testing Encryption"){

        for (size_t i=0; i < 30; i++) //I have chosen 30 as the max key to ensure that the looping back of the cipher works.
        {   
            size_t modulus{i%26};
            size_t upper_difference{upper.size() - modulus};
            CaesarCipher cipher{modulus};
            std::string outputText{cipher.applyCipher(upper, CipherMode::Encrypt)};
            REQUIRE(outputText == (upper.substr(modulus, upper_difference) + upper.substr(0, modulus)));
        }
    }

    SECTION("Testing Decryption"){

        for (size_t i=0; i < 30; i++) //I have chosen 30 as the max key to ensure that the looping back of the cipher works.
        {   
            size_t modulus{i%26};
            size_t upper_difference{upper.size() - modulus};
            CaesarCipher cipher{modulus};
            std::string outputText{cipher.applyCipher(upper, CipherMode::Decrypt)};
            //REQUIRE(outputText == (upper.erase(upper.begin, upper_difference) + upper.substr(0,upper_difference)));
            REQUIRE(outputText == (upper.substr(upper_difference, modulus) + upper.substr(0, upper_difference)));
        }
    }
}