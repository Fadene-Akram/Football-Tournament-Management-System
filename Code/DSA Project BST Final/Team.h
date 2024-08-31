#ifndef TEAM_H
#define TEAM_H

#include <iostream>
#include <vector>
#include "Player.h"
#include "TeamStatistics.h"

class Team
{
public:
    Team();

    Team(const std::string &name, std::string &coach, std::string &manager);

    void addPlayer(const Player &player);

    void addStatistics(const TeamStatistics &Stat);

    void setPlayers(const std::vector<Player>& players );

    void setStatistics(const std::vector<TeamStatistics>& tStatistics);


    std::string getTeamName() const;

    std::string getCoach() const;

    std::string getManager() const;

    std::vector<Player> getPlayers() const;

    std::vector<TeamStatistics> GetStatistics() const;

    TeamStatistics GetStatistics(const Date &Date) const;

    TeamStatistics GetStatisticsBefore(const Date &Date) const;

    int GetNumMatchPlayedUntil(const Date &date);

private:
    std::string team_name;
    std::vector<Player> players;
    std::string Coach;
    std::string Manager;
    std::vector<TeamStatistics> Statistics;
    // utility function
    bool compareByGoals(const std::pair<Player, PlayerStatistics> &a, const std::pair<Player, PlayerStatistics> &b)
    {
        return a.second.Get_goals_scored() > b.second.Get_goals_scored();
    }
};

#endif
