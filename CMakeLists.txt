cmake_minimum_required(VERSION 3.10)
project(MarkovGenerator)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(markov
    main.cpp
    src/tokenizer.cpp
    src/markov_chain.cpp
    src/generator.cpp
)
