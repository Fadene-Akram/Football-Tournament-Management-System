#ifndef TEAMSTATISTICS_H
#define TEAMSTATISTICS_H

#include <iostream>
#include "Date.h"

class TeamStatistics
{
public:
    TeamStatistics(std::string name,int point, int goalsscored, int goalsconceded, int Gamesplayednumber, Date date);

    int Get_points() const;

    int Get_goals_scored() const;

    int Get_goals_conceded() const;

    std::string Get_name()const;

    Date Get_Date() const;

    void Set_points(int point);

    void Set_goals_scored(int goal);

    void Set_goals_conceded(int goal);

    void printTeamStatistics(void) const;

    bool operator<(const TeamStatistics &Stat);
private:
    int points = 0;
    int goals_scored = 0;
    int goals_conceded = 0;
    int GamesPlayedNumber = 0;
    std::string teamName;
    Date Date;
};
#endif