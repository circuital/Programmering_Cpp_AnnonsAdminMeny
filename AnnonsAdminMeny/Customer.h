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
	int idIndex = 0;
	vector<Campaign> activeCampaigns;

public:

	void CreateCustomer();
	void AddCampaign();
	vector<Campaign> GetActiveCampaignList();
	bool HasActiveCampaigns();

};

