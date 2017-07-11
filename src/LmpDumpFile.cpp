/*
 * LmpDumpFIle.cpp
 *
 *  Created on: Jul 11, 2017
 *      Author: wk234832
 */

#include "LmpDumpFile.h"
#include <fstream>
#include <string>

LmpDumpFile::LmpDumpFile() {
	// TODO Auto-generated constructor stub

}

LmpDumpFile::LmpDumpFile(char * fname){
	// Constructor using filename
	std::ifstream fin;
	fin.open(fname);

	if (!fin){
		fileLoaded = false;
	}
	else{
		fileLoaded = true;
	}

	std::string line;
	while (getline (fin,line)){
		nLines++;
		//line = line.substr(0,line.size()-1); //remove new line character
		switch (line) {
		case "ITEM: TIMESTEP" : getline(fin,line);
								steps.push_back(atoi(line.c_str()));
								break;

		case "ITEM: NUMBER OF ATOMS" : getline(fin, line);
										atoi(line.c_str());
										nAtoms.push_back(atoi(line.c_str()));
										break;
		}

	}

}

LmpDumpFile::~LmpDumpFile() {
	// TODO Auto-generated destructor stub
}
