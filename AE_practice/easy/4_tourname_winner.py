def tournament_winner(competitions, results):
    current_best_team = ""
    scores = {current_best_team: 0}
    for idx, item in enumerate(competitions):
        result = results[idx]
        home_team, away_team = item

        winner_team = home_team if result == 1 else away_team

        update_scores(winner_team, 1, scores)

        if scores[winner_team] > scores[current_best_team]:
            current_best_team = winner_team
    return current_best_team


def update_scores(team, points, scores):
    if team not in scores:
        scores[team] = 0

    scores[team] += points


print(tournament_winner([['a', 'b']], [0]))
