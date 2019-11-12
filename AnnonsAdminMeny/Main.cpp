#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <time.h>

#include "Customer.h"
#include "Campaign.h"
#include "Ad.h"
#include "AdServingEngine.h"

using namespace std;

int main() 
{
	AdServingEngine ase;
	while (true) 
	{
		int selection;
		cout << "1. Create customer.\n2. Create Campaign.\n3. Create Ad.\n4. Get next ad.\n5. Exit.\n";
		cin >> selection;
		
		string newCustomerName;
		string newCampaignName;
		int fromYear, fromMonth, fromDay;
		struct tm fromDate;
		int toYear, toMonth, toDay;
		struct tm toDate;
		float newCampaignCost;
		string adName, adText;
		int adType;
		vector<Customer> listOfCustomers;
		string campaignOwner;
		string customerName;
		string name;
		vector<Campaign> listOfCampaigns;
		string adOwner;
		string campaignName;
		int pos = 1;
		int adOwnerNumber;
		switch (selection) 
		{
		case 1:
			cout << "Enter customer name: ";
			cin >> newCustomerName;
			ase.AddCustomer(newCustomerName);
			break;
		case 2:
			cout << "Enter for which customer: ";
			cin >> campaignOwner;
			listOfCustomers = ase.GetListOfCustomer();
			for (auto cust : listOfCustomers)
			{
				customerName = cust.GetCustomerName();
				if (customerName == campaignOwner)
				{


					cout << "Enter the campaign name: ";
					cin >> newCampaignName;

					cout << "Enter the start year YYYY: ";
					cin >> fromYear;
					cout << "Enter the start month MM: ";
					cin >> fromMonth;
					cout << "Enter the start day DD: ";
					cin >> fromDay;
					fromDate.tm_year = fromYear - 1900;
					fromDate.tm_mon = fromMonth + 1;
					fromDate.tm_mday = fromDay;
					fromDate.tm_hour = 0;
					fromDate.tm_min = 0;
					time_t from = mktime(&fromDate);

					cout << "Enter the end year YYYY: ";
					cin >> toYear;
					cout << "Enter the end month MM: ";
					cin >> toMonth;
					cout << "Enter the end day DD: ";
					cin >> toDay;
					toDate.tm_year = toYear - 1900;
					toDate.tm_mon = toMonth + 1;
					toDate.tm_mday = toDay;
					toDate.tm_hour = 0;
					toDate.tm_min = 0;
					time_t to = mktime(&toDate);

					cout << "Enter the campaign cost: ";
					cin >> newCampaignCost;

					cust.AddCampaign(newCampaignName, from, to, newCampaignCost);
				}
			}
			break;
		case 3:
			cout << "Enter for which customer: ";
			cin >> campaignOwner;
			listOfCustomers = ase.GetListOfCustomer();
			for (auto cust : listOfCustomers)
			{
				customerName = cust.GetCustomerName();
				if (customerName == campaignOwner)
				{
					listOfCampaigns = cust.GetCampaignList();
					for (auto cam : listOfCampaigns)
					{
						name = cam.GetCampaignName();

						cout << pos << ". " << name << endl;
						pos++;
					}
					cout << "Enter for which campaign: ";
					cin >> adOwnerNumber;
					cout << "Enter ad name: ";
					cin >> adName;
					cout << "Enter ad text: ";
					cin >> adText;
					cout << "1.Scroll, 2.Blink, 3.PlainText: ";
					cin >> adType;

					listOfCampaigns[adOwnerNumber-1].AddAd(adName, adText, adType);
				}
			}
			continue;
		//case 4:
		//	ad = ase.GetNextAd();
		//	cout << ad;
		case 5:
			break;
		case 6:
			listOfCustomers = ase.GetListOfCustomer();
			for (auto cust : listOfCustomers)
			{
				name = cust.GetCustomerName();
				cout << name << endl;
			}
		default:
			cout << "Wrong format!";
			break;
		}
	}
}