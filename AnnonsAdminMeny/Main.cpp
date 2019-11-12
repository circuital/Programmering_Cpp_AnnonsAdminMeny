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
	while (true) 
	{
		int selection;
		AdServingEngine ase;
		Customer cust;
		Campaign cam;
		Ad ad;
		cout << "1. Create customer.\n2. Create Campaign.\n3. Create Ad.\n4. Get next ad.\n5. Exit.\n.";
		cin >> selection;
		switch (selection) 
		{
		case 1:
			ase.AddCustomer();
			continue;
		case 2:
			cust.AddCampaign();
			continue;
		case 3:
			cam.AddAd();
			continue;
		//case 4:
		//	ad = ase.GetNextAd();
		//	cout << ad;
		case 5:
			break;
		}
	}
}