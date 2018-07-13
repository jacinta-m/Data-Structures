//============================================================================
// Name        : A3_Recursion.cpp
// Author      : Jacinta Moore
// Version     :
// Copyright   : Your copyright notice
// Description : Assignment 3: 4 functions using recursion
//============================================================================
#include <iostream>
#include <cassert>
#include <string>

using namespace std;

void triangle(ostream& outs, unsigned int m, unsigned int n){
// Precondition: m <= n
// Postcondition: The function has printed a pattern of 2*(n-m+1) lines
// to the output stream outs. The first line contains m asterisks, the next
// line contains m+1 asterisks, and so on up to a line with n asterisks.
// Then the pattern is repeated backwards, going n back down to m.

	assert (m<= n);
	outs<< string(m,'*')<<endl;
	if (m < n){
		triangle(outs,m+1,n);
		outs<< string(m,'*')<<endl;
	}
	else {outs<< string(m,'*')<<endl;}
}

void numbers(ostream& outs,const string& prefix, unsigned int levels){
//Precondition: levels >= 0
//Postcondition: The function prints output to the ostream outs.
//The output consists of the String prefix followed by "section numbers"
//of the form 1.1., 1.2., 1.3., and so on.

	assert (levels >=0);
	if (levels >1){
		numbers(outs,prefix,levels-1);
		for(int i =1; i<10;++i){
			string s = prefix + char(levels+'0')+ '.'+ char(i +'0');
			outs<<s<<endl;
		}
	}
	else if (levels==1){
		for(int i =1; i<10;++i){
			string s = prefix + char(levels+'0')+ '.'+ char(i +'0');
			outs<<s<<endl;
	}
	}
	else{outs<<prefix<<endl;}
}

bool bears(int tn){
// Postcondition: A true return value means that it is possible to win
// the bear game by starting with n bears. A false return value means that
// it is not possible to win the bear game by starting with n bears.
// Examples:
//   bear(250) is true (as shown above)
//   bear(42) is true
//   bear(84) is true
//   bear(53) is false
//   bear(41) is false

	if (tn==42){return true;}
	else if(tn<42){return false;}
	else if (tn%2==0){bears(tn/2); return true;}
	else if(tn%3==0 ||tn%4==0){
			bears((tn%10)*((tn%100)/10)); return true;}
	else if (tn%5==0){
			bears((tn-42));return true;}
	else {return false;}
}

void pattern(ostream& outs, unsigned int n, unsigned int i){
// Precondition: n is a power of 2 greater than zero.
// Postcondition: A pattern based on the above example has been
// printed to the ostream outs. The longest line of the pattern has
// n stars beginning in column i of the output. For example,
// The above pattern is produced by the call pattern(cout, 8, 0).
	assert (n>0 && !(n &(n-1)));

	if (n ==1) {
	for(unsigned int k = 0; k < i; k++)
		outs << " ";
		outs << "* ";
	}
	else{
	pattern(outs,n/2, i);
	outs<<endl;
	for(unsigned int k = 0; k < i; k++)
		outs << " ";
	for(unsigned int k = 0; k < n; k++)
		outs << "* ";
		outs << endl;
	pattern(outs, n/2, i+n);
	}
}


int main() {
	unsigned m,n, levels, teddys,nn,i;
	string prefix;
	cout<< "Welcome to Triangle! "<<endl;
	cout<< "Please enter a value for m "<<endl;
	cin>>m;
	cout<<"Please enter a value for n"<<endl;
	cin>>n;
	triangle(cout, m,n);

	cout<< "Please enter a string prefix "<<endl;
	cin>>prefix;
	cout<<"Please enter a value for levels"<<endl;
	cin>>levels;
	numbers(cout,prefix,levels);

	cout<< "Welcome to Teddys Bear Picnic Game! "<<endl;
	cout<<"Please enter a teddy bear number"<<endl;
	cin>>teddys;
	bool win=false;
	win = bears(teddys);
	if(win==true){
		cout<<teddys<< " teddys wins the game"<<endl;
	}
	else{
			cout<<teddys<< " teddys doesn't win the game"<<endl;
		}
	cout<< "Welcome to Pattern "<<endl;
	cout<< "Please enter a value for the stars "<<endl;
	cin>>nn;
	cout<<"Please enter a value for the i"<<endl;
	cin>>i;
	pattern(cout,nn,i);

	return 0;
}
