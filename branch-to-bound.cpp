// Amaëlle DIOP - 461543 - HPC assignment
// Created by amaelle.diop on 21/01/2025.
// ---This script performs the serial version of the branch-to-bound solving of the wondering salesman problem---//


#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <string>

// Function to calculate the total distance of a path
int distance(const std::vector<std::vector<int>>& matrix, const std::string& path) {
    int res = 0;
    for (size_t i = 0; i < path.size() - 1; i++) {
        int city_1 = path[i] - '1';    // Convert char to 0-based index
        int city_2 = path[i + 1] - '1'; // Convert char to 0-based index
        res += matrix[city_1][city_2]; // Add distance between city_1 and city_2
    }
    return res;
}

// Branch and bound function to explore all possible paths
void branchAndBound(const std::vector<std::vector<int>>& matrix,
                    std::string currentPath,
                    std::vector<bool>& visited,
                    int& bestDist,
                    std::string& bestPath) {
    int n = matrix.size();

    // If all cities are visited, calculate the total distance of the path
    if (currentPath.length() == n) {
        int currentDist = distance(matrix, currentPath);
        if (currentDist < bestDist) {
            bestDist = currentDist; // Update the best distance
            bestPath = currentPath; // Update the best path
        }
        return;
    }

    // Explore all unvisited cities
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            currentPath += std::to_string(i + 1); // Append the city (1-based index)

            branchAndBound(matrix, currentPath, visited, bestDist, bestPath);

            // Backtrack
            currentPath.pop_back();
            visited[i] = false;
        }
    }
}

// Function to solve the wandering salesman problem
std::pair<std::string, int> solveWanderingSalesman(const std::vector<std::vector<int>>& distances) {
    int n = distances.size();
    std::string bestPath;
    int bestDist = INT_MAX;

    // Try each city as the starting point
    for (int startCity = 0; startCity < n; startCity++) {
        std::vector<bool> visited(n, false);
        visited[startCity] = true;

        std::string currentPath = std::to_string(startCity + 1); // Start with the starting city

        branchAndBound(distances, currentPath, visited, bestDist, bestPath);
    }

    return {bestPath, bestDist};
}