#include "Date.h"

Date::Date(int YEAR, int MONTH, int DAY) : year(YEAR), month(MONTH), day(DAY){};

void Date::setDateYear(const int &y)
{
    year = y;
}

int Date::getDateYear(void) const
{
    return year;
}

void Date::setDateMonth(const int &m)
{
    month = m;
}

int Date::getDateMonth(void) const
{
    return month;
}

void Date::setDateDay(const int &d)
{
    day = d;
}

int Date::getDateDay(void) const
{
    return day;
}

std::string Date::getDate(void) const
{
    return std::to_string(getDateYear()) + "-" + std::to_string(getDateMonth()) + "-" + std::to_string(getDateDay());
}

bool Date::operator>(const Date &date)
{
    if (this->year > date.year)
    {
        if (this->month > date.month)
        {
            if (this->day > date.day)
            {
                return true;
            }
        }
    }
    return false;
}

bool Date::operator==(const Date &date)
{
    if (this->year == date.year)
    {
        if (this->month == date.month)
        {
            if (this->day == date.day)
            {
                return true;
            }
        }
    }
    return false;
}
