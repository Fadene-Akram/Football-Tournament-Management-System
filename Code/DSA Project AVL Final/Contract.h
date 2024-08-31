#ifndef CONTRACT_H
#define CONTRACT_H

#include <iostream>
#include "Date.h"

class Contract
{
public:
    Contract(const std::string &teamName, const Date &start, const Date &end, const bool &contratIsTerminated = false);

    void terminateContract();

    std::string Get_teamName() const;

    Date Get_start_date() const;

    Date Get_end_date() const;

    bool Get_is_terminated() const;

private:
    std::string teamName;
    Date start_date;
    Date end_date;
    bool is_terminated;
};

#endif