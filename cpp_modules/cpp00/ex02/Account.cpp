/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 12:31:28 by seomoon           #+#    #+#             */
/*   Updated: 2021/08/07 18:51:48 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int     Account::_nbAccounts = 0;
int     Account::_totalAmount = 0;
int     Account::_totalNbDeposits = 0;
int     Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit):
    _accountIndex(Account::_nbAccounts),
    _amount(initial_deposit),
    _nbDeposits(0),
    _nbWithdrawals(0)
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "created\n";

    Account::_nbAccounts++;
    Account::_totalAmount += initial_deposit;
}

Account::~Account(void)
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";" << "closed\n";

    Account::_nbAccounts--;
}

int     Account::getNbAccounts(void)
{
    return (Account::_nbAccounts);
}

int     Account::getTotalAmount(void)
{
    return (Account::_totalAmount);
}

int     Account::getNbDeposits(void)
{
    return (Account::_totalNbDeposits);
}

int     Account::getNbWithdrawals(void)
{
    return (Account::_totalNbWithdrawals);
}

void    Account::displayAccountsInfos(void)
{
    if (Account::_nbAccounts == 0)
        return ;
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::_nbAccounts << ";";
    std::cout << "total:" << Account::_totalAmount << ";";
    std::cout << "deposits:" << Account::_totalNbDeposits << ";";
    std::cout << "withdrawals:" << Account::_totalNbWithdrawals << "\n";
}

void    Account::makeDeposit(int deposit)
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << this->_amount << ";"; //prev_amount
    std::cout << "deposit:" << deposit << ";";
    std::cout << "amount:" << this->_amount + deposit << ";";
    std::cout << "nb_deposits:" << this->_nbDeposits + 1 << "\n";

    this->_amount += deposit;
    this->_nbDeposits++;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits++;
}

bool    Account::makeWithdrawal(int withdrawal)
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << this->_amount << ";";

    if (this->checkAmount() < withdrawal)
    {
        std::cout << "withdrawal:refused\n";
        return (false);
    }

    std::cout << "withdrawal:" << withdrawal << ";";
    std::cout << "amount:" << this->_amount - withdrawal << ";";
    std::cout << "nb_withdrawals:" << this->_nbWithdrawals + 1 << "\n";

    this->_amount -= withdrawal;
    this->_nbWithdrawals++;
    Account::_totalAmount -= withdrawal;
    Account::_totalNbWithdrawals++;

    return (true);
}

int    Account::checkAmount(void) const
{
    return (this->_amount);
}

void    Account::displayStatus(void) const
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "deposits:" << this->_nbDeposits << ";";
    std::cout << "withdrawals:" << this->_nbWithdrawals << "\n";

}

void    Account::_displayTimestamp(void)
{
    std::time_t rawTime = std::time(NULL);
    struct tm*  tm = localtime(&rawTime);
    std::cout << '[' 
        << tm->tm_year + 1900
        << tm->tm_mon + 1
        << tm->tm_mday 
        << '_' 
        << tm->tm_hour << tm->tm_min << tm->tm_sec
        << "] ";
}
