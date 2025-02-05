// Amaëlle DIOP - 461543 - HPC Assignment
// Created by amaelle.diop on 21/01/2025.
// ---This is the main script--- //

#include <iostream>
#include <iomanip>
#include "pre-work.cpp"
#include "branch-to-bound.h"

int main() {
    try {
        std::string file = "cities/dist17"; // Input file path
        std::cout << "Reading file: " << file << "\n";

        std::vector<std::vector<int>> distances = function_distances(file);

        if (distances.empty()) {
            std::cerr << "Error: Empty matrix returned\n";
            return 1;
        }

        std::cout << "\nInput matrix successfully read.\n";
        printMatrix(distances);

        if (distances.size() < 2) {
            std::cerr << "Error: Matrix too small for path finding\n";
            return 1;
        }

        auto [bestPath, bestDist] = solveWanderingSalesman(distances);

        std::cout << "\nBest path found: ";
        for (int city : bestPath) {
            std::cout << (city + 1) << " "; // Convert to 1-based index for display
        }
        std::cout << "\nTotal distance: " << bestDist << "\n";

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    } catch (...) {
        std::cerr << "Unknown error occurred\n";
        return 1;
    }

    return 0;
}