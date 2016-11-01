#include <iostream>
#include <vector>
using namespace std;

//notification
//custom notification if necessary
class Notification {
public:
    Notification(string in_type = "default") : str_type_(in_type){};
    void setType(string in_type = "default") { str_type_ = in_type;};
    string getType() { return str_type_;};
private:
    string str_type_;
};

class Observee;
//to observe
class Observer {
public:
    virtual void update(Observee&, Notification*);
    virtual operator==(Observer&);
};

//to be observed
//TODO: deal with the exception
class Observee {
public:
    //constructor
    Observee();

    //related to b_changed_
    void setChanged(bool);
    void clearChanged();
    bool hasChanged();

    //related to Observer
    int countObserver();
    bool addObserver(Observer&);
    bool rmObserver(Observer&);
    void notifyObservers(Notification* in_notification = NULL);
private:
    vector<Observer> vec_obs_;
    bool b_changed_;

    int containsObserver(Observer&);
};

Observee::Observee() : b_changed_(false){ vec_obs_.clear();}

void Observee::setChanged(bool in_state) { b_changed_ = in_state;}

void Observee::clearChanged() { b_changed_ = false;}

bool Observee::hasChanged() { return b_changed_;}

int Observee::containsObserver(Observer& in_observer) {
    for(int pos = 0; pos < vec_obs_.size(); pos++) {
        if(vec_obs_[pos] == in_observer) return pos;
    }
    return -1;
}

int Observee::countObserver() { return vec_obs_.size();}

bool Observee::addObserver(Observer& in_observer) {
    int pos = containsObserver(in_observer);
    if(pos == -1) {
        vec_obs_.push_back(in_observer);
        return true;
    }
    return false;
}

bool Observee::rmObserver(Observer& in_observer) {
    int pos = containsObserver(in_observer);
    if(pos == -1) return false;
    vec_obs_.erase(pos);
    return true;
}

void Observee::notifyObservers(Notification* in_notification) {
    if(b_changed_){
        for(int i = 0; i < vec_obs_.size(); i++) {
            vec_obs_[i].update(this, in_notification);
        }
    }
    return;
}