#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <time.h>

#include "Customer.h"
#include "Campaign.h"


using namespace std;

void Customer::CreateCustomer()
{
	cout << "Enter customer name: " << endl;
	cin >> this->name;
	this->idIndex++;
	this->id = this->idIndex;
}

void Customer::AddCampaign()
{
	Campaign cam;
	cam.CreateCampaign();
	this->campaigns.push_back(cam);
}

vector<Campaign> Customer::GetActiveCampaignList()
{
	this->activeCampaigns.clear();

	time_t now = time(NULL);
	time_t fromDateTime;
	time_t toDateTime;
	for (auto cam : this->campaigns)
	{
		fromDateTime = cam.GetFromDateTime();
		toDateTime = cam.GetToDateTime();
		if (fromDateTime >= now && toDateTime <= now)
			this->activeCampaigns.push_back(cam);
	}
	return this->activeCampaigns;
}

bool Customer::HasActiveCampaigns()
{
	this->GetActiveCampaignList();
	if (this->activeCampaigns.size() > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
