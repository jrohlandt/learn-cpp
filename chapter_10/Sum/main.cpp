#include<iostream>
#include<fstream>
#include<string>

int main()
{
    std::string filename = "numbers.txt";

    std::fstream ifs {filename};

    int sum = 0;

    while(true) {

        int n;
        if ( ! (ifs >> n) ) {
            break;
        }

        sum += n;
    }

    std::cout << "Sum: " << sum << "\n";
}