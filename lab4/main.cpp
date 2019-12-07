#include <iostream>
#include "human.h"
#include <iterator>
#include <algorithm> // for std::inplace_merge
#include <functional> // for std::less
using namespace std;

template <class Item>
void quickSort(Item *arr, int left, int right) {
      int i = left, j = right;
      Item tmp;
      Item pivot = arr[(left + right) / 2];
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      }
      if (left < j)
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);
}

template <class T>
void compexch(T& a, T&b)
{
    if (b < a){
        T buff = b;
        b = a;
        a =buff;

    }
}
void show(human arr[], int size){
    for(int i =0; i < size; i++) {
        cout << arr[i].getValue() << "  ";
    }
}

template<typename T>//алгоритм Боуза-Нельсона
T* merge_sort(T *up, T *down, unsigned int left, unsigned int right)
{
    if (left == right)
    {
        down[left] = up[left];
        return down;
    }

    unsigned int middle = (left + right) / 2;

    // разделяй и сортируй
    T *l_buff = merge_sort(up, down, left, middle);
    T *r_buff = merge_sort(up, down, middle + 1, right);

    // слияние двух отсортированных половин
    T *target = (l_buff == up) ? down : up;

    unsigned int l_cur = left, r_cur = middle + 1;
    for (unsigned int i = left; i <= right; i++)
    {
        if (l_cur <= middle && r_cur <= right)
        {
            if (l_buff[l_cur] < r_buff[r_cur])
            {
                target[i] = l_buff[l_cur];
                l_cur++;
            }
            else
            {
                target[i] = r_buff[r_cur];
                r_cur++;
            }
        }
        else if (l_cur <= middle)
        {
            target[i] = l_buff[l_cur];
            l_cur++;
        }
        else
        {
            target[i] = r_buff[r_cur];
            r_cur++;
        }
    }
    return target;
}

int main(int argc, char *argv[])
{
    {
        human arr[4] = {5,1,8,4};
        human buff[4];
        human *k= merge_sort(arr, buff, 0, 3);
        show(k, 4);
        cout << endl;
    }
    {
        human arr[4] = {2,1,8,4};
        quickSort(arr, 0, 3);
        show(arr, 4);

        cout << endl;
    }
}
