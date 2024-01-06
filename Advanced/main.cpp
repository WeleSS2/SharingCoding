#include <iostream>
#include <ranges>
#include <vector>
#include <list>
#include <unordered_map>
#include <algorithm>
#include <future>
#include <mutex>
#include <chrono>
#include <random>
#include <format>
#include <string>
#include <list>
#include <deque>
#include <array>

std::mutex locker;

void count(std::vector<int> &data, int &sum)
{
    int tempsum = 0;
    for(auto i : data)
    {
        if ( i % 2 == 0)
        {
            tempsum++;
        }
    }

    std::lock_guard<std::mutex> lock(locker);
    std::cout << "Addd " << tempsum << " to sum " << sum << "\n";
    sum += tempsum;
};

class Test
{
public:
    Test(){};

    //template <typename Tc, typename... Args>
    //Test(Tc &_arg, Args&... _args) : arg(_arg) {};
    ~Test(){};

    template<typename T>
    void call(T _arg){
        std::cout << _arg << std::endl;
    }
};

void fillVector(std::vector<int> &vec)
{
    std::random_device rd;

    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> range(1, 100000);

    for (auto &i : vec)
    {
        i = range(gen);
    }
}

void asyncWork(std::vector<int> &vec, int &sum)
{
    fillVector(vec);
    count(vec, sum);
}

std::string timeToString(const std::chrono::system_clock::time_point &time)
{
    std::string timeStr = std::format("{:%Y %m %d %T}", time);
    return timeStr;
}

struct mobData {
    int hp;
    int attack;
    std::string test = "Bla bla";
};

class mob
{
public:
    mob();
    void killMe();

private:
    mobData _mobData;
};

void spawnMob()
{
    mobData obj;
    obj.hp = 200;
}

// auto doubleit = [](int &val) { val *= 2; };
// auto doubleit = [&](int &val) { val *= 2; };
// auto doubleit = [=](int &val) { val *= 2; };
int doubleItFunc(int &val)
{
    return val *= 2;
};

// Work section declarations

int main(int argc, char** argv)
{
    // Using array with labda
    std::vector<int> tmp = {10, 20, 30, 40};
    std::unordered_map<int, mob> map;
    
    auto doubleit = [](int &val) { val *= 2; };
    auto removeit = [](int &val) { std::cout << val << std::endl; };

    // For each loop with lambda
    std::for_each(tmp.begin(), tmp.end(), doubleit);
    
    std::for_each(tmp.begin(), tmp.end(), removeit);
    
    // Using views

    auto const ints = {0, 1, 2, 3, 4, 5};
    auto even = [](int i) { return 0 == i % 2; };
    auto square = [](int i) { return i * i; };
    
    // the "pipe" syntax of composing the views
    for (int i : ints | std::views::filter(even) | std::views::transform(square))
        std::cout << i << ' ';
    
    std::cout << '\n';

    // Using template to do something universal (basics of generic)
    Test obj;
    std::string huh = "HEH";
    int val = 15;
    mobData assad;
    obj.call(huh);
    obj.call(val);



    // Using async to make asynchronous operation which will speed up it a lot
    const auto time{std::chrono::system_clock::now()};
    int sum = 0;
    std::vector<int> vec1(30000000);
    std::vector<int> vec2(30000000);
    std::vector<int> vec3(30000000);
    std::vector<int> vec4(30000000);

    fillVector(vec1);
    fillVector(vec2);
    fillVector(vec3);
    fillVector(vec4);

    count(vec1, sum);
    count(vec2, sum);
    count(vec3, sum);
    count(vec4, sum);
    const auto timeend{std::chrono::system_clock::now()};

    std::cout << "\n" << timeToString(time) << "\n" << timeToString(timeend) << std::endl;
    std::cout << "\nSum is " << sum << "\n";
    sum = 0;

    const auto time2{std::chrono::system_clock::now()};
    auto future1 = std::async(std::launch::async, asyncWork, std::ref(vec1), std::ref(sum));
    auto future2 = std::async(std::launch::async, asyncWork, std::ref(vec2), std::ref(sum));
    auto future3 = std::async(std::launch::async, asyncWork, std::ref(vec3), std::ref(sum));
    auto future4 = std::async(std::launch::async, asyncWork, std::ref(vec4), std::ref(sum));
    

    future1.get();
    future2.get();
    future3.get();
    future4.get();
    const auto timeend2{std::chrono::system_clock::now()};

    std::cout << "\n" << timeToString(time2) << "\n" << timeToString(timeend2) << std::endl;
    std::cout << "\nSum is " << sum << "\n";

    return 0;
}