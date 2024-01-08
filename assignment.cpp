#include <vector>
#include <cstdint>
#include <cmath>
#include <algorithm>
#include <stdexcept>
#include <iostream>

#include "INode.hpp"
#include "node.hpp"

/*
 * General rules:
 * - You can use modern C++ features (anything that is supported by modern compilers)
 * - Try to validate input parameters if it makes sense, throw exceptions if needed
 * - You are allowed to use STL (so adding includes is allowed)
 */

/**
 * Implement a method that returns number that is closest to zero in a given vector.
 * If there are two equally close to zero elements like 2 and -2,
 * then consider the positive element to be "closer" to zero.
 */
int getClosestToZero(const std::vector<int>& arr) {
    if (arr.empty())
        throw std::invalid_argument("Input vector cannot be empty.");
    
    auto comp = [](int a, int b) {
        // if two elements are equal, prefer the positive one
        if (std::abs(a) == std::abs(b))
            return a > b;
        // otherwise compare based on closeness to zero
        return std::abs(a) < std::abs(b);
    };

    return *std::min_element(arr.begin(), arr.end(), comp);
}

/**
 * Please implement this method to return count of chunks in given array.
 *
 * Chunk is defined as continuous sequence of one or more non-zero numbers separated by one or more zeroes.
 * Input can contain leading and trailing zeroes.
 *
 * Example: [5, 4, 0, 0, -1, 0, 2, 0, 0] contains 3 chunks
 */
std::size_t countChunks(const std::vector<int>& arr) {
    if (arr.empty())
        throw std::invalid_argument("Input vector cannot be empty.");
    
    // start counting chunks from 1 if there are no leading zeroes
    std::size_t count = arr.front() != 0 ? 1 : 0;

    for(auto it = arr.begin(); it != arr.end(); ) {
        it = std::adjacent_find(it, arr.end(), [](int a, int b) {
            return (a == 0 && b != 0);
        });

        // transition from zero to non-zero found => chunk found
        if( it != arr.end() && *it == 0)
            count++;

        if(it != arr.end())
            it++;

    }

    return count;
}

/**
 * Open INode.h to see the INode interface.
 *
 * Implement following function that shall traverse the tree,
 * and return the sum of the values (INode.value()) of all nodes
 * at the level 'n' in the tree.
 * 
 * Node root is assumed to be at the level 0. All its children are level 1, etc.
 */
int getLevelSum(const INode& root, std::size_t n) {
    if(n == 0)
        return root.value();

    if(root.children().empty() && n > 0)
        throw std::invalid_argument("Depth specified by the argument does not exist in the tree.");

    int sum = 0;
    for(const auto& child : root.children() ) {
        sum += getLevelSum(*child.get(), n-1);
    }

    return sum;
}

/**
 * Imagine a sort algorithm, that sorts array of integers by repeatedly reversing
 * the order of the first several elements of it.
 *
 * For example, to sort [12,13,11,14], you need to reverse the order of the first two (2)
 * elements. You will get [13,12,11,14].
 * Then you shall reverse the order of the first three (3) elements,
 * and you will get [11,12,13,14]
 *
 * For this assignment you shall implement function
 * that returns list of integers corresponding to the required reversals.
 * E.g. for given vector [12,13,11,14]
 * the function should return [2, 3].
 */
// std::vector<std::size_t> getReversalsToSort(const std::vector<int>& arr) {
// }
