#include <iostream>
#include <stdexcept>
#include "Test.h"
#include "Queue.h"
#include "Node.h"

void Test::run(){
  Queue myQueue;
  //testPeek(myQueue);
//}

//void Test::testPeek(int myQueue){
  try{
    myQueue.peekFront();
  }
  catch(std::runtime_error& rte)
  {
    std::cout << "\nERROR: ";
    std::cout << rte.what() << "\n\n";
  }
}
