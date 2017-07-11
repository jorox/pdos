//============================================================================
// Name        : pdos.cpp
// Author      : Wassim Kassem
// Version     : 0.1
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]) {
	float _PROGVER = 0.01;
	int numOfLines = 0;


	cout << "Phonon Density of States Calculator ver. " << _PROGVER << endl; // prints !!!Hello World!!!
	cout << "=====================================================" << endl;
	string fname (argv[1]);
	cout << "   ... input file: " << fname;

	ifstream dumpFile;
	dumpFile.open(fname.c_str());
	if (!dumpFile){
		cout << "!! Error cannot open file !!" << endl;
		exit(1); //terminate with error
	}
	string line;
	while (getline (dumpFile,line)){
		numOfLines++;
	}
	cout << " " << numOfLines << " lines " << endl;



	return 0;
}
