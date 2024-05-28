#include <iostream>  
#include <queue>
using namespace std;

struct price
{
    int a, b;
};

int main()
{
    setlocale(LC_ALL, "rus");
    priority_queue <int, vector<int>, greater<int>> queue;
    cout << "Введите кол-во магазинов: ";
    int n; cin >> n;
    if (n < 1 && n >200000)
        return -2;

    cout << "Введите необходимое кол-во единиц товара: ";
    int k; cin >> k;
    if (k < 1 && k>100000)
        return -2;

    price* pric = new price[n];
    cout << "Введите цену и наценку в каждом магазине:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> pric[i].a;
        if (pric[i].a < 1 && pric[i].a > 1000)
            return -3;
        cin >> pric[i].b;
        if (pric[i].b < 1 && pric[i].b > 1000)
            return -3;
    }

    for (int i = 0; i < n; i++)
        queue.push(pric[i].a);

    int answer = 0;
    cout << "Цена каждой единицы товара:" << endl;

    for (int j = 0; j < k; j++)
    {
        answer += queue.top();
        int temp = queue.top();
        queue.pop();
        for (int i = 0; i < n; i++)
        {
            if (temp == pric[i].a)
            {
                pric[i].a += pric[i].b;
                queue.push(pric[i].a);
            }
        }
    }
    cout << endl << endl;

    cout << answer << endl << endl;

    //del_tree(top);
}
