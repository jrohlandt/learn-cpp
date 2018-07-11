#include "../std_lib_facilities.h"

int main()
{
    // rules:
    // rock beats scissors
    // paper beats rock
    // scissors beats paper


    char user_input;
    int user_wins = 0;
    int computer_wins = 0;
    int game_count = 0;
    vector<char> variations = {'r', 'p', 's', 's', 'p'};

    cout << "Let's play Rock Paper Scissors (Best out of " << variations.size() << ")\n";
    cout << "Enter r for rock, p for paper, s for scissors:\n";

    while (cin >> user_input) {
        char computer = variations[game_count];
        cout << "You: " << user_input << "\t" << "Computer: " << computer << "\n";

        if (user_input == 'r' && computer == 'r') {
            cout << "This round is a tie!\n";
        } else if (user_input == 'p' && computer == 'p') {
            cout << "This round is a tie!\n";
        } else if (user_input == 's' && computer == 's') {
            cout << "This round is a tie!\n";
        } else if (user_input == 'r' && computer == 's') {
            cout << "You win this round!\n";
            user_wins++;
        } else if (user_input == 'p' && computer == 'r') {
            cout << "You win this round!\n";
            user_wins++;
        } else if (user_input == 's' && computer == 'p') {
            cout << "You win this round!\n";
            user_wins++;
        } else if (user_input == 'r' && computer == 'p') {
            cout << "You lose, Computer wins this round!\n";
            computer_wins++;
        } else if (user_input == 'p' && computer == 's') {
            cout << "You lose, Computer wins this round!\n";
            computer_wins++;
        } else if (user_input == 's' && computer == 'r') {
            cout << "You lose, Computer wins this round!\n";
            computer_wins++;
        }

        game_count++;

        if (game_count >= variations.size()) {
            cout << "\n---------------------------------\n";
            cout << "\t\tGAME OVER\n";
            cout << "\n---------------------------------\n";

            cout << "\n\n\tScore: \n";
            cout << "You: " << user_wins << "\n";
            cout << "Computer: " << computer_wins << "\n";

            if (user_wins == computer_wins) {
                cout << "\t\tIT'S A TIE";
            } else if (user_wins > computer_wins) {
                cout << "\t\tYOU WIN!";
            } else if (user_wins < computer_wins) {
                cout << "\t\tYOU LOSE!";
            }
        }
    }


    return 0;
}