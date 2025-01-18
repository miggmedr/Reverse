#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

void Reverse(const std::string& input, const std::string& output) {
    std::ifstream file(input);
    if (!file) {
        std::cerr << " Unable to open input file " << input << std::endl;
        return;
    }

    std::string word((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();

    std::reverse(word.begin(), word.end());

    std::ofstream outFile(output);
    if (!outFile) {
        std::cerr << "Error: Unable to open output file: " << output << std::endl;
        return;
    }

    outFile << word;
    outFile.close();
}

int main() {
    const std::string input = "C:/Users/migue/Downloads/CSC450_CT5_mod5.txt";
    const std::string output = "C:/Users/migue/Downloads/CSC450-mod5-reverse.txt";

    Reverse(input, output);

    std::cout << "File processing completed. " << output << std::endl;

    return 0; 
}
