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
	int idIndexCustomer = 0, idIndexCampaign = 0, idIndexAd = 0;
	AdServingEngine ase;
	while (true)
	{
		int selection;
		cout << "1. Create customer.\n2. Create Campaign.\n3. Create Ad.\n4. Get next ad.\n5. Exit.\n";
		cin >> selection;

		string newCustomerName, newCampaignName, newAdName, newAdText;
		float newCampaignCost;
		int newAdType;

		string customerName, campaignName;
		string campaignOwner, adOwner;
		int fromYear, fromMonth, fromDay, toYear, toMonth, toDay;
		struct tm fromDate, toDate;

		vector<Customer> listOfCustomers;
		vector<Campaign> listOfCampaigns;

		int menuPosition = 1;
		int givenMenuPosition;

		switch (selection)
		{
		case 1:
			cout << "Enter customer name: ";
			cin >> newCustomerName;
			idIndexCustomer++;
			ase.AddCustomer(newCustomerName, idIndexCustomer);
			break;
		case 2:
			listOfCustomers = ase.GetListOfCustomer();
			for (auto cust : listOfCustomers)
			{
				customerName = cust.GetCustomerName();
				cout << menuPosition << ". " << customerName << endl;
				menuPosition++;
			}
			cout << "Enter for which customers: ";
			cin >> givenMenuPosition;
			givenMenuPosition = givenMenuPosition - 1;
			Customer* cust;
			cust = ase.GetCustomer(givenMenuPosition);
			if (cust)
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
				idIndexCampaign++;

				cust->AddCampaign(newCampaignName, from, to, newCampaignCost, idIndexCampaign);
			}
			else
			{
				cout << "Customer not found." << endl;
			}
			break;
		case 3:
			listOfCustomers = ase.GetListOfCustomer();
			for (auto cust : listOfCustomers)
			{
				customerName = cust.GetCustomerName();

				cout << menuPosition << ". " << customerName << endl;
				menuPosition++;
			}
			cout << "Enter for which customers: ";
			cin >> givenMenuPosition;
			givenMenuPosition = givenMenuPosition - 1;
			Customer* cust2;
			cust2 = ase.GetCustomer(givenMenuPosition);
			if (cust2)
			{
				menuPosition = 1;
				listOfCampaigns = cust2->GetCampaignList();
				for (auto cam : listOfCampaigns)
				{
					campaignName = cam.GetCampaignName();

					cout << menuPosition << ". " << campaignName << endl;
					menuPosition++;
				}
				cout << "Enter for which campaign: ";
				cin >> givenMenuPosition;
				givenMenuPosition = givenMenuPosition - 1;
				Campaign* cam;
				cam = cust2->GetCampaign(givenMenuPosition);
				if (cam)
				{
					cout << "Enter ad name: ";
					cin >> newAdName;
					cout << "Enter ad text: ";
					cin >> newAdText;
					cout << "1.Scroll, 2.Blink, 3.PlainText: ";
					cin >> newAdType;
					idIndexAd++;
					cam->AddAd(newAdName, newAdText, newAdType, idIndexAd);
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
			continue;
			//case 4:
				//  ad = ase.GetNextAd();
				//  cout << ad;
		case 5:
			return 0;
		case 6:
			listOfCustomers = ase.GetListOfCustomer();
			for (auto cust : listOfCustomers)
			{
				customerName = cust.GetCustomerName();
				cout << customerName << endl;
			}
		default:
			cout << "Wrong format!" << endl;
			break;
		}
	}
}