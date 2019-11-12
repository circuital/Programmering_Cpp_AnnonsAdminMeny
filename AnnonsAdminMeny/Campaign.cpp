#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <time.h>

#include "Campaign.h"
#include "Ad.h"

using namespace std;

void Campaign::CreateCampaign()
{
	cout << "Enter the campaign name: " << endl;
	cin >> this->name;
	this->idIndex++;
	this->id = idIndex;

	int fromYear, fromMonth, fromDay;
	cout << "Enter the start year YYYY: " << endl;
	cin >> fromYear;
	cout << "Enter the start month MM: " << endl;
	cin >> fromMonth;
	cout << "Enter the start day DD: " << endl;
	cin >> fromDay;
	struct tm* fromDate;
	fromDate->tm_year = fromYear - 1900;
	fromDate->tm_mon = fromMonth + 1;
	fromDate->tm_mday = fromDay;
	this->fromDateTime = mktime(fromDate);

	int toYear, toMonth, toDay;
	cout << "Enter the end year YYYY: " << endl;
	cin >> toYear;
	cout << "Enter the end month MM: " << endl;
	cin >> toMonth;
	cout << "Enter the end day DD: " << endl;
	cin >> toDay;
	struct tm* toDate;
	toDate->tm_year = toYear - 1900;
	toDate->tm_mon = toMonth + 1;
	toDate->tm_mday = toDay;
	this->toDateTime = mktime(toDate);

	cout << "Enter the campaign cost: " << endl;
	cin >> this->campaignCost;
}

void Campaign::AddAd()
{
	Ad ad;
	ad.CreateAd();
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

