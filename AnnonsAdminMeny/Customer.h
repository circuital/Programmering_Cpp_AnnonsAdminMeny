#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <time.h>

#include "Campaign.h"

class Customer
{
	string name;
	int id;
	vector<Campaign> campaigns;
	vector<Campaign> activeCampaigns;

public:

	void CreateCustomer(string name, int idIndex);
	void UpdateCustomer(string name);
	void AddCampaign(string name, time_t fromDate, time_t toDate, float campaignCost, int idIndex);

	vector<Campaign> GetActiveCampaignList();
	bool HasActiveCampaigns();
	
	string GetCustomerName();
	vector<Campaign> GetCampaignList();
	Campaign* GetCampaign(int index);
};