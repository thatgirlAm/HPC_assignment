// Amaëlle DIOP - 461543 - HPC assignment
// Created by amaelle.diop on 21/01/2025.
// ---This script allows the transformation of .txt files to readable data---//

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdio>

std::vector<std::vector<int>> function_distances(const std::string& file) {
    FILE* MyFile = fopen(file.c_str(), "r");
    if (!MyFile) {
        std::cerr << "Error: File not found: " << file << "\n";
        return {};
    }

    int N = 0;
    fscanf(MyFile, "%d", &N); // Read the number of cities
    std::cout << "Number of cities: " << N << "\n";

    // Initialize the symmetric matrix with zeros
    std::vector<std::vector<int>> matrix(N, std::vector<int>(N, 0));
    std::cout << "Matrix initialized with size " << N << "x" << N << "\n";

    // Read distances row by row
    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1; j < N; ++j) {
            int distance;
            if (fscanf(MyFile, "%d", &distance) == 1) {
                std::cout << "Setting distance between city " << (i + 1)
                          << " and city " << (j + 1) << " = " << distance << "\n";
                matrix[i][j] = distance;
                matrix[j][i] = distance; // Ensure symmetry
            } else {
                std::cerr << "Error: Missing distance value in input file.\n";
                fclose(MyFile);
                return matrix;
            }
        }
    }

    fclose(MyFile);

    // Print the final matrix for verification
    std::cout << "\nFinal matrix content:\n";
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << std::setw(4) << val << " ";
        }
        std::cout << "\n";
    }

    return matrix;
}



void printMatrix(const std::vector<std::vector<int>>& matrix) {
    if (matrix.empty()) {
        std::cout << "Empty matrix\n";
        return;
    }

    std::cout << "Distance Matrix:\n";
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << std::setw(4) << val << " ";
        }
        std::cout << "\n";
    }
}