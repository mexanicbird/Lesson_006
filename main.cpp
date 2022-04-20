#include <iostream>

using namespace std;

/* task 001 */
void getInt () {
    int number;
    std::cout << "Enter a number: " << std::endl;
    cin >> number;
    if (!cin)
    {
        cout << "Input is not correct" << endl;
        cin.clear();
        fflush(stdin);
        getInt();
    } else {
        std::cout << "Enter a number: " << number << std::endl;
    }
}



/* task 002 */
std::ostream& endll(std::ostream& outStream)
{
    for (int i = 0; i < 2; i++) {
        outStream.put((outStream.widen('\n')));
    }
    outStream.flush();
    return outStream;
}



/* task 003, 004, 005*/
class GenericPlayer;
enum class Rank
{
    ACE = 1,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACEONE = ACE,
    last = KING
};

enum class Suit
{
    CLUBS = 1,
    DIAMONDS,
    HEARTS,
    SPADES,
    CLUBSFIRST = CLUBS,
    SPADESLAST = SPADES
};

class Card {
protected:
    Rank rank;
    Suit suit;
    bool isFaceUp;
public:
    Card(Rank r = Rank::ACE, Suit s = Suit::SPADES, bool ifu = true) {};
    void SetValue(Rank den, Suit suit) {};

    Rank GetRank() { return rank; };
    Suit GetSuit() { return suit; };
    void Flip() { isFaceUp = !isFaceUp; };
    int GetValue() const;
    friend std::ostream& operator<<(std::ostream& os, const Card& aCard);

};
std::ostream& operator<<(std::ostream& os, const Card& aCard);

class Hand {
protected:
    std::vector<Card> *сards;
public:
    Hand() {};
    virtual ~Hand() {};
    void Add(Card* pCard);
    void Clear();
    uint GetTotal() const;
};

class Deck : public Hand
{
protected:
    uint16_t numberOfCards = (int)Suit::SPADESLAST * (int)Rank::last;
    Card cards[(int)Suit::SPADESLAST][(int)Rank::last]{};
public:
    Deck() {};
    void Populate() {};
    void Shuffle() {};
    void Deal(Hand& aHand) {};
    void AddltionalCards(GenericPlayer& aGenerlcPlayer) {};
    Card GetCard(uint16_t number);
    bool CheckIsStayedCard(uint16_t number);
};

enum class Chip
{
    White	= 1,
    Red		= 5,
    Blue	= 10,
    Green	= 25,
    Black	= 100,
    Magenta	= 500,
    Orange	= 1000,
    count = 7
};

class ChipsOnHand
{
protected:
    Chip chips[(int)Chip::count]{};
public:
};

class GenericPlayer : public Hand
{
protected:
    std::string name;
public:
    GenericPlayer(const std::string& name = "") {};
    virtual ~GenericPlayer() = default;
    virtual bool IsHitting() const = 0;
    bool IsBoosted() const;
    void Bust() const {};
    friend std::ostream& operator<<(std::ostream& os, const GenericPlayer& aGenericPlayer);

};

std::ostream& operator<<(std::ostream& os, const GenericPlayer& aGenericPlayer);

class Player : public GenericPlayer
{
protected:
public:
    Player(const std::string& name = "") {};
    virtual ~Player() = default;
    virtual bool IsHitting() const override;
    void Win() const {};
    void Lose() const {};
    void Push() const {};
};

class House : public GenericPlayer
{
protected:
public:
    House(const std::string& name = "House") {};
    virtual ~House() = default;
    virtual bool IsHitting() const override;
    void FlipFirstCard() {};
};


class GameEntity
{
protected:
    std::string name;
public:
};

int main(int argc, const char** argv) {
    /* execution time control */
    double start_time =  clock();

    std::cout << "Lesson 006" << std::endl;
    std::cout << "Task 1" << std::endl;
    getInt();
    std::cout << "\n";

    std::cout << "Task 2" << std::endl;
    cout << "text up to space" << endll;
    cout << "text after space" << endl;
    std::cout << "\n";

    std::cout << "Task 3,4,5" << std::endl;
    std::cout << "\n";

    /* execution time control */
    double end_time = clock();
    double search_time = (end_time - start_time)/1000;
    std::cout << "Program execution time = " << search_time << " sec"<< std::endl;
    return 0;
}

/*

1. Создать программу, которая считывает целое число типа int. И поставить «защиту от дурака»:
если пользователь вводит что-то кроме одного целочисленного значения, нужно вывести сообщение об ошибке
и предложить ввести число еще раз. Пример неправильных введенных строк:
        rbtrb
        nj34njkn
        1n

2. Создать собственный манипулятор endll для стандартного потока вывода, который выводит два перевода строки
 и сбрасывает буфер.

3. Реализовать класс Player, который наследует от класса GenericPlayer. У этого класса будет 4 метода:

• virtual bool IsHitting() const - реализация чисто виртуальной функции базового класса. Метод спрашивает у
 пользователя, нужна ли ему еще одна карта и возвращает ответ пользователя в виде true или false.
• void Win() const- выводит на экран имя игрока и сообщение, что он выиграл.
• void Lose() const - выводит на экран имя игрока и сообщение, что он проиграл.
• void Push() const - выводит на экран имя игрока и сообщение, что он сыграл вничью.

4. Реализовать класс House, который представляет дилера. Этот класс наследует от класса GenericPlayer.
 У него есть 2 метода:
• virtual bool IsHitting() const - метод указывает, нужна ли дилеру еще одна карта. Если у дилера
 не больше 16 очков, то он берет еще одну карту.
• void FlipFirstCard() - метод переворачивает первую карту дилера.

5. Написать перегрузку оператора вывода для класса Card. Если карта перевернута рубашкой вверх (мы ее не видим),
 вывести ХХ, если мы ее видим, вывести масть и номинал карты. Также для класса GenericPlayer написать перегрузку
 оператора вывода, который должен отображать имя игрока и его карты, а также общую сумму очков его карт.

*/