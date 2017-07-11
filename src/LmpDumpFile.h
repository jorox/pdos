/*
 * LmpDumpFile.h
 *
 *  Created on: Jul 11, 2017
 *      Author: wk234832
 */

#ifndef LMPDUMPFILE_H_
#define LMPDUMPFILE_H_
#include "Vect3.h"

class LmpDumpFile {
public:
	LmpDumpFile();
	LmpDumpFile(char * fname);
	virtual ~LmpDumpFile();

private:
	int nLines, nTypes, nAtoms, nHeaders;
	bool ortho;
	Vect3 boxX;
	Vect3 boxY;
	Vect3 boxZ;


};

#endif /* LMPDUMPFILE_H_ */
