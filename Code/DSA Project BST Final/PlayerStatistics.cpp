#include "PlayerStatistics.h"

PlayerStatistics::PlayerStatistics(int goalscored, int yellowcards, int red_cards, double kilometersrun, int playing_time_start,
                                   int playing_time_end, class Date date , const std::string& name,int number) : goals_scored(goalscored), yellow_cards(yellowcards), red_cards(red_cards), kilometers_run(kilometersrun), playing_time_start(playing_time_start), playing_time_end(playing_time_end), Date(date) , playerName(name), playerNumber(number){};

int PlayerStatistics::Get_goals_scored() const
{
    return goals_scored;
}

int PlayerStatistics::Get_yellow_cards() const
{
    return yellow_cards;
}

int PlayerStatistics::Get_red_cards() const
{
    return red_cards;
}

double PlayerStatistics::Get_kilometers_run() const
{
    return kilometers_run;
}

std::string PlayerStatistics::getPlayerName() const {
    return  playerName;
}
int PlayerStatistics::Get_time_start_game() const
{
    return playing_time_start;
}

int PlayerStatistics::Get_time_end_game() const
{
    return playing_time_end;
}

Date PlayerStatistics::Get_Date() const
{
    return Date;
}

void PlayerStatistics::Set_goals_scored(int score)
{
    goals_scored += score;
}

void PlayerStatistics::Set_yellow_cards(int cards)
{
    if (cards == 1)
        yellow_cards += 1;
    else if (cards == 2)
        red_cards += 1;
}

void PlayerStatistics::Set_red_cards(int cards)
{
    if (cards == 1)
        red_cards += cards;
}

void PlayerStatistics::Set_kilometers_run(double km)
{
    kilometers_run += km;
}

void PlayerStatistics::printPlayerStat() const
{
    std::cout << "Goals scored: " << goals_scored << std::endl;
    std::cout << "Yellow cards: " << yellow_cards << std::endl;
    std::cout << "Red cards: " << red_cards << std::endl;
    std::cout << "Kilometers Run: " << kilometers_run << std::endl;
}

bool PlayerStatistics::operator<(const PlayerStatistics &playerstat)
{
    if (this->Get_goals_scored() > playerstat.Get_goals_scored())
    {
        return false;
    }
    else if (this->Get_goals_scored() == playerstat.Get_goals_scored())
    {
        if (this->playerName > playerstat.playerName)
        {
            return false;
        }
    }
    return true;
}

bool PlayerStatistics::operator<(const PlayerStatistics& playerstat) const {
    if (this->Get_goals_scored() > playerstat.Get_goals_scored())
    {
        return false;
    }
    else if (this->Get_goals_scored() == playerstat.Get_goals_scored())
    {
        if (this->playerName > playerstat.playerName)
        {
            return false;
        }
    }
    return true;
}
