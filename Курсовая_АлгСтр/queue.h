#ifndef queue_H
#define queue_H
class queue
{
private:
	class queueNode {
	public:
		char date;
		queueNode* next;

		queueNode(char date , queueNode* next = nullptr)
		{
			this->date = date;
			this->next = next;
		};
		~queueNode()
		{

		}

	};
public:
	queueNode* head;
	queueNode* tail;
	unsigned int size;
	queue() {
		tail = nullptr;
		head = nullptr;
		size = 0;
	}
	~queue() {
		clear();
	}
	void clear() {
		while (size != 0)
		{
			pop();
		}
	}
	void push(char date) {
		if (size == 0) {
			head = new queueNode(date);
			tail = head;
		}
		else {
			tail->next = new queueNode(date);
			tail = tail->next;
		}
		size++;
	}
	void pop() {
		if (size == 0) {
			return;
		}
		if (size == 1) {
			delete head;
			reset_list();
		}
		else {
			queueNode* current = head;
			head = head->next;
			delete current;
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