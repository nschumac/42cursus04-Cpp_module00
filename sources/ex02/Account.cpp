#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

std::string g_status = "";

int Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

int Account::getTotalAmount(void)
{
	return (_totalAmount);
}

void	Account::makeDeposit( int deposit )
{
	this->_totalNbDeposits++;
	this->_nbDeposits++;
	this->_amount += deposit;
	this->_totalAmount += deposit;
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount - deposit << ";deposit:" << deposit << ";amount:" << this->_amount <<";nb_deposits:"<< this->_nbDeposits << std::endl;
	
}
bool	Account::makeWithdrawal( int withdrawal )
{
	if (withdrawal > this->_amount)
	{
		_displayTimestamp();
		std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:refused" <<  std::endl;
		return (false);
	}
	this->_totalNbWithdrawals++;
	this->_nbWithdrawals++;
	this->_amount -= withdrawal;
	this->_totalAmount -= withdrawal;
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount + withdrawal << ";withdrawal:" << withdrawal << ";amount:" << this->_amount <<";nb_withdrawals:"<< this->_nbWithdrawals << std::endl;
	return (true);
}
int		Account::checkAmount( void ) const
{
	return (this->_amount);
}
void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:"
		<< this->_amount << ";" << "deposits:" << this->_nbDeposits
		<< ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

Account::Account(int initial_deposit)
{
	this->_amount = initial_deposit;
	this->_totalAmount += initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_totalNbDeposits = 0;
	this->_totalNbWithdrawals = 0;
	this->_accountIndex = this->_nbAccounts;
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:"
		<< this->_amount << ";created" << std::endl;
	this->_nbAccounts++;
}

Account::Account(void)
{
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_totalAmount = 0;
	this->_totalNbDeposits = 0;
	this->_totalNbWithdrawals = 0;
	this->_accountIndex = this->_nbAccounts;
	this->_nbAccounts++;
}

Account::~Account(void)
{
	this->_nbAccounts--;
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed";
	if (this->_nbAccounts > 0)
		std::cout << std::endl;
}

void	Account::_displayTimestamp( void )
{
	// time_t now;
	// tm *ltm;

	// now = time(NULL);
	// ltm = localtime(&now);
	// std::cout << "[" << std::setfill('0') << 1900 + ltm->tm_year << std::setw(2) << 1 + ltm->tm_mon << std::setw(2) << ltm->tm_mday
	// 		<< "_" << std::setw(2) <<ltm->tm_hour << std::setw(2) << ltm->tm_min << std::setw(2) << ltm->tm_sec << "]";
	std::cout << "[19920104_091532]";

}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts << ";total:" << _totalAmount
		<< ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}