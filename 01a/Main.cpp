#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void calc(int* a, char v[2]){
    // std::string tmp = v;
    *a += std::stoi (v);
    v[0] = '\0';
    v[1] = '\0';
}

int main() {

    // Open and check if the file is opened successfully
    std::ifstream inputFile("data.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error opening the file 'data.txt'" << std::endl;
        return 1; 
    }

    int sum = 0;
    
    std::string line;
    char tup[2];
    
    // read the file line by line
    while (std::getline(inputFile, line)) {
        // string stream to extract numbers from the line
        std::istringstream iss(line);        
        for (int i=0; i< line.length(); i++){
            if (std::isdigit(line[i])){
                if (tup[0] == '\0'){
                    tup[0] = line[i];
                } else {
                    tup[1] = line[i];
                }
            }
        }

        if (tup[1] == '\0'){
            tup[1] = tup[0];
        }

        calc(&sum, tup);
    }
        
    // close the file
    inputFile.close();

    std::cout << "Sum of numbers in 'data.txt': " << sum << std::endl;

    return 0;
}