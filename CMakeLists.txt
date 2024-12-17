cmake_minimum_required(VERSION 3.10)
project(Calculator VERSION 1.0.0 LANGUAGES CXX)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add compiler warnings
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Create library target
add_library(calculator_lib
    src/calculator.cpp
    src/calculator.h
)

target_include_directories(calculator_lib PUBLIC src)

# Add executable
add_executable(calculator src/main.cpp)
target_link_libraries(calculator PRIVATE calculator_lib)

# Install rules
install(TARGETS calculator calculator_lib
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)

install(FILES src/calculator.h
    DESTINATION include
)
