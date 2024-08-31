#include "Game.h"

Game::Game(Team &home_team, Team &away_team, Date date_time, std::string startTime, std::string referee, int home_team_score, int away_team_score, int duration_minutes) : Home_team(home_team), Away_team(away_team), gameDate(date_time), gameStartTime(startTime), Referee(referee), home_score(home_team_score), away_score(away_team_score)
{
    Duration_minutes = (duration_minutes < 90) ? 90 : duration_minutes;
};

Team &Game::get_home_team()
{
    return Home_team;
}

Team &Game::get_away_team()
{
    return Away_team;
}

Date Game::getGameDate() const
{
    return gameDate;
}

std::string Game::get_refere() const
{
    return Referee;
}

int Game::get_duration() const
{
    return Duration_minutes;
}

void Game::PrintGameInfo() const
{
    std::cout << "Home Team : " << Home_team.getTeamName() << std::endl;
    std::cout << "Away Team : " << Away_team.getTeamName() << std::endl;
    std::cout << "Date Time : " << gameDate.getDate() << std::endl;
    std::cout << "Referee : " << Referee << std::endl;
    std::cout << "Duration Minutes : " << Duration_minutes << std::endl;
}

bool Game::operator<(const Game &game) const
{
    if (this->getGameDate() > game.getGameDate())
    {
        return false;
    }
    else if (this->getGameDate() == game.getGameDate())
    {
        if (this->gameStartTime > game.gameStartTime)
        {
            return false;
        }
    }
    return true;
}

std::string Game::get_start_time() const
{
    return gameStartTime;
}