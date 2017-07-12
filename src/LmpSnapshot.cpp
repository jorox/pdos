/*
 * LmpSnapshot.cpp
 *
 *  Created on: Jul 12, 2017
 *      Author: wk234832
 */

#include "LmpSnapshot.h"
#include <vector>

LmpSnapshot::LmpSnapshot() {
	// TODO Auto-generated constructor stub
	timestep = 0;
	nFields = 0;
	nAtoms = 0;


}

LmpSnapshot::~LmpSnapshot() {
	// TODO Auto-generated destructor stub
}

LmpSnapshot::LmpSnapshot(int step, int nf, int na){
	timestep = step;
	nFields = nf;
	nAtoms = na;

	data.resize(nFields,std::vector<float>(nAtoms));
}

int LmpSnapshot::load_field_data(int iField, int iAtom, float datum){
	if (iField > nFields or iAtom > nAtoms){
		return 1;
	}

	data[iField][iAtom] = datum;
	return 0;
}

const std::vector<float> LmpSnapshot::get_field(int iField){
	if ( iField < 0 ){
		iField += nFields;
	}
	if ( iField > nFields){
		iField -= nFields;
	}

	return data[iField];

}

void LmpSnapshot::sort_by_field(int iField){
	struct by_field{
		bool operator()(float a, float b)
	};
}
