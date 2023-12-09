#include <iostream>

extern int value;

//const int a = 10;
static int b = 10;
extern int c = 10;
volatile int d = 10;
//inline int e = 10;

volatile int test(int abc)
{
  int value = 5;

  return abc + value;
};

printf("Hello world \n");
class Test 
{
    public:
    static const int a = 5;
};

class Base
{
  public: 

  void ShowString(){ std::cout << "Base class \n"; };
  
  protected:

  void ShowStringProt(){ std::cout << "Base class prot \n"; };

  private:

  void ShowStringPriv(){ std::cout << "Base class priv \n"; };
};

class Top : public Base
{
  public:

  void ShowStringTop()
  {
    ShowString();

    ShowStringProt(); 
  };
};

class Middle : protected Base
{
  public:

  void ShowStringMiddle()
  {
    ShowString();

    ShowStringProt();
  };
};

class Bot : private Base
{

};

class Bot2 : public Middle
{
  public:

  void Bot2String()
  {
    ShowString();

    ShowStringProt();
  }
};

class One
{
  public:
  One() 
  { 
    std::cout << "Cunst one \n";
  };
};

class Two : public One
{
  public:
  Two() { std::cout << "Const two \n"; };

  private:
  One test;
};

int main(int argc, char* argv)
{

  Base objBase;
  objBase.ShowString();

  Two objTwo;

  /*
    int normal = 10;
    normal = 99;

    const int constInt = 10;
    //constInt = 20;

    test(normal);

    //normal += 5;


    std::cout << value << std::endl;

    Test objTest;
*/
    return 0;
}