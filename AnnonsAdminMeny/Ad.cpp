#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <time.h>

#include "Ad.h"
#include "AdTypeEnum.h"

void Ad::CreateAd()
{
	cout << "Enter ad name: " << endl;
	cin >> this->name;
	this->idIndex++;
	this->id = this->idIndex;
}

void Ad::CreateAdText()
{
	int setText;
	cout << "Enter ad text: " << endl;
	cin >> this->adText;
	cout << "1.Scroll, 2.Blink, 3.PlainText:" << endl;
	cin >> setText;
	switch (setText)
	{
	case 1:
		this->adType = AdType::scroll;

	case 2:
		this->adType = AdType::blink;

	case 3:
		this->adType = AdType::plainText;
	}
}

