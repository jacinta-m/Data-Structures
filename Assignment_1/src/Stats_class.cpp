//============================================================================
// Name        : Moore_DS_A1.cpp
// Author      : Jacinta Moore
// Version     :
// Copyright   : Your copyright notice
// Description : Assignment 1 - A statistician class which calculates
//				 the statistics of a sequence of input numbers
//============================================================================

#include <iostream>
#include "Assignment1.h"
#include <cassert>
using namespace std;
using namespace main_savitch_2C;

namespace main_savitch_2C{
statistician ::statistician(): count(0), total(0), tinyest(0), largest(0){}
//member function to get the next number in the statistician
void statistician :: next(double r){
	if (count >0){
		if (r < tinyest){
			tinyest = r;
		}
		if (r > largest){
			largest = r;
		}
	}
	else{
		tinyest = r; largest = r;
	}
	++ count;
	total += r;
}
void statistician :: reset(){count=0; total=0; tinyest=0; largest=0;}
double statistician :: mean ()const{
	assert (count>0);
	return total/count;
}
int statistician :: length( ) const{
	return count;
}
double statistician :: minimum( ) const{
	assert(count > 0);
	return tinyest;
}
double statistician :: maximum( ) const{
	assert(count>0);
	return largest;
}
double statistician ::sum( ) const{
	return total;
}

statistician operator +(const statistician& s1, const statistician& s2){
    if(s1.count == 0){
	     return s2;
	  }
	else if(s2.count == 0){
	     return s1;
	  }
	else{
		statistician s3;
		s3.count = s2.count + s1.count;
		s3.total = s2.total + s1.total;
		if (s1.tinyest < s2.tinyest){s3.tinyest = s1.tinyest;}
		else {s3.tinyest = s2.tinyest;}
		if (s1.largest>s2.largest){s3.largest = s1.largest;}
		else{s3.largest = s2.largest;}
		return s3;
	  }
}
statistician operator *(double scale, const statistician& s){
	statistician n;
	n.count = s.count;
	n.total = scale*s.total;
	if (scale <0){
	n.tinyest = scale * s.largest;
	n.largest = scale* s.tinyest;}
	else{
	n.tinyest = scale * s.tinyest;
	n.largest = scale * s.largest;
	}
	return n;
}

bool operator ==(const statistician& s1, const statistician& s2){
	if(s1.length() == 0 && s2.length() == 0){return true;}
	else if (s1.length()==s2.length()&& s1.mean()==s2.mean()&& s1.sum()==s2.sum()&& s1.minimum()==s2.minimum()&& s1.maximum()==s2.maximum()){
	return (true);}
	else {return false;}
}
}
void printstats(const statistician& s1){
	cout<<"The length = "<<s1.length()<<endl;
	cout<<"The sum = "<<s1.sum()<<endl;
	cout<<"The mean = "<<s1.mean()<<endl;
	cout<<"The minimum = "<<s1.minimum()<<endl;
	cout<<"The maximum = "<<s1.maximum()<<endl;
}
int main() {
	statistician s, t, u, v;
	char choice;
	double num;
	cout<< "Welcome to Statistician!, Please choose the which operation you would like to do.."<<endl;
	while (true){
		cout<< "Enter A - to add a number to sequence 1"<<endl;
		cout<< "Enter B - to add a number to sequence 2"<<endl;
		cout<< "Enter C - to compare sequence 1 with sequence 2"<<endl;
		cout<< "Enter D - to create a new sequence by adding sequences 1 and 2 together"<<endl;
		cout<<" Enter E - to apply a multiplier to sequence 1 or 2"<<endl;
		cout<<"Enter Q - to quit the program"<<endl;
		cin>> choice;
		if (choice == 'Q'|| choice =='q'){ break;}
		if (choice == 'A'||choice =='a'){
			cout<<"Please enter a number to add to sequence 1"<<endl;
			cin >> num;
			s.next(num);
			cout<<"The statistics for sequence 1 are.."<<endl;
			printstats (s);
		}
		if (choice == 'B'||choice =='b'){
			cout<<"Please enter a number to add to sequence 2"<<endl;
			cin >> num;
			t.next(num);
			cout<<"The statistics for sequence 2 are.."<<endl;
			printstats(t);
		}
		if (choice == 'C'||choice =='c'){
			if ( s == t){ cout << "The sequences are the same"<<endl;}
			else {cout<< "The two sequences are different"<<endl;
			}
		}
		if (choice == 'D'||choice =='d'){
			u = s + t;
			cout<<"The statistics for adding the two sequences together are.."<<endl;
			printstats(u);
		}
		if (choice == 'E'||choice =='e'){
			cout <<"Please enter the amount you wish to scale the statistician by.." <<endl;
			double multip;
			cin>>multip;
			cout<< "Please select which sequence 1 or 2 you wish to scale"<<endl;
			int seq;
			cin>>seq;
			if(seq == 1){
				v = multip * s;
			}
			else if (seq ==2){
				v = multip * t;
			}
			else { cout<< " incorrect input for sequence number"<<endl;}
			cout << "The statistics for the new scaled sequence is: "<<endl;
			printstats(v);
		}
	}
	return 0;
}

