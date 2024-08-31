#include "File.h"

void File::readPlayersFromCSV(const std::string &filename, Team &t1)
{
    std::vector<Player> players;

    int playerCount = 1;
    std::string temp = filename + ".csv";
    std::ifstream file(temp);
    if (!file.is_open())
    {
        std::cerr << "Error opening file: " << temp << " 'player function'" << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string playerNumberStr, playerName, playerPosition, Team, startDateYear, startDateMonth, startDateDay, endDateYear, endDateMonth, endDateDay;

        std::getline(ss, Team, ',');
        std::getline(ss, playerNumberStr, ',');
        std::getline(ss, playerName, ',');
        std::getline(ss, playerPosition, ',');
        std::getline(ss, startDateYear, ',');
        std::getline(ss, startDateMonth, ',');
        std::getline(ss, startDateDay, ',');
        std::getline(ss, endDateYear, ',');
        std::getline(ss, endDateMonth, ',');
        std::getline(ss, endDateDay, ',');
        Player player(std::stoi(playerNumberStr), playerName, playerPosition, Team);
        Contract contract(Team, Date(std::stoi(startDateYear), std::stoi(startDateMonth), std::stoi(startDateDay)), Date(std::stoi(endDateYear), std::stoi(endDateMonth), std::stoi(endDateDay)));

        readPlayerStatisticsFromCSV(filename + "-player" + std::to_string(playerCount), player);

        player.addContract(contract);
        playerCount++;
        players.push_back(player);
    }

    file.close();
    t1.setPlayers(players);
}

void File::readTeamsFromCSV(const std::string &filename, Tournament &t1)
{
    std::vector<Team> teams;
    int count = 1;
    std::ifstream file(filename + "teams.csv");
    if (!file.is_open())
    {
        std::cerr << "Error opening file: " << filename + "teams.csv"
                  << " 'team function'" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string teamName, coach, ownername;

        std::getline(ss, teamName, ',');
        std::getline(ss, coach, ',');
        std::getline(ss, ownername, ',');

        Team team(teamName, coach, ownername);

        std::string temp = filename + "team-" + std::to_string(count);
        std::string temp2 = filename + "team" + std::to_string(count);

        readPlayersFromCSV(temp2, team);

        readTeamStatisticsFromCSV(temp + "-statistic", team);

        teams.push_back(team);
        count++;
    }

    file.close();
    t1.SetTournamentTeams(teams);
}

void File::readPlayerStatisticsFromCSV(const std::string &filename, Player &p1)
{
    std::vector<PlayerStatistics> playerStats;

    std::ifstream file(filename + ".csv");
    if (!file.is_open())
    {
        std::cerr << "Error opening file: " << filename << ".csv"
                  << " 'playerStat function'" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string dateYear, dateMonth, dateDay, playerName, _, goalsStr, yellowCardsStr, redCardsStr, kilometersRunStr, playingTimeStart, playingTimeEnd, number;

        std::getline(ss, dateDay, ',');
        std::getline(ss, dateMonth, ',');
        std::getline(ss, dateYear, ',');
        std::getline(ss, playerName, ',');
        std::getline(ss, _, ',');
        std::getline(ss, playingTimeStart, ',');
        std::getline(ss, playingTimeEnd, ',');

        std::getline(ss, yellowCardsStr, ',');
        std::getline(ss, redCardsStr, ',');
        std::getline(ss, kilometersRunStr, ',');
        std::getline(ss, number, ',');
        std::getline(ss, goalsStr, ',');

        PlayerStatistics player(std::stoi(goalsStr), std::stoi(yellowCardsStr), std::stoi(redCardsStr), std::stod(kilometersRunStr), std::stoi(playingTimeStart), std::stoi(playingTimeEnd), Date(std::stoi(dateYear), std::stoi(dateMonth), std::stoi(dateDay)), playerName, std::stoi(number));
        playerStats.push_back(player);
    }

    p1.setPlayerStatistics(playerStats);

    file.close();
}

void File::readTeamStatisticsFromCSV(const std::string &filename, Team &t1)
{
    std::vector<TeamStatistics> teamStats;

    std::ifstream file(filename + ".csv");
    if (!file.is_open())
    {
        std::cerr << "Error opening file: " << filename << " 'teamStat function'" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string teamName, points, goalsScored, goalsConceded, Gamesplayednumber, dateYear, dateMonth, dateDay;
        std::getline(ss, teamName, ',');
        std::getline(ss, points, ',');
        std::getline(ss, goalsScored, ',');
        std::getline(ss, goalsConceded, ',');
        std::getline(ss, Gamesplayednumber, ',');
        std::getline(ss, dateDay, ',');
        std::getline(ss, dateMonth, ',');
        std::getline(ss, dateYear, ',');

        TeamStatistics statistics(teamName, std::stoi(points), std::stoi(goalsScored), std::stoi(goalsConceded), std::stoi(Gamesplayednumber), Date(std::stoi(dateYear), std::stoi(dateMonth), std::stoi(dateDay)));
        teamStats.push_back(statistics);
    }

    t1.setStatistics(teamStats);
    file.close();
}

void File::readGamesFromCSV(const std::string &filename, Tournament &t1)
{
    AvlTree<Game> games;

    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string dateYear, dateMonth, dateDay, startGameTime, referee, duration, homeTeam, awayTeam, home_team_score, away_team_score;
        std::getline(ss, dateDay, ',');
        std::getline(ss, dateMonth, ',');
        std::getline(ss, dateYear, ',');
        std::getline(ss, homeTeam, ',');
        std::getline(ss, awayTeam, ',');
        std::getline(ss, home_team_score, ',');
        std::getline(ss, away_team_score, ',');
        std::getline(ss, startGameTime, ',');
        std::getline(ss, referee, ',');
        std::getline(ss, duration, ',');

        Team &HomeTeam = t1.FindTeam(homeTeam);
        Team &AwayTeam = t1.FindTeam(awayTeam);

        Game GameFile(HomeTeam, AwayTeam, Date(std::stoi(dateYear), std::stoi(dateMonth), std::stoi(dateDay)),
                      startGameTime, referee, std::stoi(home_team_score), std::stoi(away_team_score), std::stoi(duration));
        games.insert(GameFile);
    }

    t1.SetTournamentGames(games);
    file.close();
}
