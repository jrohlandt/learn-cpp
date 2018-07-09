#include "../std_lib_facilities.h"

int main()
{
    string your_name;

    string first_name;
    int friend_age;
    string comment_on_age;

    string friend_name;
    char friend_sex;
    string refer_to = "him";

    cout << "What is your name?";

    cin >> your_name;
    
    cout << "Enter the name of the person you want to write to (then press ENTER):";

    cin >> first_name;

    cout << "Specify your friends age:\n";

    cin >> friend_age;

    if (friend_age > 60) {
        comment_on_age = "You must be looking forward to retirement?\n";
    } else if (friend_age == 17) {
        comment_on_age = "You must be excited about being able to drive next year.\n";
    } else if (friend_age > 30) {
        comment_on_age = "We are getting old now.\n";
    } else {
        comment_on_age = "Well happy birthday!\n";
    }
    
    cout << "Please type another friends name:\n";

    cin >> friend_name;

    cout << "Please specify sex of second friend: (f for female and m for male)\n";

    cin >> friend_sex;

    if (friend_sex == 'f') {
        refer_to = "her";
    } 

    cout << "Dear " << first_name << ",\n"
        << "I hope this letter finds you well.\n"
        << "Have you seen " << friend_name << " recently?\n"
        << "If you do see " << friend_name << ", please ask " << refer_to << " to call me.\n\n"
        << "On another note, I hear you just turned " << friend_age << ".\n"
        << comment_on_age;

    cout << "\n"
        << "Yours Sincerely,\n\n\n"
        << your_name << "\n";

    

    




    
}