/*
 * FileReader.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: keith
 */
#include <iostream>
#include <fstream>
#include "../327_proj3_test/includes/FileIO.h"
#include "../327_proj3_test/includes/constants.h"
#include <sstream>

using namespace std;

int KP_FileIO::getFileContents(const std::string &filename, std::string &contents)
{
	contents.clear();

		ifstream myfile;
		myfile.open(filename);
		if(!myfile.is_open()) {
			return COULD_NOT_OPEN_FILE_TO_READ;
		}

		else {
			std::string line;
			std::string token;
			stringstream ss;

			while (getline(myfile, line)) {

				ss.str(line);

				getline(ss, contents, '\n');

				token += contents;


				contents += line;
				ss.clear();
			}

			contents = token;

		}
		return SUCCESS;
}

int KP_FileIO::writeVectortoFile(const std::string filename,std::vector<std::string> &myEntryVector)
{
	ofstream myFile;
		myFile.open(filename);

		if (!myFile.is_open()) {
			return COULD_NOT_OPEN_FILE_TO_WRITE;
		}

		else{
			string myData;

			for (int var = 0; var < myEntryVector.size(); ++var) {
				myData = myEntryVector[var];
				myFile<<myData<<std::endl;
			}
			if (myFile.is_open()) {
				myFile.close();
			}
		}


		return SUCCESS;
}


