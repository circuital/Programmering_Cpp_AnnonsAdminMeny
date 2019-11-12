#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <time.h>

#include "Campaign.h"
#include "Ad.h"

using namespace std;

void Campaign::CreateCampaign(string name, time_t fromDate, time_t toDate, float campaignCost)
{
	this->name = name;
	this->idIndex++;
	this->id = idIndex;
	
	this->fromDateTime = fromDate;
	this->toDateTime = toDate;

	this->campaignCost = campaignCost;
}

void Campaign::AddAd(string name, string adText, int adType)
{
	Ad ad;
	ad.CreateAd(name, adText, adType);
	this->ads.push_back(ad);
}

float Campaign::GetCampaignCost()
{
	return this->campaignCost;
}

vector<Ad> Campaign::GetAdList()
{
	return this->ads;
}

time_t Campaign::GetFromDateTime()
{
	return this->fromDateTime;
}

time_t Campaign::GetToDateTime()
{
	return this->toDateTime;
}

string Campaign::GetCampaignName()
{
	return this->name;
}

