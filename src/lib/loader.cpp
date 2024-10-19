#include "loader.h"

#include <fstream>
#include <iostream>

using namespace std;

int load(const char* image_file) {
    ifstream file(image_file);
    if(!file.is_open()) {
        return 1;
    }
    string content;
    while(getline(file, content)) {
        cout << content << endl;
    };
    file.close();
    return 0;
} 