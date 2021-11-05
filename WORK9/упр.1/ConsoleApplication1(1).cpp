#include <iostream>
#include <functional> 
#include <array>
#include <algorithm>
#include <vector> 
#include <typeinfo>

template <class T, std::size_t N>
void sort(T(&array)[N], std::function<bool(T*, T*)>);
template <class T, int N>
void quicksort(T *l, T* r, std::function<bool(T*, T*)> comp);
template <class T>
bool comp(T *l, T* r);

template <class T, std::size_t N>
void sort(T(&array)[N], std::function<bool(T*, T*)> comp ) {
	T l{ array[0] };
	T r{ array[N - 1] };
	quicksort<T, N>(l, r, comp);

}

template <class T, int N>
void quicksort(T l, T r, std::function<bool(T*, T*)> comp) {
	if (comp) {
		if (r - l <= 1) return;
		T z = (l + (r - l) / 2);
		T* ll = l, * rr = r - 1;
		while (ll <= rr) {
			while (*ll < z) ll++;
			while (*rr > z) rr--;
			if (ll <= rr) {
				std::swap(*ll, *rr);
				ll++;
				rr--;
			}
		}
		if (l < rr) quicksort(l, rr + 1);
		if (ll < r) quicksort(ll, r);
	}
	else {
		if (r - l <= 1) return;
		int z = *(l + (r - l) / 2);
		int* ll = l, * rr = r - 1;
		while (ll <= rr) {
			while (*ll < z) ll++;
			while (*rr > z) rr--;
			if (ll <= rr) {
				std::swap(*ll, *rr);
				ll++;
				rr--;
			}
		}
		if (l < rr) quicksort<T, N, comp>(l, rr + 1);
		if (ll < r) quicksort<T, N, comp>(ll, r);
	}
}

template <class T>
bool comp(T* l, T* r) {
	return l < r;
}

int main() {
	int a = 1.2;
	int array[] = { 8, 6, 4, 1 };
	std::function<bool(int*, int*)> comp = comp;
	sort<int, 4>(array,  comp );
	return 0;
}
