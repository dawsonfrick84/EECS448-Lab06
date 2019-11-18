/**
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
	*	@post Creates a Node. Pointer set to nullptr and value stored.
	*/
	void run();

	/**
	*	@return Pointer to next node.
	*/
	//Node<T>* getNext() const;

	void testEmpty();
	void testEnqueue();
	void testDequeue();
	void testPeek();
	void testDestructor();


};

#endif
