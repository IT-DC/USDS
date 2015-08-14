#ifndef TICKET_SALES
#define TICKET_SALES

#include <time.h>

struct voucher
{
	int voucher_number;
	double summ;
	char goods_name[128];
	time_t time_of_sell;
	bool status;
};

// Your class with business logic, that needs to serialize/deserialize
class TicketSales
{
public:
	TicketSales(int num_vouchers, bool clean);
	~TicketSales();

private:
	int shiftNumber;
	int cashRegister;
	time_t startShift;
	time_t endShift;
	voucher* vouchers;
	int numVouchers;

public:
	int getShiftNumber() { return shiftNumber; };
	int getCashRegister() { return cashRegister; };
	time_t getStartShift() { return startShift; };
	time_t getEndShift() { return endShift; };
	voucher* getVouchers() { return vouchers; };
	int getNumVouchers() { return numVouchers; };

	void setShiftNumber(int value) { shiftNumber = value; };
	void setCashRegister(int value) { cashRegister = value; };
	void setStartShift(time_t value) { startShift = value; };
	void setEndShift(time_t value) { endShift = value; };

};

#endif