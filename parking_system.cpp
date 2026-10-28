#include <iostream>
#include <queue>
#include <list>

using namespace std;

class Node {
public:
    string value;
    Node* next;

    Node(const string& value) : value(value), next(nullptr) {}
};

class Stack {
private:
    Node* top;
    int count;

public:
    Stack() : top(nullptr), count(0) {}

    ~Stack() {
        while (top) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void push(const string& item) {
        Node* newNode = new Node(item);
        newNode->next = top;
        top = newNode;
        count++;
    }

    string pop() {
        if (!top) return "";
        string item = top->value;
        Node* temp = top;
        top = top->next;
        delete temp;
        count--;
        return item;
    }

    string peek() {
        return top ? top->value : "";
    }

    int size() {
        return count;
    }

    bool contains(const string& item) {
        Node* current = top;
        while (current) {
            if (current->value == item) return true;
            current = current->next;
        }
        return false;
    }

    void printStack() {
        Node* current = top;
        while (current) {
            cout << current->value << " ";
            current = current->next;
        }
    }
};

class Queue {
private:
    queue<string> carQueue;

public:
    void enqueue(const string& item) {
        carQueue.push(item);
    }

    string dequeue() {
        if (carQueue.empty()) return "";
        string item = carQueue.front();
        carQueue.pop();
        return item;
    }

    int size() {
        return carQueue.size();
    }

    bool contains(const string& item) {
        queue<string> temp = carQueue;
        while (!temp.empty()) {
            if (temp.front() == item) return true;
            temp.pop();
        }
        return false;
    }

    void printQueue() {
        queue<string> temp = carQueue;
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
    }
};

class ParkingSystem {
private:
    int m, n;
    list<Stack> floors;
    Queue waitingCars;
    list<string> overflowWaitlist;

public:
    ParkingSystem(int m, int n) : m(m), n(n) {
        for (int i = 0; i < m; i++) {
            floors.push_back(Stack());
        }
    }

    void carEntry(const string& car) {
        for (auto& floor : floors) {
            if (floor.size() < n) {
                floor.push(car);
                cout << "Car " << car << " parked." << endl;
                return;
            }
        }
        if (waitingCars.size() < 5) {
            waitingCars.enqueue(car);
            cout << "Car " << car << " added to waiting queue" << endl;
        } else {
            overflowWaitlist.push_back(car);
            cout << "Car " << car << " added to overflow waitlist" << endl;
        }
    }

    void carExit(const string& car) {
        for (auto& floor : floors) {
            if (floor.contains(car)) {
                Stack tempStack;
                while (floor.peek() != car) {
                    tempStack.push(floor.pop());
                }
                floor.pop();
                while (tempStack.size() > 0) {
                    floor.push(tempStack.pop());
                }
                cout << "Car " << car << " removed." << endl;
                return;
            }
        }
    }

    void expandParking() {
        floors.push_back(Stack());
        m++;
        cout << "New floor added. Total floors: " << m << endl;
    }

    void displayStatus() {
        cout << "\nParking Lot Status:" << endl;
        int i = 1;
        for (auto& floor : floors) {
            cout << "Floor " << i++ << ": ";
            floor.printStack();
            cout << endl;
        }

        cout << "Waiting Queue: ";
        waitingCars.printQueue();
        cout << endl;

        cout << "Overflow Waitlist: ";
        for (const auto& car : overflowWaitlist) {
            cout << car << " ";
        }
        cout << endl;
    }
};

int main() {
    int floors, spots;
    cout << "Enter number of floors: ";
    cin >> floors;
    cout << "Enter number of spots per floor: ";
    cin >> spots;

    ParkingSystem parking(floors, spots);
    string command, car;

    while (true) {
        cout << "Enter command (entry/exit/status/expand/quit): ";
        cin >> command;
        if (command == "quit") break;
        if (command == "status") {
            parking.displayStatus();
            continue;
        }
        if (command == "expand") {
            parking.expandParking();
            continue;
        }
        cout << "Enter car ID: ";
        cin >> car;
        if (command == "entry") parking.carEntry(car);
        else if (command == "exit") parking.carExit(car);
    }
    return 0;
}



