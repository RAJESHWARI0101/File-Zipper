#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include "huffman.hpp"

void printDecompressionStats(const std::string& compressedFile, const std::string& decompressedFile);

int main() {
    HuffmanCoding huffman("compressedFile.huf", "outputFile.txt");
    huffman.decompress();
    printDecompressionStats("compressedFile.huf", "outputFile.txt");
    return 0;
}

void printDecompressionStats(const std::string& compressedFile, const std::string& decompressedFile) {
    struct stat compStat, decompStat;

    if (stat(compressedFile.c_str(), &compStat) != 0 || stat(decompressedFile.c_str(), &decompStat) != 0) {
        std::cerr << "Error accessing files.\n";
        return;
    }

    std::cout << "Compressed file: " << compressedFile << "\n";
    std::cout << "Compressed size: " << compStat.st_size << " bytes\n";
    std::cout << "Decompressed file: " << decompressedFile << "\n";
    std::cout << "Decompressed size: " << decompStat.st_size << " bytes\n";
}
