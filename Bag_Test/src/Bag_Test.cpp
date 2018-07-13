//============================================================================
// Name        : Bag_Test.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm> // Provides copy function
#include <cassert> // Provides assert function
#include "bag_t.h"
using namespace std;
using namespace main_savitch_4;
namespace main_savitch_4{

const bag::size_type bag::DEFAULT_CAPACITY;

bag::bag(size_type initial_capacity){
data = new value_type[initial_capacity];
capacity = initial_capacity;
used = 0;
}
}
