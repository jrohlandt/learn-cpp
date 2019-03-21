#include<iostream>
#include<vector>
#include<string>
#include<fstream>

struct Point {
    int x;
    int y;
};

std::istream& operator>>(std::istream& is, Point& point) 
{
    char separator = ',';
    
    char ch1, ch2;
    is >> ch1 >> ch2;
    if (ch1 != 'x' || ch2 != ':') {
        is.unget();
        is.clear(std::ios_base::failbit);
        return is;
    }

    int x;
    is >> x;
    point.x = x;

    char ch3, ch4;
    is >> ch3 >> ch4;
    if (ch3 != 'y' || ch4 != ':') {
        is.unget();
        is.clear(std::ios_base::failbit);
        return is;
    }

    int y;
    is >> y;
    point.y = y;

    return is;
}


int main()
{
    // std::cout << "Please specify a file name: \n";
    std::string filename = "points.txt";
    // std::cin >> filename;

    std::ifstream ifs {filename};

    std::vector<Point> points;
    while(true) {
        Point point;
        if (! (ifs >> point) ) {
            break;
        }
        points.push_back(point);
        
        char sep;
        ifs >> sep;
        if (sep != ',') {
            throw std::runtime_error("Bad separator");
        }
    }

    std::cout << "\nPoints: \n";
    for (Point pp : points) {
        std::cout << pp.x << " " << pp.y << "\n";
    }
}



