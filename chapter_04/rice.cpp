#include "../std_lib_facilities.h"

int main()
{
    // 1  1 x 2  2 * 2   4 * 2
    int max_squares = 64;
    int current_square = 1;
    double value = 0;
    int squares_1k = 0; // squares required for 1000 grains of rice.
    int squares_1m = 0;
    int squares_1b = 0;


    for (current_square; current_square <= max_squares; current_square++) {
        value = current_square == 1 ? 1 : value * 2;
        if (squares_1k == 0 && value >= 1000) {
            squares_1k = current_square;
        } else if (squares_1m == 0 && value >= 1000000) {
            squares_1m = current_square;
        } else if (squares_1b == 0 && value >= 1000000000) {
            squares_1b = current_square;
        }
        cout << "Current square: " << current_square << " Value: " << value << "\n";
    }

    cout << squares_1k << " squares are required to earn 1000 grains of rice.\n";
    cout << squares_1m << " squares are required to earn 1 000 000 grains of rice.\n";
    cout << squares_1b << " squares are required to earn 1 000 000 000 grains of rice.\n";

    return 0;
}