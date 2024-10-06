// Header files for Score
// Represents the total score of the game, highest score and remaining lives


class Score{

private:

int currentScore;
int highestScore;
int lives;
bool gameOver;

public:

void updateScore(FoodItems& food);
void updateHighestScore(currentScore gameScore);
void getHighScore();
bool gameOver();

};
