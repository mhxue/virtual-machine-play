# About

A demo project used to play with virtual machine related technologies. It provided an assembler and a virtual machine.

## How to build

Make sure `cmake` is installed on your platform and after that run following command to build it.

1. Run `cmake -S . -B build` to generate to configurations on your platform.
1. Run `cmake --build build` to build the project
1. Locate and run the generated executables under the `build` folder, including:
    1. `assembler`, the executable of assembler used to transfer bytecode into binary code
    1. `vm`, the virtual machine executable can be used to simulate the run on a platform. In practice, it should be integrated as a library into a hosted app.

## Todo

1. Create a emulator
