#include <iostream>
#include <string>

int compare(const void *i, const void *j)
  { return strcmp(*(char **)i, *(char **)j); }

int main()
{
    const int Nmax = 100;
    const int Mmax = 100;
    int i;
    char* a[Nmax];
    char buf[Mmax];

    //Type each string + enter, then press ctrl-d to sort pointers
    for (i = 0; i < Nmax; i++)
      {
        if (!(std::cin >> buf))
            break;
        a[i] = new char[std::strlen(buf) + 1];
        std::strcpy(a[i],buf);
        std::cin.clear();
      }
    std::cout<<"========================"<<std::endl;
    qsort(a, i, sizeof(char*), compare);
    for (int j = 0; j  < i; j++){
      std::cout << a[j] << std::endl;
      delete [] a[j];
    }
}
