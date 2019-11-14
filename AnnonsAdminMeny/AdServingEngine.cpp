#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <time.h>

#include "Customer.h"
#include "Campaign.h"
#include "Ad.h"
#include "AdServingEngine.h"

void AdServingEngine::AddCustomer(string name, int idIndex)
{
	Customer cust;
	cust.CreateCustomer(name, idIndex);
	this->allCustomers.push_back(cust);
}

vector<Customer> AdServingEngine::GetListOfCustomer()
{
	return this->allCustomers;
}

Customer* AdServingEngine::GetCustomer(int index)
{
	if (index <= allCustomers.size() && index >= 0)
		return &(this->allCustomers[index]);
	else
		return NULL;
}

Ad AdServingEngine::GetNextAd()
{
	this->allActiveCampaigns.clear();
	float totalParts = 0;
	srand(time(NULL));
	vector<Campaign> activeCampaigns;
	float campaignCost;
	int checkLastCampaign;
	for (int i = 0; i < allCustomers.size(); i++)
	{
		if (allCustomers[i].HasActiveCampaigns())
		{
			activeCampaigns = allCustomers[i].GetActiveCampaignList();
			for (int j = 0; j < activeCampaigns.size(); j++)
			{
				campaignCost = activeCampaigns[j].GetCampaignCost();
				allActiveCampaigns.push_back(activeCampaigns[j]);
				totalParts += campaignCost;
			}
		}
	}
	while (true)
	{
		int totalPartsInt = static_cast<int>(totalParts);
		int randomPart = rand() % totalPartsInt;
		int currentParts = 0;
		for (int k = 0; k < allActiveCampaigns.size(); k++)
		{
			campaignCost = allActiveCampaigns[k].GetCampaignCost();
			currentParts += campaignCost;
			checkLastCampaign = allActiveCampaigns[k].GetCampaignId();
			if (randomPart < currentParts && checkLastCampaign != lastCampaign)
			{
				lastCampaign = checkLastCampaign;
				vector<Ad> ads = allActiveCampaigns[k].GetAdList();
				int randomAd = rand() % ads.size();
				return (ads[randomAd]);
				break;
			}
		}
	}
}