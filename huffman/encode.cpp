#include <iostream>
#include <fstream>
#include "huffman.hpp"
#include <sys/stat.h>

void printCompressionStats(const std::string& originalFile, const std::string& compressedFile);

int main() {

    HuffmanCoding huffman("inputFile.txt", "compressedFile.huf");
    huffman.compress();
    printCompressionStats("inputFile.txt", "compressedFile.huf");
    return 0;
}

void printCompressionStats(const std::string& originalFile, const std::string& compressedFile) {
    struct stat origStat, compStat;

    if (stat(originalFile.c_str(), &origStat) != 0 || stat(compressedFile.c_str(), &compStat) != 0) {
        std::cerr << "Error accessing files.\n";
        return;
    }

    std::cout << "Original file: " << originalFile << "\n";
    std::cout << "Original size: " << origStat.st_size << " bytes\n";
    std::cout << "Compressed file: " << compressedFile << "\n";
    std::cout << "Compressed size: " << compStat.st_size << " bytes\n";

    double ratio = 100.0 * (1.0 - (double)compStat.st_size / origStat.st_size);
    std::cout << "Compression ratio: " << ratio << "%\n";
}
