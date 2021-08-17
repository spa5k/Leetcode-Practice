// Time - O(n)  N is the number
// Space - O(a) where a is the number of teams

const tournamentWinner = (competitions, results) => {
  let currentBestTeam = "";
  const scores = { [currentBestTeam]: 0 };
  for (let i = 0; i < competitions.length; i++) {
    const result = results[i];
    const [homeTeam, awayTeam] = competitions[i];

    const winningTeam = result === 1 ? homeTeam : awayTeam;
    updateScores(winningTeam, 3, scores);

    if (scores[winningTeam] > scores[currentBestTeam]) {
      currentBestTeam = winningTeam;
    }
  }
  console.log(currentBestTeam);
  return currentBestTeam;
};

const updateScores = (team, points, scores) => {
  if (!(team in scores)) scores[team] = 0;

  scores[team] += points;
};

console.log(
  tournamentWinner(
    [
      ["HTML", "C"],
      ["C", "Python"],
      ["Python", "HTML"],
    ],
    [0, 0, 1]
  )
);
