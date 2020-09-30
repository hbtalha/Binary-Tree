#include <iostream>

#include "Tree.h"

using namespace std;

class Test
{
    string name;
public:
    Test () {}
    Test(string name_) : name(name_) {}

    friend ostream& operator<<(ostream& os, Test& t)
    {
        os << t.name;

        return os;
    }

    bool operator<(Test t);
    bool operator<=(Test t);
    bool operator>(Test t);
};

bool Test::operator<(Test t)
{
    return (name < t.name);
}

bool Test::operator<=(Test t)
{
    return (name <= t.name);
}

bool Test::operator>(Test t)
{
    return (name > t.name);
}

int main()
{
    BinaryTree<int> tr;

    /*
                      4
                    /      \
                 1          6
                /  \        /  \
              0    2       5      9
                                  \
                                  89
                                 /    \
                               12   222
                                  \
                                 32
                                /
                             22
    */

    tr.insert(4);
    tr.insert(6);
    tr.insert(1);
    tr.insert(9);
    tr.insert(2);
    tr.insert(0);
    tr.insert(89);
    tr.insert(12);
    tr.insert(32);
    tr.insert(5);
    tr.insert(22);
    tr.insert(222);

     cout << tr.getNumberLeftNodes();


    tr.showLast();

    //tr.erase(4);

    cout  << endl;

    tr.erase(89);

     tr.print();


    //  tr.showFirst();
    cout << endl;
    // tr.showLast();
    cout << endl;

    BinaryTree<string> bst;

    bst.insert("Zanildo");
    bst.insert("Helder");
    bst.insert("Wilson");
    bst.insert("Ady");
    bst.insert("Adilson");
    bst.insert("Patrick");

    // bst.showFirst();
    cout << endl;
    // bst.showLast();
    cout << endl;

    BinaryTree<Test> test;

    test.insert({"Jhonny"});
    test.insert({"Bruno"});
    test.insert({"Garry"});
    test.insert({"Henry"});
    test.insert({"Amber"});
    test.insert({"Brandy"});
    test.insert({"Danny"});
    test.insert({"Cameron"});
    test.insert({"Edla"});
    test.insert({"Zenalda"});

    // test.showFirst();
    cout << endl;
    // test.showLast();
    cout << endl;
    //test.print();


    return 0;
}
