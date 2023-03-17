#include <iostream>

using std::cin, std::cout, std::endl;

int
main(void)
{
    unsigned int counter = 0;
    unsigned int buf_shift;
    cin >> buf_shift;
    unsigned int cur_byte;
    unsigned int cur_num = 0;
    while (cin >> std::hex >> cur_byte) {
        counter++;
        cur_num = (cur_num << 8) | cur_byte;
        if (counter % 4 == 0) {
            cout << cur_num << endl;
        }
        if (counter % 16 == 0) {
            cin >> buf_shift;
        }
    }
    
    return 0;
}


