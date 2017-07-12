/*
 * LmpDumpFileInfo.h
 *
 *  Created on: Jul 11, 2017
 *      Author: wk234832
 */

#ifndef LmpDumpFileInfo_H_
#define LmpDumpFileInfo_H_
#include "Vect3.h"
#include <list>
#include <string>

class LmpDumpFileInfo {
public:
	LmpDumpFileInfo();
	LmpDumpFileInfo(std::string& );
	virtual ~LmpDumpFileInfo();
	std::string toString();

private:
	int nHeader; // number of header lines in LAMMPS dump file
	int nLines;
	int nTypes;

	bool ortho;

	std::string fname;

	Vect3 boxX;
	Vect3 boxY;
	Vect3 boxZ;
	Vect3 origin;

	std::list<int> steps;
	std::list<int> nAtoms;
	std::list<std::string> fields;

	int dump_line_int(std::string& );

};

#endif /* LmpDumpFileInfo_H_ */
