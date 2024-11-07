#include <bits/stdc++.h>
using namespace std;

int partition(int l, int h, vector<int> &a)
{
   int pivot = a[l];

   int i = l;
   int j = h;

   while (i < j)
   {
      do
      {
         i++;
      } while (a[i] <= pivot);

      while (a[j] > pivot)
      {
         j--;
      }

      if (i < j)
      {
         swap(a[i], a[j]);
      }
   }
   swap(a[l], a[j]);
   return j;
}

void quickSort(int l, int h, vector<int> &a)
{
   if (l < h)
   {
      int j = partition(l, h, a);
      quickSort(l, j, a);
      quickSort(j + 1, h, a);
   }
}

int randomPartition(int l, int h, vector<int> &a)
{
   int pivotIndex = l + rand() % (h - l + 1);
   swap(a[l], a[pivotIndex]);

   int pivot = a[l];
   int i = l;
   int j = h;

   while (i < j)
   {
      do
      {
         i++;
      } while (a[i] <= pivot);

      while (a[j] > pivot)
      {
         j--;
      }

      if (i < j)
      {
         swap(a[i], a[j]);
      }
   }
   swap(a[l], a[j]);
   return j;
}

void randomQuickSort(int l, int h, vector<int> &a)
{
   if (l < h)
   {
      int j = randomPartition(l, h, a);
      randomQuickSort(l, j, a);
      randomQuickSort(j + 1, h, a);
   }
}


int main()
{

   int size;
   cout << "Enter size of array: ";
   cin >> size;

   vector<int> v(size);
   cout << "\nEnter data:\n";
   for (int i = 0; i < size; i++)
   {
      cout << "\tarr[" << i << "] = ";
      cin >> v[i];
   }

   randomQuickSort(0, size - 1, v);

   cout << "\n\nSorted array: ";
   for (auto i : v)
   {
      cout << i << " ";
   }
   cout << "\nx-------------x-------------------x-----------------x\n\n";
   return 0;
}
