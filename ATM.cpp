#include <iostream>
#include <vector>
using namespace std;
class ATM
{
private:
    vector<int> user_id;
    vector<int> password;

public:
    void get_details()
    {
        int id, pass;
        cout << "Enter user id: ";
        cin >> id;
        user_id.push_back(id);

        cout << "Enter your password: ";
        cin >> pass;
        password.push_back(pass);
        cout << "\n Thank You! Your account has been created! \n";
    }

    int login(int id, int pass)
    {
        for (int i = 0; i < user_id.size(); ++i)
        {
            if (user_id[i] == id && password[i] == pass)
            {
                return 1; // true
            }
        }
        return 0; // false
    }
};

class login_success
{
private:
    float deposite_money, withdraw_money, Request_balance;

public:
    login_success()
    {
        deposite_money = 0;
        withdraw_money = 0;
        Request_balance = 0;
    }

    void choose_func()
    {
        char loop;
        do
        {
            char choice;
            cout << "Press 'd' for deposit money" << endl;
            cout << "Press 'w' for withdraw money" << endl;
            cout << "Press 'r' for request balance" << endl;
            cin >> choice;

            if (choice == 'd')
            {
                int money;
                cout << "Enter amount you want to deposit: ";
                cin >> money;
                deposite_money += money;
                Request_balance = deposite_money;
            }
            else if (choice == 'w')
            {
                int money;
                cout << "Enter amount you want to withdraw: ";
                cin >> money;
                if (Request_balance > money)
                {
                    cout << " amount credited successfully ... \n";
                }
                else
                {
                    cout << " insufficient balance ... \n";
                }
                withdraw_money += money;
                deposite_money -= money;
                Request_balance = deposite_money;
            }
            else if (choice == 'r')
            {
                cout << "Your current balance is: " << Request_balance << endl;
            }

            cout << "Do you want to continue? (y/n): ";
            cin >> loop;
        } while (loop != 'n');
    }
};

int main()
{
    char loop_control;
    ATM user1;
    login_success obj1;
    do
    {
        int choice, correct;
        cout << "Press 1 to create a bank account." << endl;
        cout << "Press 2 to login using id and password." << endl;
        cout << "Press 'n' to exit, any other key to continue: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            user1.get_details();
            break;
        case 2:
            int id, pass;
            cout << "Please enter your id and password: " << endl;
            cin >> id >> pass;
            correct = user1.login(id, pass);
            if (correct == 1)
            {
                cout << "Successfully logged in. Please proceed." << endl;
                obj1.choose_func();
            }
            else
            {
                cout << "Something went wrong. Please login again with correct id and password." << endl;
            }
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }

        cout << "Do you want to continue? (y/n): ";
        cin >> loop_control;

    } while (loop_control != 'n');

    return 0;
}
