#include "../std_lib_facilities.h"

bool is_cow(vector<int> numbers, vector<int> used, int guess)
{
    for (int i=0; i < used.size(); ++i)
        if (guess == used[i])
            return false;

    for (int n : numbers) 
    {
        if (n == guess)
            return true;
    }

    return false;
}

int main()
{
    vector<int> numbers = {1, 2, 3, 4};
    vector<int> guesses;
    vector<int> used;
    int g;
    int bulls = 0;
    vector<int> correct_bulls;
    int cows = 0;

    // cout << is_cow(numbers, used, 5); return 0; 

    cout << "\n------------------------------------------------\n";
    cout << "\tBulls and Cows";
    cout << "\n------------------------------------------------\n\n";

    cout << "Guess the four numbers e.g. 1 3 6 9 (each number can be between 1 and 9).\n";
    cout << "Type your guess: \n";

    while (cin >> g)
    {
        guesses.push_back(g);
    }

    cout << "You guessed: " << guesses[0] << " " << guesses[1] << " " << guesses[2] << " " << guesses[3] << "\n";

    for (int i=0; i < guesses.size(); ++i)
    {
        int g = guesses[i];
        if (numbers[i] == g) {
            ++bulls;
            correct_bulls.push_back(g);
        } else if (is_cow(numbers, used, g)) {
            ++cows;
            correct_bulls.push_back(0);
        } else {
            correct_bulls.push_back(0);
        }

        used.push_back(g);

    }

    cout << "Bulls: " << bulls << " Cows: " << cows << "\n";
    for (int i : correct_bulls)
    {
        cout << " " << i << " ";
    }
        
    return 0;
}