#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <sstream>

#include "Customer.h"
#include "Campaign.h"
#include "Ad.h"
#include "AdServingEngine.h"

using namespace std;

void GetYYYYMMDD(string YYYYMMDD, int* YYYY, int* MM, int* DD)
{

	string dateString = YYYYMMDD;
	replace(dateString.begin(), dateString.end(), '/', ' ');

	vector<int> dateInts;
	stringstream dateStream(dateString);
	int temp;
	while (dateStream >> temp)
	{
		dateInts.push_back(temp);
	}
		

	*YYYY = dateInts[0];
	*MM = dateInts[1];
	*DD = dateInts[2];
}

time_t GetDateFromString(string YYYYMMDD) 
{
	string dateString = YYYYMMDD;
	struct tm toDate;
	replace(dateString.begin(), dateString.end(), '/', ' ');

	vector<int> dateInts;
	stringstream dateStream(dateString);
	int temp;
	while (dateStream >> temp)
	{
		dateInts.push_back(temp);
	}
	toDate.tm_year = dateInts[0] - 1900;
	toDate.tm_mon = dateInts[1] + 1;
	toDate.tm_mday = dateInts[2];
	toDate.tm_hour = 0;
	toDate.tm_min = 0;
	toDate.tm_sec = 0;
	time_t to = mktime(&toDate);
	return to;
}

void CreateNewCustomer(AdServingEngine* ase, int idIndex)
{
	string newCustomerName;
	cout << "Enter customer name: ";
	cin >> newCustomerName;
	ase->AddCustomer(newCustomerName, idIndex);

	ofstream outfile;
	outfile.open("C:\\Users\\elvir\\Desktop\\IoT\\C++\\AnnonsAdminMeny\\customers.txt", ofstream::out | ofstream::app);
	outfile << idIndex << ". " << newCustomerName << ". " << endl;
	outfile.close();
}

void CreateNewCampaign(Customer* customer, int idIndex)
{
	string newCampaignName;
	cout << "Enter the campaign name: ";
	cin >> newCampaignName;

	string fromDateString;
	int fromYear, fromMonth, fromDay;
	cout << "Give start date of campaign YYYY/MM/DD: ";
	cin >> fromDateString;
	GetYYYYMMDD(fromDateString, &fromYear, &fromMonth, &fromDay);

	struct tm fromDate;
	fromDate.tm_year = fromYear - 1900;
	fromDate.tm_mon = fromMonth + 1;
	fromDate.tm_mday = fromDay;
	fromDate.tm_hour = 0;
	fromDate.tm_min = 0;
	fromDate.tm_sec = 0;
	time_t from = mktime(&fromDate);

	string toDateString;
	int toYear, toMonth, toDay;
	cout << "Give end date of campaign YYYY/MM/DD: ";
	cin >> toDateString;
	GetYYYYMMDD(toDateString, &toYear, &toMonth, &toDay);

	struct tm toDate;
	toDate.tm_year = toYear - 1900;
	toDate.tm_mon = toMonth + 1;
	toDate.tm_mday = toDay;
	toDate.tm_hour = 0;
	toDate.tm_min = 0;
	toDate.tm_sec = 0;
	time_t to = mktime(&toDate);

	float newCampaignCost;
	cout << "Enter the campaign cost: ";
	cin >> newCampaignCost;
	customer->AddCampaign(newCampaignName, from, to, newCampaignCost, idIndex);

	string customerFileName = customer->GetCustomerName();
	ofstream outfile;
	outfile.open("C:\\Users\\elvir\\Desktop\\IoT\\C++\\AnnonsAdminMeny\\" + customerFileName + "campaigns.txt", ofstream::out | ofstream::app);
	outfile << idIndex << ". " << newCampaignName << ". " << newCampaignCost << ". " << fromDateString << ". " << toDateString << ". " << endl;
	outfile.close();
}

void CreateNewAd(Campaign* campaign, int idIndex)
{
	string newAdName;
	cout << "Enter ad name: ";
	cin >> newAdName;
	string newAdText;
	cout << "Enter ad text: ";
	cin >> newAdText;
	cin.ignore();
	int newAdTypeInt;
	cout << "1. Scroll.\n2. Blink.\n3. PlainText.\nEnter ad type: ";
	cin >> newAdTypeInt;
	AdType newAdType;
	switch (newAdTypeInt)
	{
	case 1:
	{
		newAdType = AdType::scroll;
	}
	case 2:
	{
		newAdType = AdType::blink;
	}
	case 3:
	{
		newAdType = AdType::plainText;
	}
	}
	campaign->AddAd(newAdName, newAdText, newAdType, idIndex);

	string campaignFileName = campaign->GetCampaignName();
	ofstream outfile;
	outfile.open("C:\\Users\\elvir\\Desktop\\IoT\\C++\\AnnonsAdminMeny\\" + campaignFileName + "ads.txt", ofstream::out | ofstream::app);
	outfile << idIndex << ". " << newAdName << ". " << newAdText << ". " << newAdType << ". " << endl;
	outfile.close();
}

Customer* GetChosenCustomer(AdServingEngine* ase)
{
	vector<Customer> listOfCustomers;
	listOfCustomers = ase->GetListOfCustomer();
	string customerName;
	int menuPosition = 1;
	for (int i = 0; i < listOfCustomers.size(); i++)
	{
		customerName = listOfCustomers[i].GetCustomerName();
		cout << menuPosition << ". " << customerName << endl;
		menuPosition++;
	}
	int givenMenuPosition;
	cout << "Enter for which customers: ";
	cin >> givenMenuPosition;
	int givenMenuIndex = givenMenuPosition - 1;
	Customer* chosenCustomer;
	chosenCustomer = ase->GetCustomer(givenMenuIndex);
	return chosenCustomer;
}

Campaign* GetChosenCampaign(Customer* customer)
{
	vector<Campaign> listOfCampaigns;
	listOfCampaigns = customer->GetCampaignList();
	string campaignName;
	int menuPosition = 1;
	for (int i = 0; i < listOfCampaigns.size(); i++)
	{
		campaignName = listOfCampaigns[i].GetCampaignName();
		cout << menuPosition << ". " << campaignName << endl;
		menuPosition++;
	}
	int givenMenuPosition;
	cout << "Enter for which campaign: ";
	cin >> givenMenuPosition;
	int givenMenuIndex = givenMenuPosition - 1;
	Campaign* chosenCampaign;
	chosenCampaign = customer->GetCampaign(givenMenuIndex);
	return chosenCampaign;
}

Ad* GetChosenAd(Campaign* campaign)
{
	vector<Ad> listOfAds;
	listOfAds = campaign->GetAdList();
	string adName;
	int menuPosition = 1;
	for (int i = 0; i < listOfAds.size(); i++)
	{
		adName = listOfAds[i].GetAdName();
		cout << menuPosition << ". " << adName << endl;
		menuPosition++;
	}
	int givenMenuPosition;
	cout << "Enter for which ad: ";
	cin >> givenMenuPosition;
	int givenMenuIndex = givenMenuPosition - 1;
	Ad* chosenAd;
	chosenAd = campaign->GetAd(givenMenuIndex);
	return chosenAd;
}

void UpdateCustomerMenu(Customer* customer)
{
	string updatedCustomerName;
	cout << "New name: ";
	cin >> updatedCustomerName;
	customer->UpdateCustomer(updatedCustomerName);
}

void UpdateCampaignMenu(Campaign* campaign)
{
	string updatedCampaignName;
	cout << "Enter the campaign name: ";
	cin >> updatedCampaignName;

	string updatedFromDateString;
	cout << "Give start date of campaign YYYY/MM/DD: ";
	cin >> updatedFromDateString;
	struct tm updatedFromDate;
	int updatedFromYear, updatedFromMonth, updatedFromDay;
	GetYYYYMMDD(updatedFromDateString, &updatedFromYear, &updatedFromMonth, &updatedFromDay);
	updatedFromDate.tm_year = updatedFromYear - 1900;
	updatedFromDate.tm_mon = updatedFromMonth + 1;
	updatedFromDate.tm_mday = updatedFromDay;
	updatedFromDate.tm_hour = 0;
	updatedFromDate.tm_min = 0;
	updatedFromDate.tm_sec = 0;
	time_t from = mktime(&updatedFromDate);

	string updatedToDateString;
	cout << "Give end date of campaign YYYY/MM/DD: ";
	cin >> updatedToDateString;
	struct tm updatedToDate;
	int updatedToYear, updatedToMonth, updatedToDay;
	GetYYYYMMDD(updatedToDateString, &updatedToYear, &updatedToMonth, &updatedToDay);
	updatedToDate.tm_year = updatedToYear - 1900;
	updatedToDate.tm_mon = updatedToMonth + 1;
	updatedToDate.tm_mday = updatedToDay;
	updatedToDate.tm_hour = 0;
	updatedToDate.tm_min = 0;
	updatedToDate.tm_sec = 0;
	time_t to = mktime(&updatedToDate);

	float updatedCampaignCost;
	cout << "Enter the campaign cost: ";
	cin >> updatedCampaignCost;

	campaign->UpdateCampaign(updatedCampaignName, from, to, updatedCampaignCost);
}

void UpdateAdMenu(Ad* ad)
{
	string updatedAdName;
	cout << "Enter ad name: ";
	cin >> updatedAdName;
	string updatedAdText;
	cout << "Enter ad text: ";
	cin >> updatedAdText;
	cin.ignore();
	int updatedAdTypeInt;
	cout << "1. Scroll.\n2. Blink.\n3. PlainText.\nEnter ad type: ";
	cin >> updatedAdTypeInt;
	AdType updatedAdType;
	switch (updatedAdTypeInt)
	{
	case 1:
	{
		updatedAdType = AdType::scroll;
	}
	case 2:
	{
		updatedAdType = AdType::blink;
	}
	case 3:
	{
		updatedAdType = AdType::plainText;
	}
	ad->UpdateAd(updatedAdName, updatedAdText, updatedAdType);
	}
	return;
}

void PrintNextAd(AdServingEngine ase)
{
	Ad ad = ase.GetNextAd();
	string adText = ad.GetAdText();
	AdType adType = ad.GetAdType();
	if (adType == AdType::scroll)
		cout << "Scrolling: " << adText << endl;
	else if (adType == AdType::blink)
		cout << "Blinking: " << adText << endl;
	else if (adType == AdType::plainText)
		cout << adText << endl;
}

int main()
{
	{
		int idIndexCustomer = 0, idIndexCampaign = 0, idIndexAd = 0;
		AdServingEngine ase;

		ifstream infileCustomer;
		infileCustomer.open("C:\\Users\\elvir\\Desktop\\IoT\\C++\\AnnonsAdminMeny\\customers.txt", ifstream::in);
		string cust;
		vector<string> custs;
		while (!infileCustomer.eof())
		{
			getline(infileCustomer, cust);
			custs.push_back(cust);
		}
		infileCustomer.close();
		for (int i = 0; i < custs.size(); i++)
		{
			string delimiter = ". ";

			size_t pos = 0;
			string fileIdIndexString;
			string fileCustName;
			int fileIdIndexInt;
			int count = 0;
			while ((pos = custs[i].find(delimiter)) != std::string::npos)
			{
				if (count == 0) {
					fileIdIndexString = custs[i].substr(0, pos);
					custs[i].erase(0, pos + delimiter.length());
					fileIdIndexInt = stoi(fileIdIndexString);
					count++;
				}
				else if (count == 1) {
					fileCustName = custs[i].substr(0, pos);
					custs[i].erase(0, pos + delimiter.length());
				}
				if (fileIdIndexInt > 0 && fileCustName.length() > 0)
				{
					ase.AddCustomer(fileCustName, fileIdIndexInt);
				}
				idIndexCustomer = fileIdIndexInt;
			}
		}

		while (true)
		{
			int selection;
			cout << "1. Create customer.\n2. Create campaign.\n3. Create ad.\n4. Update customer. \n5. Update campaign.\n6. Update ad. \n7. Print next ad.\n8. Exit.\n";
			cin >> selection;

			switch (selection)
			{
			case 1:
			{
				idIndexCustomer++;
				CreateNewCustomer(&ase, idIndexCustomer);
				break;
			}
			case 2:
			{
				Customer* chosenCustomer1;
				chosenCustomer1 = GetChosenCustomer(&ase);
				if (chosenCustomer1)
				{
					idIndexCampaign++;
					CreateNewCampaign(chosenCustomer1, idIndexCampaign);
				}
				else
				{
					cout << "Customer not found." << endl;
				}
				break;
			}
			case 3:
			{
				Customer* chosenCustomer2 = GetChosenCustomer(&ase);
				if (chosenCustomer2)
				{
					Campaign* chosenCampaign = GetChosenCampaign(chosenCustomer2);
					if (chosenCampaign)
					{
						idIndexAd++;
						CreateNewAd(chosenCampaign, idIndexAd);
					}
					else
					{
						cout << "Campaign not found." << endl;
					}
				}
				else
				{
					cout << "Customer not found." << endl;
				}
				break;
			}
			case 4:
			{
				Customer* chosenCustomer3 = GetChosenCustomer(&ase);
				if (chosenCustomer3)
				{
					UpdateCustomerMenu(chosenCustomer3);
				}
				else
				{
					cout << "Customer not found." << endl;
				}
				break;
			}
			case 5:
			{
				Customer* chosenCustomer4 = GetChosenCustomer(&ase);
				if (chosenCustomer4)
				{
					Campaign* chosenCampaign3 = GetChosenCampaign(chosenCustomer4);
					if (chosenCampaign3)
					{
						UpdateCampaignMenu(chosenCampaign3);
					}
					else
					{
						cout << "Campaign not found." << endl;
					}
				}
				else
				{
					cout << "Customer not found." << endl;
				}
				break;
			}
			case 6:
			{
				Customer* chosenCustomer5 = GetChosenCustomer(&ase);
				if (chosenCustomer5)
				{
					Campaign* chosenCampaign4 = GetChosenCampaign(chosenCustomer5);
					if (chosenCampaign4)
					{
						Ad* chosenAd = GetChosenAd(chosenCampaign4);
						if (chosenAd)
						{
							UpdateAdMenu(chosenAd);
						}
					}
					else
					{
						cout << "Campaign not found." << endl;
					}
				}
				else
				{
					cout << "Customer not found." << endl;
				}
				break;
			}
			case 7:
			{
				PrintNextAd(ase);
			}
			case 8:
				return 0;
			default:
				cout << "Wrong format!" << endl;
				break;
			}
		}
	}
}