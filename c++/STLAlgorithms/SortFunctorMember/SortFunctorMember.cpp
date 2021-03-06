#include <iostream>
#include <vector>
#include <algorithm>

struct Test
{
  int a,b;
};

struct SortFunctor
{
  bool operator()(const Test &T1, const Test &T2)
  {
    std::cout << "a: " << a << std::endl;
    return(T1.a < T2.a);
  }
  float a;
};

//////////////////////////
int main (int argc, char *argv[]) 
{
  srand(time(NULL));

  std::vector<Test> testVector;
  Test t;
  t.a = rand()%50;
  t.b = rand()%50;
  testVector.push_back(t);
  
  t.a = rand()%50;
  t.b = rand()%50;
  testVector.push_back(t);
  
  t.a = rand()%50;
  t.b = rand()%50;
  testVector.push_back(t);

  std::cout << "unsorted:" << std::endl;
  for(unsigned int i = 0; i < testVector.size(); i++)
  {
    std::cout << testVector[i].a << " " << testVector[i].b << std::endl;
  }

  SortFunctor test;
  test.a = 3.1f;
  std::sort(testVector.begin(), testVector.end(), test);
  std::cout << "sorted:" << std::endl;
  for(unsigned int i = 0; i < testVector.size(); i++)
  {
    std::cout << testVector[i].a << " " << testVector[i].b << std::endl;
  }
  return 0;
}
