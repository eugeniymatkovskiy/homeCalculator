#include "Parser.h"

Parser::Parser(vector<MATERIAL *> *materials)
{
	this->materials = materials;
}

int Parser::init()
{
	if (!checkIfFileExist() || checkIfNeedDownloadMaterialPrice())
		getFileWithMaterialPrice();

	readMaterialPriceFile();

	return 1;
}

void Parser::getFileWithMaterialPrice()
{
	const TCHAR url[] = _T(URLFORDOWNLOAD);
	const TCHAR filePath[] = _T(MATERIALPRICES);
	cout << "downloading ...";
	HRESULT hr = URLDownloadToFile(NULL, url, filePath, 0, NULL);
	cout << "Done!" << endl;
}

void Parser::readMaterialPriceFile()
{
	fstream materialPriceFile;
	materialPriceFile.open(MATERIALPRICES, ios::in | ios::out | ios::binary);

	string line;


	while (getline(materialPriceFile, line))
	{
		setupMaterialPriceToVector(explodeMaterialLine(line));
	}

	materialPriceFile.close();
}

void Parser::setupMaterialPriceToVector(vector<string> materialData)
{
	int newMaterialId = materials->size() + 1;

	MATERIAL *newMaterial = new MATERIAL();

	newMaterial->groupId = stoi(materialData[0], nullptr, 10);
	newMaterial->id = stoi(materialData[1], nullptr, 10);;
	newMaterial->type = materialData[3];
	newMaterial->price = stod(materialData[4]);

	newMaterial->width = 0;
	newMaterial->height = 0;
	newMaterial->length = 0;
	newMaterial->count = 0;

	newMaterial->unit = 0;

	materials->push_back(newMaterial);
}

vector<string> Parser::explodeMaterialLine(string materialString){
	vector <string> materialData;
	char delimiter = ';';
	string tmpString;

	for (int i = 0; i < materialString.length(); i++){

		if (materialString[i] == delimiter){
			materialData.push_back(tmpString);
			tmpString.clear();
			continue;
		}

		tmpString.push_back(materialString[i]);
	}

	if (tmpString.size()){
		materialData.push_back(tmpString);
		tmpString.clear();
	}

	trimMaterialValues(&materialData);

	return materialData;
}

void Parser::trimMaterialValues(vector<string> *materialData){
	int spaceCharacter;
	int lastSpaceCharacter;
	string tmpStringWithoutSpaces;
	string tmpString;

	for (int i = 0; i < materialData->size(); i++){
		tmpString = (*materialData)[i];
		spaceCharacter = 0;
		lastSpaceCharacter = tmpString.size() - 1;

		while (tmpString[spaceCharacter] == ' ')
			spaceCharacter++;

		while (tmpString[lastSpaceCharacter] == ' ')
			lastSpaceCharacter--;

		if (spaceCharacter || (lastSpaceCharacter != (tmpString.size() - 1))){

			for (int j = spaceCharacter; j <= lastSpaceCharacter; j++){
				tmpStringWithoutSpaces.push_back(tmpString[j]);
			}

			tmpString = tmpStringWithoutSpaces;
		}

		(*materialData)[i] = tmpString;
		tmpStringWithoutSpaces.clear();
	}
}

bool Parser::checkIfNeedDownloadMaterialPrice(){

	struct _stat buf;
	_stat(MATERIALPRICES, &buf);

	time_t currentUnixTime;
	time(&currentUnixTime);

	CTimeSpan ts(currentUnixTime - buf.st_mtime);

	return ts.GetDays() >= COUNTRELEVANTDAYFORMATERIALPRICES;
}

bool Parser::checkIfFileExist(){
	return PathFileExists(MATERIALPRICES);
}

Parser::~Parser()
{
}
