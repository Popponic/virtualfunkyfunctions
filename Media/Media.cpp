// Media.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Went a bit overboard, but I've got the idea down. To stop confusion resulting from complex code, abstraction aims to avoid this sort of issue by hiding details.
// The subclasses rely on their own defintions to allow the virtual functions to actually work when called upon by the Media pointer object.
// Also makes things more efficient by using only one call to the parent class to point to any subclass to create an object.
// Bad at explaining, and apologies for lack of comments.


#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Media {
protected:
    string title;
    float price;
public:
    Media(string s = "Blank", float a = 0.0) {
        title = s;
        price = a;
    }
    virtual void input() = 0;
    virtual void display() = 0;
};

class Tape : public Media {
private:
    float time;
public:
    Tape(string s = "Blank", float a = 0.0, float t = 0.0) :Media(s, a) {
        title = s;
        price = a;
        time = t;
    }
    void input() {
        cin.ignore(256, '\n');
        cout << "\nEnter the tape title: ";
        getline(cin, title);
        cout << "Enter the tape price (no $ symbol please): ";
        cin >> price;
        cout << "Enter the tape playtime (in minutes. 5.5 = 5 minutes, 30 seconds for example): ";
        cin >> time;
    }
    void display() {
        cout << "\nTitle: " << title << endl;
        cout << "Price: " << price << endl;
        cout << "Playtime: " << time << " minutes" << endl;
    }
};

class Book : public Media {
private:
    int pages;
public:
    Book(string s = "Blank", float a = 0.0, int p = 0) :Media(s, a) {
        title = s;
        price = a;
        pages = p;
    }
    void input() {
        cin.ignore(256, '\n');
        cout << "\nEnter the book title: ";
        getline(cin, title);
        cout << "Enter the book price (no $ symbol please): ";
        cin >> price;
        cout << "Enter the number of pages: ";
        cin >> pages;
    }
    void display() {
        cout << "\nTitle: " << title << endl;
        cout << "Price: " << price << endl;
        cout << "Pages: " << pages << endl;
    }
};

int main()
{
    vector<Media*> m(1);
    int datatype = 0;
    int choice = 0; //
    int vc = 0; // Vector Counter

    do {
        cout << "Choose the data type for input: " << endl;
        cout << "[1]>> Book" << endl;
        cout << "[2]>> Tape" << endl;
        cin >> datatype;

        switch (datatype) {
        case 1:
            m[vc] = new Book;
            m[vc]->input();
            m.push_back(m[vc]);
            vc++;
            break;
        case 2:
            m[vc] = new Tape;
            m[vc]->input();
            m.push_back(m[vc]);
            vc++;
            break;
        default:
            cout << "You didn't enter a relevant choice." << endl;
        }

        cout << "\n\nSelect your next action: " << endl;
        cout << "[1]>> Add More Data" << endl;
        cout << "[2]>> View Existing Data" << endl;
        cin >> choice;
    } while (choice != 2);

    for (int i = 0; i < vc; i++) {
        m[i]->display();
    }


}

