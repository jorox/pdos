/*
 * LmpSnapshot.h
 *
 *  Created on: Jul 12, 2017
 *      Author: wk234832
 */

#ifndef LMPSNAPSHOT_H_
#define LMPSNAPSHOT_H_

#include <vector>

class LmpSnapshot {
public:
	LmpSnapshot();
	LmpSnapshot(int,int,int);
	virtual ~LmpSnapshot();

	int load_field_data(int, int, float);
	const std::vector<float> get_field(int);
	void sort_by_field(int);

private:
	int timestep;
	int nAtoms;
	int nFields;
	std::vector< std::vector<float> > data;

};

#endif /* LMPSNAPSHOT_H_ */
