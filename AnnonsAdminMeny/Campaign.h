#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <time.h>

#include "Ad.h"

using namespace std;

class Campaign
{
	string name;
	int id;
	time_t fromDateTime;
	time_t toDateTime;
	float campaignCost;
	vector<Ad> ads;

public:
	void CreateCampaign(string name, time_t fromDate, time_t toDate, float campaignCost, int idIndex);
	void UpdateCampaign(string name, time_t fromDate, time_t toDate, float campaignCost);
	void AddAd(string name, string adText, AdType adType, int idIndex);

	float GetCampaignCost();
	time_t GetFromDateTime();
	time_t GetToDateTime();
	
	string GetCampaignName();
	vector<Ad> GetAdList();
	int GetCampaignId();
	Ad* GetAd(int index);
};