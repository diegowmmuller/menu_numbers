#include <iostream>
#include <list>


using namespace std;

int main() {

    list<int> integer_list{};
    bool flag{true};
    char choice{};
    char choice_upper{};

    do {
        cout << "=== MENU ===" << endl;
        cout << endl;
        cout << "P - print numbers" << endl;
        cout << "A - add a number to the list" << endl;
        cout << "M - display the mean of the numbers" << endl;
        cout << "S - display the smallest number" << endl;
        cout << "L - display the largest number" << endl;
        cout << "Q - quit" << endl;
        cout << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        choice_upper = toupper(static_cast<unsigned char>(choice));
        switch (choice_upper) {

            case 'P': {
                cout << "Numbers: " << endl;
                for (const int num: integer_list) {
                    cout << num << endl;
                }
                cout << endl;
                break;
            }

            case 'A': {
                cout << endl;
                cout << "Type the number: ";
                int number{};
                cin >> number;
                integer_list.push_back(number);
                cout << "Number inserted successfully" << endl;
                cout << endl;
                break;
            }

            case 'M': {
                if (integer_list.empty()) {
                    cout << "Unable to calculate mean - list is empty" << endl;
                    break;
                }

                double sum{};
                for (int num: integer_list) {
                    sum += static_cast<double>(num);
                }
                const double mean = sum / integer_list.size();
                cout << "mean of the list: " << mean << endl;
                break;
            }

            case 'S': {
                if (integer_list.empty()) {
                    cout << "Unable to calculate mean - list is empty" << endl;
                    break;
                }

                int smallest{integer_list.front()};
                for (int num : integer_list) {
                    if (num < smallest) {
                        smallest = num;
                    }
                }
                cout << "The smallest number of the list is: " << smallest << endl;
                break;
            }

            case 'L': {
                if (integer_list.empty()) {
                    cout << "Unable to calculate mean - list is empty" << endl;
                    break;
                }

                int largest{integer_list.front()};
                for (int num : integer_list) {
                    if (num > largest) {
                        largest = num;
                    }
                }
                cout << "The largest number of the list is: " << largest << endl;
                break;
            }

            case 'Q': {
                flag = false;
                break;
            }

            default: {
                cout << "Unknown selection, please try again" << endl;
                cout << endl;
                break;
            }
        }


    } while (flag);

    return 0;
}