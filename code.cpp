#include <iostream>
#include <numeric>
using namespace std;
class shop
{
protected:
    int limit, b[100], sum;

public:
    void set_data(void);
    void addition(void);
    void get_data(void);
};
void shop ::set_data(void)
{
    cout << "Enter the total numbers of the items:";
    cin >> limit;
    for (int i = 0; i < limit; i++)
    {
        cout << "Enter the price for the item #[" << i + 1 << "]:";
        cin >> b[i];
    }
}
void shop ::addition(void)
{
    cout << "=>The total price of the items are as following:";
    cout << sum << endl;
}
void shop ::get_data(void)
{
    sum = 0;
    sum = accumulate(b, b + limit, sum);
}
class customer : public shop
{
protected:
    string g, pre, nu;

protected:
    char q;

protected:
    int amount, temp;

public:
    void start(void);
    void feedback(void);
    // void feedback_out(void);
    void balance(void);
    void end(void);
};
void customer ::balance(void)
{
    cout << "Enter the total amount form the customer:";
    cin >> amount;
    cout << "=>The balance amount of the customer are as following:";
    cout << amount - sum << endl;
}
void customer ::feedback(void)
{
    cout << "[FEED_BACK]=>Do you have any query(y/n)?:";
    cin >> q;
    switch (q)
    {
    case 'y':
        cout << "Enter your feed-back:" << endl;
        cin >> nu;
        break;
    case 'n':
        cout << "Okay:" << endl;
        cin >> nu;
        break;

    default:
        break;
    }
}
void customer ::start(void)
{
    cout << "Enter the cusotmers name:";
    cin >> g;
}
void customer ::end(void)
{
    cout << "Thanks\t" << g << "\tfor shopping & feed-back" << endl;
}
int main()
{
    customer *john = new customer();
    john->start();
    john->set_data();
    john->get_data();
    john->addition();
    john->balance();
    john->feedback();
    john->end();
    delete john;
    return 0;
}