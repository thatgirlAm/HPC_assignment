// Amaëlle DIOP - 461543 - HPC assignment
// Created by amaelle.diop on 21/01/2025.
// ---This is the header file the serial version of the branch-to-bound solving of the wondering salesman problem---//

#ifndef BRANCH_TO_BOUND_H
#define BRANCH_TO_BOUND_H

#include <vector>
#include <string>
#include <utility>

int distance(const std::vector<std::vector<int>>& matrix, const std::string& path);
void branchAndBound(const std::vector<std::vector<int>>& matrix,
                    std::string currentPath,
                    std::vector<bool>& visited,
                    int& bestDist,
                    std::string& bestPath);
std::pair<std::string, int> solveWanderingSalesman(const std::vector<std::vector<int>>& distances);

#endif