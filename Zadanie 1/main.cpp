#include <stdio.h>
#include <iostream>
#include <array>

/*void test(std::string tekst)
{
    std::cout << "Tekst jest: " << tekst << "\n";

    tekst = "Zmiana";

    std::cout << "Tekst jest 2: " << tekst << "\n";
};*/

// RGBA 

// Wejscie danych - Oskar! 
// Przeliczanie (Dodawanie, odejmowanie - Greg
// , mnozenie i dzielenie) - Dawid



// Stringowy kalkulator
void sumNumbers(std::string *number1, std::string *number2, long long *result);
void subtractNumbers (std::string *number1 , std::string *number2 , long long *result);
void multiply (std::string *number1, std::string *number2, long long *result );
void divide (std::string &number1, std::string &number2, long long &result );

void input()
{
    long long result;

    std::string number1;
    std::string number2;
    char operation;
    
    std::cout << "Enter number 1: ";
    std::cin >> number1;
    std::cout << "\n";
    
    std::cout << "Enter number 2: ";
    std::cin >> number2;
    std::cout << "\n";
    
    bool running = 1;

    while (running)
    {   
        std::cout << "Pick operation (+ ,- ,* ,/): ";
        std::cin >> operation;
        std::cout << "\n";

        switch (operation)
        {
            case '+':
            {  
                sumNumbers(&number1, &number2, &result);
                running = false;
                break;
            }
            case '-':
            {
                subtractNumbers(&number1, &number2, &result);
                running = false; 
                break;
            }
            case '*':
            {    
                multiply(&number1, &number2, &result);
                running = false;
                break;
            }
            case '/':
            {
                divide(number1, number2, result);
                running = false;
                break;
            }
            default:
            {
                std::cout << "Wrong operation! \n";
                break;
            }
        }
    }
    
    std::cout << "Result is: " << result << "\n";    
}

void sumNumbers (std::string *number1 , std::string *number2, long long *result) 
{   

   int* strAsInt1 = (int*)&number1[0];
   int* strAsInt2 = (int*)&number2[0];
        
   *result = *strAsInt1 + *strAsInt2;
   
   std::cout << *result;
}

void subtractNumbers (std::string *number1 , std::string *number2, long long *result)
{
   
   int* strAsInt1 = (int*)&number1[0];
   int* strAsInt2 = (int*)&number2[0];
        
   *result = *strAsInt1 - *strAsInt2;
}


void multiply (std::string *number1 , std::string *number2, long long *result )
{
    int* StringAsInt = (int*)&number1[0];
    int* StringAsInt2 = (int*)&number2[0];
    
    *result = *StringAsInt * *StringAsInt2;
}

void divide (std::string &number1 , std::string &number2, long long &result )
{

    int* StringAsInt6 = (int*)&number1[0];
    int* StringAsInt5 = (int*)&number2[0];
    
    result = *StringAsInt6 / *StringAsInt5;   
    
}


int main()
{
    input();
    //std::string test1 = "aaa";
    //std::string test2 = "bbb";
    
    //subtractNumbers(test1, test2);

    /*
    int number = 1;
    char letter = 'A';
    float f = 1.0f;
    double d = 1.0f;
    bool b = true;
    
    int array[] = {10, 4, 1, 6, 19, 44, 2, 16, 9};

    int charint = letter;

    std::cout << "Numer A to : " << charint << "\n";
    
    std::string as = "ABCCCCCCDDSADSD";

    for (int i = 0; i < 10; i++)
    {
        test(as);
    }

    std::cout << "As is: " << as << "\n";




    char* letter2 = &letter;
    
    std::cout << "Letter is: " << letter << " adres " << *letter2 << "\n";
        
    char* letter3 = &as[0];

    void* smth = letter3;
    void* smth1 = letter3;
    void* smth2 = &d;
    
    int* stringAsInt = (int*)&as[0];

    std::cout << "Letter is: " << stringAsInt << " Value is: " << *stringAsInt << "\n";
    */
    return 0;
}

