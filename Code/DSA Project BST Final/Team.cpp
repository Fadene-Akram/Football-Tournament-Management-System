#include "Team.h"

Team::Team() = default;

Team::Team(const std::string &name, std::string &coach, std::string &manager) : team_name(name), Coach(coach), Manager(manager){};

void Team::addPlayer(const Player &player)
{
    players.push_back(player);
}

void Team::addStatistics(const TeamStatistics &Stat)
{
    Statistics.push_back(Stat);
}

std::string Team::getTeamName() const
{
    return team_name;
}

std::string Team::getCoach() const
{
    return Coach;
}

std::string Team::getManager() const
{
    return Manager;
}

std::vector<Player> Team::getPlayers() const
{
    return players;
}

std::vector<TeamStatistics> Team::GetStatistics() const
{
    return Statistics;
}

TeamStatistics Team::GetStatistics(const Date &Date) const
{
    for (size_t i = 0; i < Statistics.size(); i++)
    {
        if (Statistics[i].Get_Date() == Date)
        {
            return Statistics[i];
        }
        else if (Statistics[i].Get_Date() > Date)
            return Statistics[i - 1];
        else
            return  Statistics[Statistics.size()-1];
    }
}

TeamStatistics Team::GetStatisticsBefore(const Date &Date) const
{
    for (size_t i = 0; i < Statistics.size(); i++)
    {
        if ((Statistics[i].Get_Date() == Date) || (Statistics[i].Get_Date() > Date))
        {
            return Statistics[i - 1];
        }
    }
}

int Team::GetNumMatchPlayedUntil(const Date &date)
{
    int matchPlayed = 1;
    for (size_t i = 0; i < Statistics.size(); i++)
    {
        if (Statistics[i].Get_Date() == date)
        {
            return matchPlayed;
        }
        if (Statistics[i].Get_Date() > date)
            return matchPlayed - 1;
        matchPlayed++;
    }
}



void Team::setPlayers(const std::vector<Player>& players ){
    this->players = players;
}

void Team::setStatistics(const std::vector<TeamStatistics>& tStatistics){
    this->Statistics = tStatistics;
}