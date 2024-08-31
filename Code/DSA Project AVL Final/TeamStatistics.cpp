#include "TeamStatistics.h"
#include "Date.h"
#include <iomanip>
TeamStatistics::TeamStatistics(std::string name, int point, int goalsscored, int goalsconceded, int Gamesplayednumber, class Date date) : teamName(name), points(point), goals_scored(goalsscored), goals_conceded(goalsconceded), GamesPlayedNumber(Gamesplayednumber), Date(date){};

int TeamStatistics::Get_points() const
{
    return points;
}

int TeamStatistics::Get_goals_scored() const
{
    return goals_scored;
}

int TeamStatistics::Get_goals_conceded() const
{
    return goals_conceded;
}

std::string TeamStatistics::Get_name() const
{
    return teamName;
}

Date TeamStatistics::Get_Date() const
{
    return Date;
}

void TeamStatistics::Set_points(int point)
{
    points += point;
}

void TeamStatistics::Set_goals_scored(int goal)
{
    goals_scored += goal;
}

void TeamStatistics::Set_goals_conceded(int goal)
{
    goals_conceded += goal;
}

void TeamStatistics::printTeamStatistics(void) const
{
    std::cout << std::left;
    std::cout << std::setw(17) << points << std::setw(17) << goals_scored << std::setw(22) << goals_conceded << std::setw(22) << goals_scored - goals_conceded << GamesPlayedNumber << std::endl;
    std::cout << "__________________________________________________________________________________________________________________________________" << std::endl;
}

bool TeamStatistics::operator<(const TeamStatistics &Stat)
{
    if (this->Get_points() > Stat.Get_points())
    {
        return false;
    }
    else if (this->Get_points() == Stat.Get_points())
    {
        if (this->Get_goals_scored() > Stat.Get_goals_scored())
        {
            return false;
        }
        else if (this->Get_goals_conceded() > Stat.Get_goals_conceded())
        {
            return false;
        }
    }
    return true;
}