#include <iostream>
#include <algorithm>
using namespace std;

void outputArray(int* array, int size)
{
  for (int i = 0; i < size; ++i) { cout << array[i] << " "; }
}

int main ()
{
  int myints[] = { 1, 2, 3, 4, 5 };
  const int size = sizeof(myints);

  cout << "The 5! possible permutations with 5 elements:\n";

  sort (myints, myints + size);

  bool hasMorePermutations = true;
  do
  {
    outputArray(myints, size);
    hasMorePermutations = next_permutation(myints, myints + size);
  }
  while (hasMorePermutations);

  return 0;
}
