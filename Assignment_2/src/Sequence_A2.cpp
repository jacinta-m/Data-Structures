//============================================================================
// Name        : Sequence_A2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Assignment 2 - Implementation of a sequence container class
// INVARIANT for the sequence class:
// 1. The number of items in the sequence is in the member variable used.
// 2. For a sequence, the items are stored in data[0] through data[used-1], and
//    are stored in order.
// 3. If there is a current item, then it lies in data[current_index]; if there is
//   no current item, then current_index equals used.
//============================================================================

#include <iostream>
#include "Sequence2.h"
#include <cassert>
using namespace std;
using namespace main_savitch_3;

namespace main_savitch_3{
	sequence::sequence(){used=0; current_index=0;};

    void sequence::start( ){
    	current_index = 0;
    }

    void sequence::advance( ){
    	assert (is_item());
    	++current_index;
    }

    void sequence::insert(const value_type& entry){
    	size_type i;
    	assert (size()<CAPACITY);
    	if(!is_item()){
    		current_index = 0;}
    	for(i=used; i > current_index; i--){
    		data[i] = data[i -1];}
    	data[current_index]= entry;
    	++used;
    }

    void sequence::attach(const value_type& entry){
    	size_type i;
  		assert ( size()< CAPACITY);
  		if(!is_item()){
  			data[used]=entry;
  			}
  		else {for(i=used; i > current_index; i--)
    			data[i] = data[i-1];
    		data[current_index+1]= entry;
    		++current_index;}
    	++used;
    }

    void sequence::remove_current( ){
    	assert(is_item());
    	size_type i;
    	for(i=current_index; i < (used-1); ++i){
    		data[i] = data[i+1];}
    	--used;
    }

    // CONSTANT MEMBER FUNCTIONS
    sequence::size_type sequence::size( ) const{
    	return used;
	}

    bool sequence::is_item( ) const {
    	return (current_index < used );
    }

    sequence::value_type sequence:: current( ) const{
    	assert (is_item());
    	return data[current_index];
    }
}
