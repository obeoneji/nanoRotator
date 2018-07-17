
#include <iostream>
#include "nanoRotator.h"



int main(int argc, char * argv[])
{
	// connect with and open nanoRotator
	int serialNo = 40871779;
	char rotSerialNo[16];
	sprintf_s(rotSerialNo, "%d", serialNo);
	int nanoRot_err;

	nanoRot_err = connect_nanoRotator(rotSerialNo);

	if (nanoRot_err == -1)
	{
		std::cout << "nanoRotator connection error!!!" << std::endl;
	}

	////////// init nanoRotator
	//device unit
	int initPos = 0; // Position
	int initVeloc = 37546290; // Velocity
	int initAcc = 18773140; // Acceleration

	nanoRot_err = init_nanoRotator(rotSerialNo, initPos, initVeloc, initAcc);
	if (nanoRot_err == -1)
	{
		std::cout << "nanoRotator int error!!!" << std::endl;
	}

	// rotate 90 degree for test
	rotate_nanoRotator(rotSerialNo, 90);
	
	// stop nanoRotator
	nanoRot_err = stop_nanoRotator(rotSerialNo);

	
	return 0;
}


