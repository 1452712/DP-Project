#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Entry{
public:
    virtual string getName() = 0;
    virtual int getSize() = 0;

    Entry& add(Entry entry) {
        //TODO
        try {
            //throw
        }
        catch("") {

        }
    }

    void printList() {
        printList("");
    }

    string& toString() {
        return getName() + "(" +getSize() + ")";
    }
protected:
    virtual void printList(string& prefix) = 0;
};

// public class FileTreatementException extends RuntimeException {
//     public FileTreatementException() {
//     }
//     public FileTreatementException(String msg) {
//         super(msg);
//     }
// }

class File: public Entry {
public:
    File(string& name, int size): name_(name), size_(size) {}
    int getSize() { return size_;}
    string& getName() { return name_;}
protected:
    void printList(string& prefix) {
        //TODO
        cout << prefix << "" << this << endl;
    }
private:
    string name_;
    int size_;
};

class Directory: public Entry {
private:
    string name_;
    vector<Entry> directory_;
public:
    Directory(string& name) name_(name){
        directory_.clear();
    }

    string& getName() { return name_;}

    int getSize() {
        int res = 0;
        for(auto temp: directory_) {
            res += temp.getSize();
        }
        return res;
    }

    Entry& add(Entry entry) {
        directory_.push_back(entry);
        return this;
    }

protected:
    void printList(string& prefix) {
        //TODO
        cout << prefix << "" << this << endl;
        for(auto temp: directory_){
            temp.printList(prefix + "/" + name_);
        }
    }
};