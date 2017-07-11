/*
 * LmpDumpFile.h
 *
 *  Created on: Jul 11, 2017
 *      Author: wk234832
 */

#ifndef LMPDUMPFILE_H_
#define LMPDUMPFILE_H_
#include "Vect3.h"
#include <list>

class LmpDumpFile {
public:
	LmpDumpFile();
	LmpDumpFile(char * fname);
	virtual ~LmpDumpFile();

private:
	int nHEADER = 9; // number of header lines in LAMMPS dump file

	int nLines = 0;
	int nTypes = 0;

	bool ortho = true;
	bool fileLoaded = false;

	Vect3 boxX;
	Vect3 boxY;
	Vect3 boxZ;

	std::list<int> steps;
	std::list<int> nAtoms;

	int dump_str_int(char* );

};

#endif /* LMPDUMPFILE_H_ */
