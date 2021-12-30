#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <algorithm>
#include <time.h>
#include <array>

class Level {
	public:
		int difficulty;
		std::array<int, 3> numberArray{};
		int numberArrayProduct;
		int numberArraySum;

		Level(int d) {
			difficulty = d;
			numberArrayProduct = 1;
			numberArraySum = 0;
		}
};

void printLevelResult(bool isCorrect) {
	if (isCorrect) {
		std::cout << "Right Answer!" << std::endl;
		return;
	}
	std::cout << "Wrong Answer! You need to try again from the start!" << std::endl;
}

int checkIsCorrect(std::array<int, 3> givenArray, std::array<int, 3> correctArray) {
	std::sort(givenArray.begin(), givenArray.end());
	std::sort(correctArray.begin(), correctArray.end());

	for (int i = 0; i < givenArray.max_size(); i++) {
		if (givenArray[i] != correctArray[i]) {
			return -1;
		}
	}

	return 0;
}

std::array<int, 3> getUserAnswer() {
	int inputedNumbersQuantity = 0;
	std::array<int, 3> guessesArray = {};

	while (inputedNumbersQuantity < 3) {
		std::cout << "Number " << inputedNumbersQuantity + 1 << ": ";
		std::cin >> guessesArray[inputedNumbersQuantity];
		++inputedNumbersQuantity;
	}

	return guessesArray;
	
}

void printLevelHint(Level& levelObj) {
	std::cout << "You are currently in the " << levelObj.difficulty << " level" << std::endl;
	std::cout << "The 3 numbers multiplied are equal to " << levelObj.numberArrayProduct << std::endl;
	std::cout << "The 3 numbers summed are equal to " << levelObj.numberArraySum << std::endl;

	std::cout << "Whats your answer?" << std::endl;
}

void setLevelNumbers(Level& levelObj) {
	std::array<int, 3> numberArray{};
	int arrayProduct = 1;
	int arraySum = 0;

	srand(time(0));

	for (int i = 0; i < numberArray.max_size(); i++) {
		numberArray[i] = rand() % (levelObj.difficulty * 2) + levelObj.difficulty;

		levelObj.numberArray[i] = numberArray[i];

		arrayProduct *= numberArray[i];
		arraySum += numberArray[i];
	}

	levelObj.numberArrayProduct = arrayProduct;
	levelObj.numberArraySum = arraySum;
}

int playLevel(Level& levelObj) {

	setLevelNumbers(levelObj);
	printLevelHint(levelObj);
	std::array<int, 3> guesses = { getUserAnswer() };

	return checkIsCorrect(guesses, levelObj.numberArray);
}

int playGame() {
	int STARTING_DIFICULTY = 2;
	int MAX_DIFICULTY = 11;

	Level levelObj(STARTING_DIFICULTY);

	while (levelObj.difficulty <= MAX_DIFICULTY) {
		if(playLevel(levelObj) == 0) levelObj.difficulty += 1;
	}

	std::cout << "You have won the game and therefore the prize! Congratulations!";

	return 0;
}

void printStory() {
	std::cout << "Someday you were navigating on the wide web and something caught your interest" << std::endl;
	std::cout << "An enigma called 'From 3 to 1 million'" << std::endl;
	std::cout << "You opened its website and it says 'If you are able to find the 3 secret numbers in a 10 level based game..." << std::endl;
	std::cout << "we will pay a million dollars in crypto in reward" << std::endl;
	std::cout << "\n Now it is your challenge to beat the game and get the million! Good Luck!" << std::endl;
}

int main() {
	printStory();
	playGame();

	return 0;
}