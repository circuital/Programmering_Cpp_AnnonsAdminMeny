#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <time.h>

#include "AdTypeEnum.h"

using namespace std;

class Ad
{
	string name;
	int id;
	string adText;
	AdType adType;

public:
	void CreateAd(string name, string adText, AdType adType, int idIndex);
	void UpdateAd(string name, string adText, AdType adType);
	string GetAdName();
	string GetAdText();
	AdType GetAdType();
};