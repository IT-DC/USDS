#include "ticketSales.h"

// This library is needed for USDS - memcpy()
#include <string.h>
#include <cstdio>

using namespace std;

TicketSales::TicketSales(int num_vouchers, bool clean)
{
	if (clean)
	{
		shiftNumber = 1234;
		cashRegister = 9992828;
		startShift = 8887776;
		endShift = 8889999;

		numVouchers = num_vouchers;
		vouchers = new voucher[numVouchers];

		for (int i = 0; i < numVouchers; i++)
		{
			vouchers[i].voucher_number = i;
			vouchers[i].summ = i*i;
			sprintf(vouchers[i].goods_name, "Goods ID is %i", i);
			vouchers[i].time_of_sell = i*i;
			if (i/2*2 == i)
				vouchers[i].status = true;
			else
				vouchers[i].status = false;
		}
	}
	else
	{
		shiftNumber = 0;
		cashRegister = 0;
		startShift = 0;
		endShift = 0;

		numVouchers = num_vouchers;
		vouchers = new voucher[numVouchers];

		for (int i = 0; i < numVouchers; i++)
		{
			vouchers[i].voucher_number = 0;
			vouchers[i].summ = 0;
			vouchers[i].goods_name[0] = 0;
			vouchers[i].time_of_sell = 0;
			vouchers[i].status = false;
		}
	}
};

TicketSales::~TicketSales() 
{ 
	delete[] vouchers;
};

