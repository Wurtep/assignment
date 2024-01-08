#include "assignment.hpp"
#include "node.hpp"
#include <iostream>
#include <cassert>

int main()
{
    std::vector<int> vec1 {-7,-5,-3,7,3};
    std::vector<int> vec2 {1,-7,-5,-3,7,3,-1,1};
    std::vector<int> vec3 {-999,1,0};
    assert(getClosestToZero(vec1) == 3);
    std::cout << "getClosesToZero on [-7,-5,-3,7,3] returned 3.\n";
    assert(getClosestToZero(vec2) == 1);
    std::cout << "getClosesToZero on [1,-7,-5,-3,7,3,-1,1] returned 1.\n";
    assert(getClosestToZero(vec3) == 0);
    std::cout << "getClosesToZero on [-999,1,0] returned 0.\n";


    std::vector<int> vec4 {0,0,-7,-5,0,-3,7,3,0,0};
    std::vector<int> vec5 {1,-7,-5,-3,7,3,-1,1};
    std::vector<int> vec6 {-999,1,0};
    std::vector<int> vec7 {0,1,0};
    std::vector<int> vec8 {0,0,0};
    assert(countChunks(vec4) == 2);
    std::cout << "countChunks on [0,0,-7,-5,0,-3,7,3,0,0] returned 2.\n";
    assert(countChunks(vec5) == 1);
    std::cout << "countChunks on [1,-7,-5,-3,7,3,-1,1] returned 1.\n";
    assert(countChunks(vec6) == 1);
    std::cout << "countChunks on [-999,1,0] returned 1.\n";
    assert(countChunks(vec7) == 1);
    std::cout << "countChunks on [0,1,0] returned 1.\n";
    assert(countChunks(vec8) == 0);
    std::cout << "countChunks on [0,0,0] returned 0.\n";


    // create root node
    auto root = std::make_unique<Node>(1);

    // create level 1 nodes
    auto leaf_lvl1_a = std::make_unique<Node>(2);
    root->addChild(std::move(leaf_lvl1_a));

    auto leaf_lvl1_b = std::make_unique<Node>(3);
    root->addChild(std::move(leaf_lvl1_b));

    auto leaf_lvl1_c = std::make_unique<Node>(4);
    root->addChild(std::move(leaf_lvl1_c));

    // create level 2 nodes
    // children of first leaf
    auto leaf_lvl2_1a_a = std::make_unique<Node>(5);
    dynamic_cast<Node*>(root->children().at(0).get())->addChild(std::move(leaf_lvl2_1a_a));

    auto leaf_lvl2_1a_b = std::make_unique<Node>(6);
    dynamic_cast<Node*>(root->children().at(0).get())->addChild(std::move(leaf_lvl2_1a_b));

    // child of second leaf
    auto leaf_lvl2_1b_a = std::make_unique<Node>(7);
    dynamic_cast<Node*>(root->children().at(1).get())->addChild(std::move(leaf_lvl2_1b_a));

    // child of third leaf
    auto leaf_lvl2_1c_a = std::make_unique<Node>(8);
    dynamic_cast<Node*>(root->children().at(2).get())->addChild(std::move(leaf_lvl2_1c_a));


    assert(getLevelSum(*root, 0) == 1);
    std::cout << "getLevelSum on the following tree:\n"
                "               [1]\n"
                "              / | \\\n"
                "            [2][3][4]\n"
                "            /|  |  | \n"
                "         [5][6][7][8]\n"
                "returned 1 for depth 0.\n";
    assert(getLevelSum(*root, 1) == 9);
    std::cout << "getLevelSum on the following tree:\n"
                "               [1]\n"
                "              / | \\\n"
                "            [2][3][4]\n"
                "            /|  |  | \n"
                "         [5][6][7][8]\n"
                "returned 9 for depth 1.\n";
    assert(getLevelSum(*root, 2) == 26);
    std::cout << "getLevelSum on the following tree:\n"
                "               [1]\n"
                "              / | \\\n"
                "            [2][3][4]\n"
                "            /|  |  | \n"
                "         [5][6][7][8]\n"
                "returned 26 for depth 2.\n";

    try {
        getLevelSum(*root, 5);
    }
    catch(...) {
    std::cout << "getLevelSum on the following tree:\n"
                "               [1]\n"
                "              / | \\\n"
                "            [2][3][4]\n"
                "            /|  |  | \n"
                "         [5][6][7][8]\n"
                "caused an exception with argument of depth being equal to 5.\n";
    }

    try {
        getLevelSum(*root, -1);
    }
    catch(...) {
        std::cout << "Negative depth does not make sense.\n";
    }    

    return 0;
}