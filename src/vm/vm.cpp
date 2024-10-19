#include <iostream>
#include "definitions.h"
#include "loader.h"

using namespace std;

int main(int argc, const char* argv[]) {
    if(argc < 2) {
        cout << "Wrong usage, should be:" << endl;
        cout << "vm [image-file]" << endl;
        exit(2);
    }

    if(load(argv[1])) {
        cout << "Invalid image file at path: " << argv[1] << endl;
        exit(1);
    }

    return 0;
}