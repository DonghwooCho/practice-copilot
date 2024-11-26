#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>

class Game {
public:
    void play() {
        char playAgain;
        do {
            int userChoice;
            do {
                userChoice = getUserChoice();
                if (userChoice < 1 || userChoice > 3) {
                    std::cout << "올바르지 않은 입력값입니다. 다시 시도하세요." << std::endl;
                }
            } while (userChoice < 1 || userChoice > 3);

            int computerChoice = getComputerChoice();
            displayChoices(userChoice, computerChoice);
            determineWinner(userChoice, computerChoice);
            playAgain = askPlayAgain();
        } while (std::toupper(playAgain) == 'Y');
    }

private:
    int getUserChoice() {
        int choice;
        std::cout << "가위(1), 바위(2), 보(3) 중 하나를 선택하세요: ";
        std::cin >> choice;
        return choice;
    }

    int getComputerChoice() {
        std::srand(std::time(0));
        return std::rand() % 3 + 1;
    }

    void displayChoices(int userChoice, int computerChoice) {
        std::cout << "사용자의 선택: " << choiceToString(userChoice) << std::endl;
        std::cout << "컴퓨터의 선택: " << choiceToString(computerChoice) << std::endl;
    }

    std::string choiceToString(int choice) {
        switch (choice) {
            case 1: return "가위";
            case 2: return "바위";
            case 3: return "보";
            default: return "알 수 없음";
        }
    }

    void determineWinner(int userChoice, int computerChoice) {
        if (userChoice == computerChoice) {
            std::cout << "비겼습니다!" << std::endl;
        } else if ((userChoice == 1 && computerChoice == 3) ||
                   (userChoice == 2 && computerChoice == 1) ||
                   (userChoice == 3 && computerChoice == 2)) {
            std::cout << "사용자가 이겼습니다!" << std::endl;
        } else {
            std::cout << "컴퓨터가 이겼습니다!" << std::endl;
        }
    }

    char askPlayAgain() {
        char response;
        std::cout << "게임을 다시 하시겠습니까? (Y/N): ";
        std::cin >> response;
        return response;
    }
};

int main() {
    Game game;
    game.play();
    return 0;
}