/*
 * LmpDumpFileInfo.cpp
 *
 *  Created on: Jul 11, 2017
 *      Author: wk234832
 */

#include "LmpDumpFileInfo.h"
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>

LmpDumpFileInfo::LmpDumpFileInfo() {
	// TODO Auto-generated constructor stub

	nHeader = 9;
	nTypes = 0;
	nLines = 0;
	fname = "";
	ortho = true;

}

LmpDumpFileInfo::LmpDumpFileInfo(std::string  &p){
	// Constructor using filename
	std::ifstream fin;

	fname = p;
	fin.open(fname.c_str());

	if (!fin){
		std::cout << "Error: File does not exist\n";
		exit(1);
	}


	nHeader = 9;
	nTypes = 1;
	nLines = 0;
	ortho = true;

	std::string line;
	int lineType;
	std::stringstream convert("0");
	int tmp;
	float tmp2;
	std::string tmp3;

	while (getline (fin,line)){
		nLines++;
		//line = line.substr(0,line.size()-1); //remove new line character
		lineType = dump_line_int(line);

		switch (lineType) {
			case 1: getline(fin,line);
					convert.str(line);
					convert.clear();
					convert >> tmp;
					steps.push_back(tmp);
					break;

			case 2: getline(fin, line);
					convert.str(line);
					convert.clear();
					convert >> tmp;
					nAtoms.push_back(tmp);
					break;

			case 3: if (line.substr(17,2) == "xy"){ortho = false;}
					getline (fin, line);
					convert.str(line);
					convert.clear();
					convert >> origin[0];
					convert >> tmp2;
					if (!ortho){ convert >> boxY[0];}
					boxX[0] = tmp2 - origin[0];
					getline (fin, line);
					convert.str(line);
					convert.clear();
					convert >> origin[1];
					convert >> tmp2;
					if (!ortho){ convert >> boxZ[0];}
					boxY[1] = tmp2 - origin[1];
					getline (fin, line);
					convert.str(line);
					convert.clear();
					convert >> origin[2];
					convert >> tmp2;
					if (!ortho){ convert >> boxZ[1];}
					boxZ[2] = tmp2 - origin[2];
					break;

			case 4: if (fields.size()>0) {break;}
					line = line.substr(12,line.size()-12);
					convert.str(line);
					convert.clear();
					convert >> tmp3;
					while(convert){
						fields.push_back(tmp3);
						convert >> tmp3;
					}
					break;

			default: break;

		}
	}//end while read file

}//end constructor

LmpDumpFileInfo::~LmpDumpFileInfo() {
	// TODO Auto-generated destructor stub
}


int LmpDumpFileInfo::dump_line_int(std::string &line){
	if (line == "ITEM: TIMESTEP"){
		return 1;
	}
	if (line == "ITEM: NUMBER OF ATOMS"){
		return 2;
	}
	if (line.substr(0,9) == "ITEM: BOX BOUNDS"){
		return 3;
	}
	if (line.substr(0,11) == "ITEM: ATOMS"){
		return 4;
	}
	return 0;

}

std::string LmpDumpFileInfo::toString(){
	std::string tmp = "";
	std::ostringstream convert;

	convert << nLines;
	tmp += "     Filename: " + fname + " - " + convert.str() + " lines.";

	convert.str("");
	convert << steps.size();

	tmp += "\n     " + convert.str() +" Timesteps: ";
	std::list<int>::iterator it;
	int nSteps = steps.size();
	int nShow = 4;
	int cntr = 0;
	for (it = steps.begin(); it != steps.end(); ++it){
		if (cntr < nShow or (nSteps-cntr)<nShow){
			convert.str("");
			convert << *it;
			tmp += " "+ convert.str();
		}
		cntr++;
	}

	it = nAtoms.begin();
	convert.str("");
	convert << *it;
	tmp += "\n     " + convert.str() + "/";
	it = nAtoms.end(); it--;
	convert.str("");
	convert << *it;
	tmp += convert.str() + " atoms on first/last timestep";
	//for (it=nAtoms.begin(); it != nAtoms.end(); ++it){
	//	convert << *it;
	//	tmp += " " + convert.str();
	//}

	convert.str("");
	convert << fields.size();
	tmp += "\n     " + convert.str() + " fields: ";
	std::list<std::string>::iterator itField;

	for (itField=fields.begin(); itField!=fields.end(); ++itField){
		convert.str("");
		convert << std::distance(fields.begin(),itField);
		tmp += *itField + ":" + convert.str() + "  ";
	}

	return tmp;
}
