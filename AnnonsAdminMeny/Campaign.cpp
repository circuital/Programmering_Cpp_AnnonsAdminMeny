#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <time.h>

#include "Campaign.h"
#include "Ad.h"

using namespace std;

void Campaign::CreateCampaign(string name, time_t fromDate, time_t toDate, float campaignCost, int idIndex)
{
	this->name = name;
	this->id = idIndex;

	this->fromDateTime = fromDate;
	this->toDateTime = toDate;

	this->campaignCost = campaignCost;
}

void Campaign::UpdateCampaign(string name, time_t fromDate, time_t toDate, float campaignCost)
{
	this->name = name;

	this->fromDateTime = fromDate;
	this->toDateTime = toDate;

	this->campaignCost = campaignCost;
}

void Campaign::AddAd(string name, string adText, AdType adType, int idIndex)
{
	Ad ad;
	ad.CreateAd(name, adText, adType, idIndex);
	this->ads.push_back(ad);
}

float Campaign::GetCampaignCost()
{
	return this->campaignCost;
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

vector<Ad> Campaign::GetAdList()
{
	return this->ads;
}

int Campaign::GetCampaignId()
{
	return this->id;
}

Ad* Campaign::GetAd(int index)
{
	if (index <= ads.size() && index >= 0)
		return &(this->ads[index]);
	else
		return NULL;
}