//! Unit Tests for MPAGSCipher ProcessCommandLine interface
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "ProcessCommandLine.hpp"
#include "CipherMode.hpp"


TEST_CASE("Input file is found", "[alphanumeric]") {
    ProgramSettings settings {false, false, "", "", "", CipherMode::Encrypt};
    const std::vector<std::string>& cmdLineArgs{"Program_name", "-i", "Input_file"};
    processCommandLine(cmdLineArgs, settings);
    REQUIRE(settings.inputFile == "Input_file");
}

TEST_CASE("Ouput file is found", "[alphanumeric]") {
    ProgramSettings settings {false, false, "", "", "", CipherMode::Encrypt};
    const std::vector<std::string>& cmdLineArgs{"Program_name", "-o", "Output_file"};
    processCommandLine(cmdLineArgs, settings);
    REQUIRE(settings.outputFile == "Output_file");
}

TEST_CASE("Cipher key is found", "[alphanumeric]") {
    ProgramSettings settings {false, false, "", "", "", CipherMode::Encrypt};
    const std::vector<std::string>& cmdLineArgs{"Program_name", "-k", "0"};
    processCommandLine(cmdLineArgs, settings);
    REQUIRE(settings.cipherKey == "0");
}

TEST_CASE("Cipher mode is set correctly", "[alphanumeric]") {
    ProgramSettings settings {false, false, "", "", "", CipherMode::Encrypt};
    ProgramSettings settings2 {false, false, "", "", "", CipherMode::Encrypt};
    const std::vector<std::string>& cmdLineArgs{"Program_name", "--encrypt"};
    const std::vector<std::string>& cmdLineArgs2{"Program_name", "--decrypt"};
    processCommandLine(cmdLineArgs, settings);
    processCommandLine(cmdLineArgs2, settings2);
    REQUIRE((settings.ciphermode == CipherMode::Encrypt) & (settings2.ciphermode == CipherMode::Decrypt));
}

// There is probably a better way to test both help commands than writing two sets of code
TEST_CASE("Help is requested", "[alphanumeric]") {
    ProgramSettings settings {false, false, "", "", "", CipherMode::Encrypt};
    ProgramSettings settings2 {false, false, "", "", "", CipherMode::Encrypt};
    const std::vector<std::string>& cmdLineArgs{"Program_name", "-h"};
    const std::vector<std::string>& cmdLineArgs2{"Program_name", "--help"};
    processCommandLine(cmdLineArgs, settings);
    processCommandLine(cmdLineArgs2, settings2);
    REQUIRE((settings.helpRequested == true) & (settings2.helpRequested == true));
}

TEST_CASE("Version is requested", "[alphanumeric]") {
    ProgramSettings settings {false, false, "", "", "", CipherMode::Encrypt};
    const std::vector<std::string>& cmdLineArgs{"Program_name", "--version"};
    processCommandLine(cmdLineArgs, settings);
    REQUIRE(settings.versionRequested == true);
}
