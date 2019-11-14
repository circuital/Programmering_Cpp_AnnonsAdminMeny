#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <time.h>

#include "Ad.h"
#include "AdTypeEnum.h"

void Ad::CreateAd(string name, string adText, AdType adType, int idIndex)
{
	this->name = name;
	this->id = idIndex;
	this->adType = adType;
	this->adText = adText;
}

void Ad::UpdateAd(string name, string adText, AdType adType)
{
	this->name = name;
	this->adType = adType;
	this->adText = adText;
}

string Ad::GetAdName()
{
	return this->name;
}

string Ad::GetAdText()
{
	return this->adText;
}

AdType Ad::GetAdType()
{
	return this->adType;
}