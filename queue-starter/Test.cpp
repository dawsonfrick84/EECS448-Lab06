/*
*	@file Test.cpp
*	@author Dawson Frick
*	@date 2019.11.11
*/

#include <iostream>
#include <stdexcept>
#include "Test.h"
#include "Queue.h"
#include "Node.h"

void Test::run(){
  testEmpty();
  testEnqueue();
  testDequeue();
  testPeek();
  //testDestructor();
}

void Test::testEmpty(){
  std::cout << "1) New queue is empty:";
  Queue myQueue;
  if (myQueue.isEmpty()==true){
    std::cout << "\tPASSED" << '\n';
  }
  else{
    std::cout << "\tFAILED" << '\n';
  }
  myQueue.~Queue();
}

void Test::testEnqueue(){
  try{
    std::cout << "2) Enqueue adds to empty queue:";
    Queue myQueue;
    myQueue.enqueue(1);
    std::cout << "\tPASSED" << '\n';
    myQueue.~Queue();
  }
  catch(std::runtime_error& rte)
  {
    std::cout << "\tFAILED:\n\t";
    std::cout << rte.what() << "\n";
  }
  try{
    std::cout << "3) Enqueue adds to queue with one node:";
    Queue myQueue1;
    myQueue1.enqueue(1);
    myQueue1.enqueue(2);
    std::cout << "\tPASSED" << '\n';
    myQueue1.~Queue();
  }
  catch(std::runtime_error& rte)
  {
    std::cout << "\tFAILED:\n\t";
    std::cout << rte.what() << "\n";
  }
  try{
    std::cout << "4) Queue with values in it is non-empty:";
    Queue myQueue2;
    myQueue2.enqueue(1);
    if (myQueue2.isEmpty()==false){
      std::cout << "\tPASSED" << '\n';
    }
    else{
      std::cout << "\tFAILED" << '\n';
    }
    myQueue2.~Queue();
  }
  catch(std::runtime_error& rte)
  {
    std::cout << "\nFAILED:\n\t";
    std::cout << rte.what() << "\n\n";
  }
}

void Test::testDequeue(){
  try{
    std::cout << "5) Dequeue throws error if queue is empty: ";
    Queue myQueue;
    myQueue.dequeue();
    std::cout << "\tFAILED" << '\n';
    myQueue.~Queue();
  }
  catch(std::runtime_error& rte)
  {
    std::cout << "\tPASSED" << '\n';
  }
  try{
    std::cout << "6) Dequeue can remove a node from the queue:";
    Queue myQueue1;
    myQueue1.enqueue(1);
    myQueue1.dequeue();
    if(myQueue1.isEmpty()){
      std::cout << "\tPASSED" << '\n';
    }
    myQueue1.~Queue();
  }
  catch(std::runtime_error& rte)
  {
    std::cout << "\nFAILED:\n\t";
    std::cout << rte.what() << "\n\n";
  }
}

void Test::testPeek(){
  try{
    std::cout << "7) PeekFront cannot get value from empty queue:";
    Queue myQueue;
    int front=myQueue.peekFront();
    std::cout << "FAILED" << '\n';
      myQueue.~Queue();
  }
  catch(std::runtime_error& rte){
    std::cout << "\tPASSED \n";
  }

  try{
    std::cout << "8) PeekFront shows correct value after one enqueue:";
    Queue myQueue1;
    myQueue1.enqueue(1);
    int front=myQueue1.peekFront();
    if (front==1) {
      std::cout << "\tPASSED" << '\n';
    }
    else{
      std::cout << "\tFAILED\n\tFront is not the correct value" << '\n';
    }
      myQueue1.~Queue();
  }
  catch(std::runtime_error& rte){
    std::cout << "\nFAILED:\n\t";
    std::cout << rte.what() << "\n\n";
  }

  try{
    std::cout << "9) PeekFront shows correct value after multiple enqueues:";
    Queue myQueue2;
    myQueue2.enqueue(1);
    myQueue2.enqueue(2);
    myQueue2.enqueue(3);
    int front=myQueue2.peekFront();
    if (front==1) {
      std::cout << "\tPASSED" << '\n';
    }
    else if(front==3){
      std::cout << "\tFAILED:\n\tFront is not the correct value." << '\n';
      std::cout << "\tPeakFront shows the back" << '\n';
    }
    else{
      std::cout << "\tFAILED:\n\tFront is not the correct value." << '\n';
      std::cout << "\tPeek Front returns unknown value" << '\n';
    }
      myQueue2.~Queue();
  }
  catch(std::runtime_error& rte)
  {
    std::cout << "\nFAILED:\n\t";
    std::cout << rte.what() << "\n\n";
  }

  try{
    std::cout << "10) PeekFront shows correct value after dequeued:";
    Queue myQueue3;
    myQueue3.enqueue(1);
    myQueue3.enqueue(2);
    myQueue3.enqueue(3);
    myQueue3.enqueue(4);
    myQueue3.dequeue();
    int front=myQueue3.peekFront();
    if (front==1) {
      std::cout << "\tFAILED:\n\tFront was not removed" << '\n';
    }
    else if (front==2){
      std::cout << "\tPASSED\n";
    }
    else if (front==3){
      std::cout << "\tFAILED:\n\tFront is not the correct value." << '\n';
      std::cout << "\tDequeue removes from the back" << '\n';
    }
    else if (front==4){
      std::cout << "\tFAILED:\n\tFront is not the correct value." << '\n';
      std::cout << "\tEnqueue adds to front" << '\n';
    }
      myQueue3.~Queue();
  }
  catch(std::runtime_error& rte)
  {
    std::cout << "\nFAILED:\n\t";
    std::cout << rte.what() << "\n\n";
  }
}

void Test::testDestructor(){
  Queue myQueue;
  myQueue.enqueue(1);
  myQueue.enqueue(2);
  myQueue.enqueue(3);
  myQueue.~Queue();
}
