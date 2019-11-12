#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <time.h>

#include "Customer.h"
#include "Campaign.h"


class AdServingEngine
{
	vector<Customer> allCustomers;
	vector<Campaign> allActiveCampaigns;
	float activeCampaignCostTotal;
	int activeCampaignCount;

public:
	void AddCustomer();
	Ad GetNextAd();
};