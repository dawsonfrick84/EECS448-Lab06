/*
*	@file Test.h
*	@author Dawson Frick
*	@date 2019.11.11
*/

#ifndef TEST_H
#define TEST_H

// template <typename T>
class Test
{
	public:

	/**
	*	@post Calls test functions
	*/
	void run();

	/**
	*	@pre Checks if queue isEmpty after creation of a new queue
	*	@post Prints to terminal the results of test 1
	*/
	void testEmpty();

	/**
	*	@pre Checks if queue isEmpty after enqueues, checks for errors with adding to queue
	*	@post Prints to terminal the results of tests 2-4, catches errors
	*/
	void testEnqueue();

	/**
	*	@pre Checks if queue isEmpty after dequeues
	*	@post Prints to terminal the results of tests 5-6, catches errors
	*/
	void testDequeue();

	/**
	*	@pre Checks peekFront() functionality by comparing the front value to various ints
	*	@post Prints to terminal the results of tests 7-10, catches errors
	*/
	void testPeek();

	/* Test Destructor
	*	@post Enqueues values to a queue and calls the destructor; used to test for memory leaks
	*/
	void testDestructor();
};

#endif
