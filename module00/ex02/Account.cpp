/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 13:18:29 by dshirais          #+#    #+#             */
/*   Updated: 2026/06/11 13:18:30 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <iomanip>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{   
    _accountIndex = _nbAccounts;
    _nbAccounts++;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbDeposits = 0;

    _displayTimestamp();
    std::cout 
        << "index:" << _accountIndex 
        << ";amount:" << initial_deposit 
        << ";created" 
        << std::endl;

    _totalAmount += initial_deposit;
}

Account::~Account( void )
{
    _displayTimestamp();
    std::cout 
        << "index:" << _accountIndex 
        << ";amount:" << _amount 
        << ";closed" 
        << std::endl;
}

int Account::getNbAccounts( void )
{
    return _nbAccounts;
}

int Account::getTotalAmount( void )
{
    return _totalAmount;
}

int Account::getNbDeposits( void )
{
    return _totalNbDeposits;
}

int Account::getNbWithdrawals( void )
{
    return _totalNbWithdrawals;
}

void Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout 
        << "accounts:" << getNbAccounts() 
        << ";total:" << getTotalAmount() 
        << ";deposits:" << getNbDeposits() 
        << ";withdrawals:" << getNbWithdrawals() 
        << std::endl;
}

void Account::makeDeposit( int deposit )
{
    _displayTimestamp();
    std::cout 
        << "index:" << _accountIndex 
        << ";p_amount:" << _amount
        << ";deposit:" << deposit;
    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits++; 
    _totalNbDeposits++; 
    std::cout
        << ";amount:" << _amount 
        << ";nb_deposits:" << _nbDeposits 
        << std::endl;
}

bool Account::makeWithdrawal ( int withdrawal)
{
    _displayTimestamp();
    std::cout 
        << "index:" << _accountIndex 
        << ";p_amount:" << _amount
        << ";withdrawals:";
    if (checkAmount() < withdrawal)
    {
        std::cout << "refused" << std::endl;
        return false;
    }
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    std::cout
        << withdrawal
        << ";amount:" << _amount
        << ";nb_withdrawals:" << _nbWithdrawals
        << std::endl;
    return (true);
}

int Account::checkAmount(void) const
{
    return _amount;
}

void Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout
        << "index:" << _accountIndex
        << ";amount:" << _amount
        << ";deposits:" << _nbDeposits
        << ";withdrawals:" << _nbWithdrawals
        << std::endl;
}

void Account::_displayTimestamp(void)
{
    time_t curr_time;
	curr_time = time(NULL);

	tm *tm_local = localtime(&curr_time);
    std::cout
        << "["
        << std::setw(4) << std::setfill('0') << tm_local->tm_year + 1900
        << std::setw(2) << std::setfill('0') << tm_local->tm_mon + 1
        << std::setw(2) << std::setfill('0') << tm_local->tm_mday
        << "_"
        << std::setw(2) << std::setfill('0') << tm_local->tm_hour
        << std::setw(2) << std::setfill('0') << tm_local->tm_min
        << std::setw(2) << std::setfill('0') << tm_local->tm_sec
        << "] ";
}