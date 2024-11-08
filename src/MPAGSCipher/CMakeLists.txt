# - Build cub-script for the MPAGSCipher library

# - Declare the build of the static MPAGSCipher library
add_library(MPAGSCipher STATIC 
 CipherMode.hpp
 CaesarCipher.hpp
 CaesarCipher.cpp 
 ProcessCommandLine.cpp
 ProcessCommandLine.hpp
 TransformChar.hpp
 TransformChar.cpp
 )

# - Need to declare the C++ features and header serach paths needed for MPAGSCipherr

target_include_directories(MPAGSCipher PUBLIC ${CMAKE_CURRENT_LIST_DIR})

target_compile_features(MPAGSCipher PUBLIC cxx_auto_type cxx_range_for cxx_uniform_initialization)