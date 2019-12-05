#include <iostream>
#include "human.h"
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

template <class Item>
  void batchersort(Item a[], int l, int r)
 { int N = r-l+1;
   for (int p = 1; p < N; p += p)
        for (int k = p; k > 0; k /= 2)
            for (int j = k%p; j+k < N; j += (k+k))
                for (int i = 0; i < N-j-k; i++)
                    if ((j+i)/(p+p) == (j+i+k)/(p+p))
                        compexch(a[l+j+i], a[l+j+i+k]);
 }


void show(human arr[], int size){
    for(int i =0; i < size; i++) {
        cout << arr[i].getValue() << "  ";
    }
    cout << endl;
}

int main(int argc, char *argv[])
{
    {
        human arr[16] = {2,1,8,4,5,3,10,7,9,0,11,10,14,13,12,15};
        batchersort(arr, 0, 15);
        show(arr, 16);
        cout << endl;
    }
    {
        human arr[16] = {2,1,8,4,5,3,10,7,9,0,11,10,14,13,12,15};
        quickSort(arr, 0, 15);
        show(arr, 16);
        cout << endl;
    }
}
