// Amaëlle DIOP - 461543 - HPC assignment
// Created by amaelle.diop on 21/01/2025.
// ---This is the header file the serial version of the branch-to-bound solving of the wondering salesman problem---//

#ifndef BRANCH_TO_BOUND_H
#define BRANCH_TO_BOUND_H

#include <vector>
#include <string>
#include <utility>

int distance(const std::vector<std::vector<int>>& matrix, const std::vector<int>& path);
void branchAndBound(const std::vector<std::vector<int>>& matrix,
                    std::vector<int>& currentPath,
                    std::vector<bool>& visited,
                    int& bestDist,
                    std::vector<int>& bestPath);
std::pair<std::vector<int>, int> solveWanderingSalesman(const std::vector<std::vector<int>>& distances);

#endif