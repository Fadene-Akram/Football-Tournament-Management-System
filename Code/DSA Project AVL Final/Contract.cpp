#include "Contract.h"

Contract::Contract(const std::string &teamName, const Date &start, const Date &end, const bool &contratIsTerminated)
    : teamName(teamName), start_date(start), end_date(end), is_terminated(contratIsTerminated) {}

void Contract::terminateContract()
{
    is_terminated = true;
}

std::string Contract::Get_teamName() const
{
    return teamName;
}

Date Contract::Get_start_date() const
{
    return start_date;
}

Date Contract::Get_end_date() const
{
    return end_date;
}

bool Contract::Get_is_terminated() const
{
    return is_terminated;
}
