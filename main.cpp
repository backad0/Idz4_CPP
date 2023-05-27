#include <iostream>
#include "cmake-build-debug/_deps/googletest-src/googletest/include/gtest/gtest.h"
#include "hashTable.cpp"

TEST(HachTable, Test1){
    hashTable p;
    p.insert(3, 4);
    p.insert(2, 3);
    p.insert(4, 5);
    p.insert(0, 1);
    p.insert(52, 2);
    int i = 1;
    for (auto it = p.begin(); it != p.end(); ++it) {
        std::cout << *it << " ";
        EXPECT_EQ(i,*it);
        i++;
    }
    EXPECT_EQ(1,1);
}
