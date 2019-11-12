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
	int idIndex = 0;

public:
	void CreateAd(string name, string adText, int adType);
};