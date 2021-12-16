#include <iostream>
#include <string>
#include <tuple>
#include <memory>
#include <vector>

template<template<typename...> class W, typename T> struct TupleWrapper;

template<template<typename...> class W, typename... Ts>
struct TupleWrapper<W, std::tuple<Ts...>>
{
    using type = std::tuple<W<Ts>...>;
};

template<template<typename...> class W, typename T>
using TupleWrapperT = typename TupleWrapper<W,T>::type;

int main()
{
    TupleWrapperT<std::unique_ptr, std::tuple<int, std::vector<int>, double>>::nothing;
    TupleWrapperT<std::vector, std::tuple<int, std::vector<int>, double>>::nothing;
}
