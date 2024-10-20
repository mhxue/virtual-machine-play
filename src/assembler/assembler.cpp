#include <iostream>
#include <fstream>
#include <sstream>

#include "instruction.cpp"

using namespace std;

int load_byte_code(const char* bc_file, const char* output_file) {
    ifstream file(bc_file);

    string out_file_path(output_file);
    ofstream output(out_file_path, std::ios::binary);
    if(!file.is_open()) {
        return 1;
    }
    if(!output) {
        return 1;
    }
    string line;
    while(getline(file, line)) {
        cout << line << endl;
        stringstream ss(line);
        vector<string> components;
        string word;
        while(ss >> word) {
            components.push_back(word);
        }

        auto op_code = components[0];
        Instruction instruction;
        if (op_code == "OP_TRAP")
        {
            auto trap_code = components[1];
            instruction = TrapInstruction(OP_TRAP, parseTrapCode(trap_code));
        }
        output.write((char* )&instruction, sizeof(instruction));
    };
    file.close();
    return 0;
}

/*
The assembler which assembles the bytecode into binary format.
Each instruction is coded in a 16bits long format.
*/
int main(int argc, const char* argv[]) {
    if(argc < 3) {
        cout << "Wrong usage, should be:" << endl;
        cout << "assembler [bytecode-file] [output-file]" << endl;
        exit(2);
    }

    if(load_byte_code(argv[1], argv[2])) {
        cout << "Invalid image file at path: " << argv[1] << endl;
        exit(1);
    }
    return 0;
}
