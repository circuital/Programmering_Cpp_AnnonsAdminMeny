#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <time.h>

#include "Customer.h"
#include "Campaign.h"


using namespace std;

void Customer::CreateCustomer(string name, int idIndex)
{
	this->name = name;
	this->id = idIndex;
}

void Customer::UpdateCustomer(string name)
{
	this->name = name;
}

void Customer::AddCampaign(string name, time_t fromDate, time_t toDate, float campaignCost, int idIndex)
{
	Campaign cam;
	cam.CreateCampaign(name, fromDate, toDate, campaignCost, idIndex);
	this->campaigns.push_back(cam);
}

vector<Campaign> Customer::GetActiveCampaignList()
{
	this->activeCampaigns.clear();

	time_t now = time(NULL);
	time_t fromDateTime;
	time_t toDateTime;
	for (int i = 0; i < campaigns.size(); i++)
	{
		fromDateTime = campaigns[i].GetFromDateTime();
		toDateTime = campaigns[i].GetToDateTime();
		if (fromDateTime <= now && toDateTime >= now)
			this->activeCampaigns.push_back(campaigns[i]);
	}
	return this->activeCampaigns;
}

bool Customer::HasActiveCampaigns()
{
	vector<Campaign> v;
	v = this->GetActiveCampaignList();
	if (v.size() > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

string Customer::GetCustomerName()
{
	return this->name;
}

vector<Campaign> Customer::GetCampaignList()
{
	return this->campaigns;
}

Campaign* Customer::GetCampaign(int index)
{
	if (index <= campaigns.size() && index >= 0)
		return &(this->campaigns[index]);
	else
		return NULL;
}

