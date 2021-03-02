#include <iostream>
#include <tuple>

template <typename First>
void print(First& first)
{
    std::cout << first << std::endl;
}

template <typename First, typename... Rest>
void print(First& first, Rest&... rest)
{
    std::cout << first << std::endl;
    print(rest...);
}

template <typename... T, std::size_t... Is>
void printOrder(std::tuple<T...>& in_tuple, std::index_sequence<Is...>)
{
    print(std::get<Is>(in_tuple)...);
}

int main(int argc, char* argv[])
{
    std::tuple<int, char, float> test{1, 'a', 2.0};
    printOrder(test, std::integer_sequence<size_t, 0, 1, 2>{});
    printOrder(test, std::integer_sequence<size_t, 2, 1, 0>{});
    printOrder(test, std::integer_sequence<size_t, 2, 2, 2>{});
}
