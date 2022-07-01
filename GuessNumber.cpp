#include <iostream>
#include <ctime>
#include <vector>

double getRandom()
{
    int max = 999;
    int min = 100;
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

std::vector<int> numToVector(int num)
{
    std::vector<int> vec;
    vec.push_back(num / 100);
    vec.push_back((num % 100) / 10);
    vec.push_back(num % 10);
    return vec;
}

int input()
{
    int x;
    do
    {
        std::cin >> x;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Неверный ввод! Повторите попытку.\nВаш вариант: ";
        }
    } while (std::cin.fail() || x < 100 || x > 999);
    return x;
}

bool again()
{
    char answer;
    do
    {
        std::cout << "Сыграть еще раз (1 - да/ 2 - нет)? ";
        std::cin >> answer;
        if (answer == '1')
            return true;
        if (answer == '2')
            return false;
    } while (answer != '1' && answer != '2');
}

bool game(std::vector<int> numComputer)
{
    std::vector<int> numPlayer;
    int guesses = 0;
    for (int k = 1; k <= 10; k++)
    {
        int rightnum = 0;
        int rightplace = 0;
        std::cout << "Ваш вариант: ";
        int guess = input();
        numPlayer = numToVector(guess);
        guesses++;
       
        if (numComputer == numPlayer)
        {
            std::cout << "Вы угадали!\nКоличество попыток: " << guesses << std::endl;
            return true;
        }

        for (int i = 0; i < numComputer.size(); ++i)
        {
            for (int j = 0; j < numPlayer.size(); ++j)
            {
                if (numComputer[i] == numPlayer[j])
                {
                    ++rightnum;
                    break;
                }   
            }
            if (numComputer[i] == numPlayer[i])
            {
                ++rightplace;
            }
        }
        std::cout <<"Угадано: " << rightnum <<". На своих местах: " << rightplace<<".\n";
    }
    return false;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    srand(static_cast<unsigned int>(time(0)));
    rand();
    do
    {
        std::cout << "Компьютер загадал случайное 3-х значное число. Вы должны его отгадать. "
            "После очередного числа вам будет сообщено, сколько цифр угадано"
            " и сколько из них находится на своих местах. У вас 10 попыток.\n";
        int number = getRandom();
        std::vector <int> numComputer = numToVector(number);
        std::cout << number;
        if (!game(numComputer))
            std::cout << "Извините вы не угадали!\nЗагаданное число: " << number << ".\n";
    } while (again());
 
    return 0;
};