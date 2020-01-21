//
//  main.cpp
//  MaxSumNonAdj
//
//  Created by adeeb mohammed on 19/01/20.
//  Copyright © 2020 adeeb mohammed. All rights reserved.
//

#include <iostream>
#include <vector>

int maxSubsetSumNoAdjacent(std::vector<int> array) {
    if(array.size() == 0){
        return 0;
    }else if(array.size() == 1){
        return array.at(1);
    }
    std::vector<int> resultArray = array;
    resultArray[1] = std::max(array[0],array[1]);
    for(int i = 2; i < array.size(); ++i){
        resultArray[i] = std::max(resultArray[i-1],resultArray[i-2]+array[i]);
    }
    return resultArray[array.size() - 1];
}

int main(int argc, const char * argv[]) {
    std::cout << "Sum of non adjascent numbers:"<<maxSubsetSumNoAdjacent({75,105,120,75,90,135}) << std::endl;
    return 0;
}
