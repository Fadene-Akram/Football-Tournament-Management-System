#ifndef Date_H
#define Date_H
#include <iostream>
class Date
{

public:
    Date(int YEAR, int MONTH, int DAY);

    bool operator>(const Date &date);

    bool operator==(const Date &date);

    void setDateYear(const int &y);

    int getDateYear(void) const;

    void setDateMonth(const int &m);

    int getDateMonth(void) const;

    void setDateDay(const int &d);

    int getDateDay(void) const;

    std::string getDate(void) const;

private:
    int year, month, day;
};

#endif