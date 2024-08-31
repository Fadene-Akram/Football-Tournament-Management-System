#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include "Contract.h"
#include "PlayerStatistics.h"

class Player
{
public:
    Player(int Number, const std::string &name, const std::string &pos, const std::string &teamName);

    int Get_playerNumber() const;

    std::string Get_player_name() const;

    std::string Get_position() const;

    Contract Get_contract() const;

    void setPlayerStatistics(const std::vector<PlayerStatistics> &stat);

    std::vector<PlayerStatistics> GetStatistics() const;

    PlayerStatistics GetStatistics(const Date &Date) const;

    void Printstat(const Date &Date) const;

    PlayerStatistics GetStatisticsBefore(const Date &Date) const;

    void AddPlayerStatistic(PlayerStatistics newplayerstat);

    void addContract(const Contract &NewCont);

    int GetNumberMatchPlayed(Date date) const;

    double GameKmRun(const Date &date) const;

    double AverageKmRun(const Date &date) const;

    bool operator<(const Player &player) const;

private:
    int playerNumber;
    std::string TeamName;
    std::string player_name;
    std::string position;
    std::vector<PlayerStatistics> statistics;
    std::vector<Contract> contracts;
};
#endif