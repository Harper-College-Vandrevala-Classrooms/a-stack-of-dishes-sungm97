#include <iostream>
#include <array>
#include <string>

using namespace std;

class Dish {
private:
    string description;

public:
    Dish(string description = "") { 
        this->description = description;
    }

    string get_description() const {
        return this->description;
    }
};

class DishStack {
private:
    int top;                        
    static const int max = 10; 
    array<Dish, max> stack;    
public:
    DishStack() : top(-1) {}        

    void push(const Dish& dish) {
        if (top == max - 1) {
            cout << "The stack is full. Cannot push a new dish.\n";
            return;
        }
        stack[++top] = dish;
    }

    Dish pop() {
        if (top == -1) {
            cout << "The stack is empty. Cannot pop.\n";
            return Dish();
        }
        return stack[top--];
    }

    Dish peek() const {
        if (top == -1) {
            cout << "The stack is empty. Cannot peek.\n";
            return Dish();
        }
        return stack[top];
    }

    int size() const {
        return top + 1;
    }
};

int main() {
    DishStack stack;

    Dish one_dish("A dish with one fish pattern on it");
    Dish two_dish("A dish with two fish patterns on it");
    Dish red_dish("A dish with a red fish pattern on it");
    Dish blue_dish("A dish with a blue fish pattern on it");

    int stack_size = stack.size();
    cout << "Initial stack size: " << stack_size << endl;

    stack.push(one_dish);
    stack.push(two_dish);
    stack.push(red_dish);
    stack.push(blue_dish);

    int size_after_pushes = stack.size();
    cout << "Stack size after pushes: " << size_after_pushes << endl;

    Dish peeked_dish = stack.peek();
    cout << "Peeked dish: " << peeked_dish.get_description() << endl;

    Dish popped_dish = stack.pop();
    cout << "Popped dish: " << popped_dish.get_description() << endl;

    Dish another_popped_dish = stack.pop();
    cout << "Another popped dish: " << another_popped_dish.get_description() << endl;
    
    Dish test_dish("Test");
    stack.push(test_dish);
    stack.push(test_dish);
    stack.push(test_dish);
    stack.push(test_dish);
    stack.push(test_dish);
    stack.push(test_dish);
    stack.push(test_dish);
    stack.push(test_dish);
    stack.push(test_dish);

    int final_size = stack.size();
    cout << "Final stack size: " << final_size << endl;

    return 0;
}
