#include <cctype>
#include <iostream>


int
main(void)
{
    using std::cin, std::cout;
    cin.tie(nullptr);
    char c;
    int counter = 0;
    int flag_prev_num = 0;
    while (cin.get(c)) {
        if (c == '0') {
            if (flag_prev_num == 0) {
                counter++;
            } else {
                cout << c;
            }
        } else if (std::isdigit(c)) {
            counter = 0;
            flag_prev_num = 1;
            cout << c;
        } else {
            flag_prev_num = 0;
            if (counter != 0) {
                cout << "0";
            }
            counter = 0;
            cout << c;
        }
    }
    if (counter != 0) {
        cout << "0";
    }
    
    return 0;
}


