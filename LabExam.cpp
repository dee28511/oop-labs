#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

class Source;

class Observer
{
public:
	virtual void update(const Source* obj) = 0;
};

class Source
{
private:
	vector<shared_ptr<Observer>> observerList;
public:
	void notifyObservers()
	{
		for (int i{ 0 }; i < observerList.size(); i++) {
			observerList.at(i)->update(this);
		}
	}

	void regisObserver(shared_ptr<Observer> observer) {
		observerList.push_back(observer);
	}
};

class Publisher : public Source
{
private:
	string currentScore;
	void setCurrentScore(string newScore) {
		currentScore = newScore;
		notifyObservers();
	}
public:
	bool askCurrentScore() {
		string tempScore;
		cout << "Enter Score: ";
		getline(cin, tempScore);
		if (tempScore == "") { return false; }
		else {
			setCurrentScore(tempScore);
			return true;
		}
	}

	string getCurrentScore() { return currentScore; }
};

class Subscriber : public Observer
{
public:
	void update(const Source* obj) {
		cout << "Live result: " << ((Publisher*)obj)->getCurrentScore() << endl;
	}
};

int main()
{
	shared_ptr<Publisher> publisher = make_shared<Publisher>();
	shared_ptr<Subscriber> subOne = make_shared<Subscriber>();
	shared_ptr<Subscriber> subTwo = make_shared<Subscriber>();
	publisher->regisObserver(subOne);
	publisher->regisObserver(subTwo);
	while (publisher->askCurrentScore()) {}
	return 0;
}