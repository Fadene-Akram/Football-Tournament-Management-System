#include "Player.h"

Player::Player(int Number, const std::string &name, const std::string &pos, const std::string &teamName) : playerNumber(Number), player_name(name), position(pos), TeamName(teamName) {}

int Player::Get_playerNumber() const
{
    return playerNumber;
}

std::string Player::Get_player_name() const
{
    return player_name;
}

std::string Player::Get_position() const
{
    return position;
}

Contract Player::Get_contract() const
{
    return contracts.back();
}

void Player::setPlayerStatistics(const std::vector<PlayerStatistics> &stat)
{
    statistics = stat;
}

std::vector<PlayerStatistics> Player::GetStatistics() const
{
    return statistics;
}

PlayerStatistics Player::GetStatistics(const Date &Date) const
{
    for (size_t i = 0; i < statistics.size(); i++)
    {
        if (statistics.size() >= 2)
        {
            if (statistics[i].Get_Date() == Date)
            {
                return statistics[i];
            }
            else if (statistics[i].Get_Date() > Date)
                return statistics[i - 1];
            else
                return statistics[statistics.size() - 1];
        }
    }
    return statistics[statistics.size() - 1];
}

void Player::Printstat(const Date &Date) const
{
    for (size_t i = 0; i < statistics.size(); i++)
    {
        if (statistics[i].Get_Date() == Date)
        {
            std::cout << "Player Number : " << TeamName << std::endl;
            std::cout << "Player Name : " << player_name << std::endl;
            std::cout << "Player Position : " << position << std::endl;
            statistics[i].printPlayerStat();
            return;
        }

        if (statistics[i].Get_Date() > Date)
        {
            std::cout << "Player Number : " << TeamName << std::endl;
            std::cout << "Player Name : " << player_name << std::endl;
            std::cout << "Player Position : " << position << std::endl;
            statistics[i - 1].printPlayerStat();
            return;
        }
    }
}

PlayerStatistics Player::GetStatisticsBefore(const Date &Date) const
{
    for (size_t i = 0; i < statistics.size(); i++)
    {
        if (statistics.size() >= 2)
        {
            if ((statistics[i].Get_Date() == Date) || (statistics[i].Get_Date() > Date))
            {
                return statistics[i - 1];
            }
            else
                return statistics[statistics.size() - 2];
        }
    }
}

void Player::AddPlayerStatistic(PlayerStatistics newplayerstat)
{
    statistics.push_back(newplayerstat);
}

void Player::addContract(const Contract &NewCont)
{
    if ((contracts.size() >= 1))
    {
        contracts.back().terminateContract();
    }

    contracts.push_back(NewCont);
}

int Player::GetNumberMatchPlayed(Date date) const
{
    int matchPlayed = 1;
    for (size_t i = 0; i < statistics.size(); i++)
    {
        if (statistics[i].Get_Date() == date)
        {
            return matchPlayed;
        }
        if (statistics[i].Get_Date() > date)
            return matchPlayed - 1;
        matchPlayed++;
    }
}

double Player::GameKmRun(const Date &date) const
{
    return GetStatistics(date).Get_kilometers_run() - GetStatisticsBefore(date).Get_kilometers_run();
}

double Player::AverageKmRun(const Date &date) const
{
    return GetStatistics(date).Get_kilometers_run() / GetNumberMatchPlayed(date);
}

bool Player::operator<(const Player &player) const
{
    if (this->statistics[statistics.size() - 1].Get_goals_scored() == player.statistics[statistics.size() - 1].Get_goals_scored())
    {
        return this->statistics[statistics.size() - 1].getPlayerName() < player.statistics[statistics.size() - 1].getPlayerName();
    }
    else if (this->statistics[statistics.size() - 1].Get_goals_scored() > player.statistics[statistics.size() - 1].Get_goals_scored())
    {
        return false;
    }
    return true;
}