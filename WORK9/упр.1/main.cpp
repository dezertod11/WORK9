#include <iostream>
#include <functional>
#include <array>
#include <algorithm>
#include <vector>
#include <typeinfo>

template <class T, std::size_t N>
void sort(T(&array)[N], std::function<bool(T*, T*)>);
template <class T, int N>
void quicksort(T(&array)[N], T *l, T* r, std::function<bool(T*, T*)> comp);
template <class T>
bool comp(T *l, T* r);

template <class T, std::size_t N>
void sort(T(&array)[N], std::function<bool(T*, T*)> comp ) {
    T* l{ array };
    T* r{ array + (N - 1) };
    quicksort<T, N>(array, l, r, comp);

}

template <class T, int N>
void quicksort(T(&array)[N], T *l, T *r, std::function<bool(T*, T*)> comp) {

    if (r - l <= 1) return;
    T* z = (l + (r - l) / 2);
    T* ll = l;
    T* rr = r;
    while (ll <= rr) { //  не получается заменить на функцию comp. Выдаёт std::bad_function_call ((
        while (*ll < *z) ll++;
        while (*rr > *z) rr--;
        if (ll <= rr) {
            std::swap(*ll, *rr);
            ll++;
            rr--;
        }
    }
    quicksort<T,N>(array, l, rr + 1, comp);
    quicksort<T,N>(array, ll, r, comp);
}

template <class T>
bool comp(T* l, T* r) {
    return l < r;
}

int main() {
    std::function<bool(int*, int*)> comp1 = comp1;
    int array1[] = { 51, 2, 10, 15, 30, 20};
    sort<int, 6>(array1,  comp1 );
    std::cout << std::endl;
    for (auto elem: array1) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    std::function<bool(char*, char*)> comp2 = comp2;
    char array2[] = { 'b', 'a', 'c', 'x', 'z'};
    sort<char, 5>(array2,  comp2 );
    std::cout << std::endl;
    for (auto elem: array2) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    std::function<bool(std::string*, std::string*)> comp3 = comp3;
    std::string array3[] = { "bb", "aa", "cc"};
    sort<std::string, 3>(array3,  comp3 );
    std::cout << std::endl;
    for (auto elem: array3) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
