cmake_minimum_required(VERSION 3.30)

# A project to play with virtual machine based technolies
project(VIRTUAL_MACHINE_PLAY
            VERSION 0.1
            LANGUAGES CXX)

# The assembler
add_subdirectory(src/assembler)

# The virtual machine
add_subdirectory(src/vm)