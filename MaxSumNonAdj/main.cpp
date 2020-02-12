//
//  main.cpp
//  MaxSumNonAdj
//
//  Created by adeeb mohammed on 19/01/20.
//  Copyright © 2020 adeeb mohammed. All rights reserved.
//
// a function to find out the maximum sum of the adjasent numbers

#include <iostream>
#include <vector>

int maxSubsetSumNoAdjacent(std::vector<int> array){
    if(array.size() == 0){
        return 0;
    }else if(array.size() ==  1){
        return array.at(0);
    }
    int tempSum     = 0;
    int prevSum     = array.at(0);
    int greatestSum = std::max(array.at(0),array.at(1));
    for(int i = 2; i < array.size(); ++i){
        tempSum = greatestSum;
        greatestSum = std::max(greatestSum,prevSum+array.at(i));
        prevSum = tempSum;
        
    }
    return greatestSum;
}

// time complexity is o(n) , space complexity is
int maxSubsetSumNoAdjacentOrg(std::vector<int> array) {
    if(array.size() == 0){
        return 0;
    }else if(array.size() == 1){
        return array.at(0);
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
    std::cout << "Sum of non adjascent numbers:"<<maxSubsetSumNoAdjacentOrg({75,105,120,75,90,135}) << std::endl;
    return 0;
}
