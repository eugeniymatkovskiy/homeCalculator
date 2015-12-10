#include "Roof.h"
#include "HomeCalculator.h"

Roof::Roof(double houseLength, double houseWidth, int roofType, int typeBuild) {
	this->houseLength = houseLength;
	this->houseWidth = houseWidth;
	this->roofType = roofType;
	this->typeBuild = typeBuild;
	this->frontonHeight = 4;//âèñîòà ôðîíòîíó
	this->reftersLength = 4.5;// äîâæèíà ñòðîï³ëè
	this->reftersWidthBetween = 1.0; //â³äñòàíü ì³æ ñòðîï³ëàìè
	this->reftersWidth = 0.50;// øèðèíà ñòðîï³ëè
	this->slateWidth = 1.13;// øèðèíà øèôåðà
	this->slateLength = 1.75;// äîâæèíà øèôåðà
	this->slateLayingOn = 0.20;//øèðèíà íàêëàäàííÿ øèôåðà

	//îòðèìàííÿ ö³í íà ìàòåð³àëè
	//this->reftersPrice = reftersPrice; //çà ìåòð êâàäðàòíèé ñòðîï³ë
	//this->slatePrice = slatePrice;
	//this->tilingPrice = tilingPrice;
	//this->ruberoidPrice = ruberoidPrice;
}

Roof::~Roof() {
}

void Roof::PifagorTheorem() {
	this->roofLength = sqrt((this->houseWidth / 2) * (this->houseWidth / 2) + this->frontonHeight * this->frontonHeight); //äîâæèíà êðèø³
}

void Roof::roofSize() {
	this->PifagorTheorem();// âèçíà÷åííÿ äîâæèíè êðèø³

	//âèçíà÷åííÿ ê³ëüêîñò³ ñòðîï³ë ç äâîõ ñòîð³í áóäèíêó
	double reftersAmountHeight = ceil(this->roofLength / this->reftersLength); //ê³ëüê³ñòü ñòðîï³ë ïî âèñîò³
	double reftersAmountInMeter = (ceil(this->houseLength / (this->reftersWidth + this->reftersWidthBetween) + 1) * reftersAmountHeight) * 2; //çàãàëüíà ê³ëüê³ñòü ñòðîï³ë ç äâîõ ñòîð³í áóäèíêó
	this->reftersAmount = (this->reftersLength * this->reftersWidth * 0.50) * reftersAmountInMeter;

	//cout << "Enter the type of root: 0 for slate, 1 for tiling" << endl;
	//cin >> roofType;

	//âèçíà÷åííÿ ê³ëüêîñò³ øèôåðó
	if (this->roofType == ROOF_SLATE_ID) {
		double slateAmountHeight = 1; //ê³ëüê³ñòü íåîáõ³äíîãî øèôåðó ïî âèñîò³
		double tmp = this->slateLength - this->slateLayingOn;
		while (true) {
			if (this->slateLength >= this->roofLength) {
				break;
			}
			else {
				slateAmountHeight++;
				this->slateLength += tmp;
			}
		}
		this->slateAmount = (int)(ceil(this->houseLength / this->slateWidth) * slateAmountHeight) * 2; //çàãàëüíà ê³ëüê³ñòü øèôåðó = âèçíà÷åíà ê³ëüê³ñòü øèôåðó ïî äîâæèí³ áóäèíêó ïîìíîæåíà íà ê³ëüê³ñòü ïî âèñîò³ 
		//cout << "General slate amount: " << this->slateAmount << endl;
		//cout << "General refters amount: " << this->reftersAmount << endl;
	}
	//âèçíà÷åííÿ ê³ëüêîñò³ ìåòàëî÷åðåïèö³
	else if (this->roofType == ROOF_TILING_ID) {
		double squareHomeRoof;
		squareHomeRoof = this->houseLength * this->roofLength * 2; //ïëîùà êðèø³ ç îáîõ áîê³â
		this->tilingAmount = ceil(squareHomeRoof);
 
		//cout << "General tiling amount: " << this->tilingAmount << endl;
		//cout << "General refters amount: " << this->reftersAmount << endl;
	}
	else if (this->typeBuild == 2 || this->typeBuild == 3) {
		double squareGarageRoof;
		squareGarageRoof = this->houseLength * this->houseWidth;
		this->tilingAmount = ceil(squareGarageRoof);
		//cout << "General amount square meters of ruberoid: " << this->ruberoidAmount << endl;
	}	
}

int Roof::getReftersAmount(){
	return this->reftersAmount;
}

int Roof::getSlateAmount(){
	return this->slateAmount;
}

int Roof::getTilingAmount(){
	return this->tilingAmount;
}

int Roof::getRuberoidAmount(){
	return this->ruberoidAmount;
}

int Roof::getRoofType(){
	return this->roofType;
}

//ñ÷èòàòü è äîáàâèòü ìàòåðèàëû â íîâûé ñïèñîê
void Roof::addMaterials(vector<MATERIAL*>* mtrl, vector<MATERIAL*>* calcMtrl){

	MATERIAL* tmpMaterial;


	//************ äîáàâëÿåì ê-âî ñòðîïèë **************

	//ïðîâåðÿåì íàëè÷èå ñòðîïèë äëÿ èçãîòîâëåíèÿ êðûøè
	if (this->getReftersAmount())
	{
		for (int i = 0; i < mtrl->size(); i++)
		{
			if ((*mtrl)[i]->id == ROOF_REFTERS_ID)
			{
				//êîïèðóåì ìàòåðèàë
				tmpMaterial = new MATERIAL();
				tmpMaterial = (*mtrl)[i];
				//äîáàâëÿåì ê-âî ìàòåðèàëà
				tmpMaterial->count = this->getReftersAmount();
				//äîáàâëÿåì ìàòåðèàë â íîâûé ñïèñîê
				calcMtrl->push_back(tmpMaterial);
				break;
			}
		}
	}

	//************ äîáàâëÿåì ê-âî øèôåðà **************

	//ïðîâåðÿåì íàëè÷èå øèôåðà äëÿ èçãîòîâëåíèÿ êðûøè
	if (this->getSlateAmount())
	{
		for (int i = 0; i < mtrl->size(); i++)
		{
			if ((*mtrl)[i]->id == ROOF_SLATE_ID)
			{
				//êîïèðóåì ìàòåðèàë
				tmpMaterial = new MATERIAL();
				tmpMaterial = (*mtrl)[i];
				//äîáàâëÿåì ê-âî ìàòåðèàëà
				tmpMaterial->count = this->getSlateAmount();
				//äîáàâëÿåì ìàòåðèàë â íîâûé ñïèñîê
				calcMtrl->push_back(tmpMaterial);
				break;
			}
		}
	}

	//************ äîáàâëÿåì ê-âî ìåòàëî÷åðåïèöè **************

	//ïðîâåðÿåì íàëè÷èå ìåòàëî÷åðåïèöè äëÿ èçãîòîâëåíèÿ êðûøè
	if (this->getTilingAmount())
	{
		for (int i = 0; i < mtrl->size(); i++)
		{
			if ((*mtrl)[i]->id == ROOF_TILING_ID)
			{
				//êîïèðóåì ìàòåðèàë
				tmpMaterial = new MATERIAL();
				tmpMaterial = (*mtrl)[i];
				//äîáàâëÿåì ê-âî ìàòåðèàëà
				tmpMaterial->count = this->getTilingAmount();
				//äîáàâëÿåì ìàòåðèàë â íîâûé ñïèñîê
				calcMtrl->push_back(tmpMaterial);
				break;
			}
		}
	}

	//************ äîáàâëÿåì ê-âî ðóáåðîèäà **************

	//ïðîâåðÿåì íàëè÷èå ðóáåðîèäà äëÿ èçãîòîâëåíèÿ êðûøè
	if (this->getRuberoidAmount())
	{
		for (int i = 0; i < mtrl->size(); i++)
		{
			if ((*mtrl)[i]->id == ROOF_RUBEROID_ID)
			{
				//êîïèðóåì ìàòåðèàë
				tmpMaterial = new MATERIAL();
				tmpMaterial = (*mtrl)[i];
				//äîáàâëÿåì ê-âî ìàòåðèàëà
				tmpMaterial->count = this->getRuberoidAmount();
				//äîáàâëÿåì ìàòåðèàë â íîâûé ñïèñîê
				calcMtrl->push_back(tmpMaterial);
				break;
			}
		}
	}
}
