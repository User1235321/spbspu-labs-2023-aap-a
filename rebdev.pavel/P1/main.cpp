#include <iostream>

int main()
{
  int * arrOfElements = new int[3];
  
  for(int i = 0; i < 3; ++i)
  {
    std::cin >> arrOfElements[i];
    if (std::cin.fail() || (arrOfElements[i] == 0))
    {
      std::cout << "0\n";
      return 1;
    }
  }

  int counter = 0;
  while (std::cin.good() && (arrOfElements[2] !=0))
  {
    counter += (arrOfElements[2] < arrOfElements[1]) * (arrOfElements[1] < arrOfElements[0]);
    arrOfElements[0] = arrOfElements[1];
    arrOfElements[1] = arrOfElements[2];
    std::cin >> arrOfElements[2];
  }
  
  if(std::cin.good())
  { 
    std::cout << counter << '\n';
    return 0;
  }
  else
  {
    std::cout << "0\n";
    return 1;
  }
}
