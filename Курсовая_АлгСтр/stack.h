#ifndef stack_H
#define stack_H
#include"queue.h"
class stackoper
{
private:
	class stackNode {
	public:
		char date;
		queue Queue;
		stackNode* next;
		size_t index;
		stackNode(char date, stackNode* next = nullptr)
		{
			this->date = date;
			this->next = next;
		};
		~stackNode()
		{

		}

	};
public:
	stackNode* head;
	stackNode* tail;
	unsigned int size;
	stackoper() {
		head = nullptr;
		tail = nullptr;
		size = 0;
	}
	~stackoper() {
		clear();
	}
	void clear() {
		while (size != 0)
		{
			pop_front();
		}
	}
	void push(char date) {
		if (size == 0) {
			head = new stackNode(date);
			tail = head;
		}
		else {
			head = new stackNode(date, head);
		}
		size++;
	}
	void pushafter(char date) {
		stackNode* ggg = new stackNode(date);
		ggg->next = head->next;
		head->next = ggg;
		size++;
	}
	void pop_front() {
		if (size == 0) {
			return;
		}
		if (size == 1) {
			delete head;
			reset_list();
		}
		else {
			stackNode* current = head;
			head = head->next;
			delete current;
		}
		size--;

	}
	void pop_back() {
		if (size == 0) return;
		if (size == 1) {
			delete head;
			reset_list();
		}
		else {
			stackNode* current = head;
			while (current->next != tail) {
				current = current->next;
			}
			current->next = nullptr;
			delete tail;
			tail = current;
		}
		size--;
	}
	void reset_list()
	{
		head = nullptr;
		tail = nullptr;
	}

};
#endif
