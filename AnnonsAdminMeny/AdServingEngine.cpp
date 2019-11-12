#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <time.h>

#include "Customer.h"
#include "Campaign.h"
#include "Ad.h"
#include "AdServingEngine.h"

void AdServingEngine::AddCustomer(string name)
{
	Customer cust;
	cust.CreateCustomer(name);
	this->allCustomers.push_back(cust);
}

Ad AdServingEngine::GetNextAd()
{
	this->allActiveCampaigns.clear();
	float totalParts = 0;
	srand(time(NULL));
	vector<Campaign> activeCampaigns;
	float campaignCost;
	for (auto cust : this->allCustomers)
	{
		if (cust.HasActiveCampaigns())
		{
			activeCampaigns = cust.GetActiveCampaignList();
			for (auto cam : activeCampaigns)
			{
				campaignCost = cam.GetCampaignCost();
				allActiveCampaigns.push_back(cam);
				totalParts += campaignCost;
			}
		}
	}
	float randomPart = rand() % (int)totalParts;
	float currentParts = 0;
	Campaign chosenCampaign;
	for (auto cam : this->allActiveCampaigns)
	{
		campaignCost = cam.GetCampaignCost();
		currentParts += campaignCost;
		if (randomPart < currentParts)
		{
			chosenCampaign = cam;
			break;
		}
	}
	vector<Ad> ads = chosenCampaign.GetAdList();
	int randomAd = rand() % ads.size();
	Ad chosenAd;
	chosenAd = ads[randomAd];
	return chosenAd;
}

vector<Customer> AdServingEngine::GetListOfCustomer()
{
	return this->allCustomers;
}