#include <iostream>

struct point {
    int x, y;
    point (int in_x, int in_y)
    {
        x = in_x;
        y = in_y;
    };
};



class OurClass {
public:
    int a;

    void SetC(int in_c)
    {
        c = in_c;
    }

    int GetC()
    {
        return c;
    }

protected:

private:
    int c;
};

point* functionScopePtr()
{
    point* pointa = new point(15, 20);

    return pointa;
}

int* functionScope()
{
    point pointa(20, 25);

    return &pointa.x;
}

int main()
{
    //int b = 10;

    //point pointb(10, 10);
    //OurClass class1;

    //class1.SetC(b);
    //std::cout << class1.GetC() << "\n";


    //std::cout << functionScopePtr()->x << "\n";

    //int *value = functionScope();

    //std::cout << *value << "\n";

    //std::cout << value << "\n";
/*
    obj1.functionA();
    obj1.a;
    obj2.functionB();
    obj2.a;
*/
    return 0;
}