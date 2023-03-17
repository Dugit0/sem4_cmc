#include <iostream>


int
main(void)
{
    using std::cin, std::cout;
    cin.tie(nullptr);
    char c;
    char prev_c;
    int counter = 1;
    int flag_begin = 0;
    if (!cin.get(prev_c)) {
        return 0;
    }
    while (cin.get(c)) {
        flag_begin = 1;
        if (c == prev_c) {
            counter++;
        } else {
            if (prev_c == '#') {
                cout << std::hex << "##" << counter << "#";
            } else if (counter > 4) {
                cout << std::hex << "#" << prev_c << counter << "#";
            } else {
                for (int i = 0; i < counter; i++) {
                    cout << prev_c;
                }
            }
            counter = 1;
        }
        prev_c = c;
    }
    if (!flag_begin) {
        if (prev_c != '#') {
            cout << prev_c;
        } else {
            cout << "##1#";
        }
    } else {
        if (prev_c == '#') {
            cout << std::hex << "##" << counter << "#";
        } else if (counter > 4) {
            cout << std::hex << "#" << prev_c << counter << "#";
        } else {
            for (int i = 0; i < counter; i++) {
                cout << prev_c;
            }
        }
    }
    
    return 0;
}


