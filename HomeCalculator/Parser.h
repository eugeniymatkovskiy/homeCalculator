#pragma once
#include "stdafx.h"

class Parser
{
private:
	vector <MATERIAL *> *materials;

	void getFileWithMaterialPrice();
	void readMaterialPriceFile();
	void setupMaterialPriceToVector(vector<string> materialData);
	vector<string> explodeMaterialLine(string materialString);
	void trimMaterialValues(vector<string> *materialData);
	bool checkIfFileWithMaterialPriceExist();
	string getLastDateWhenDonwloadMaterialPriceFile();
	bool checkIfNeedDownloadMaterialPrice();
	bool checkIfFileExist();
public:
	Parser(vector<MATERIAL *> *materials);
	int init();
	~Parser();
};

