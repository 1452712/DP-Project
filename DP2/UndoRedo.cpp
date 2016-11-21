#include <iostream>
#include <string>
#include <vector>
using namespace std;

class UndoableEdit {
public:
    virtual void undo() = 0;
    virtual bool canUndo() = 0;
    virtual void redo() = 0;
    virtual bool canRedo() = 0;
    virtual void die() = 0;
    virtual void addEdit(UndoableEdit anEdit) = 0;
    virtual void replaceEdit(UndoableEdit anEdit) = 0;
    virtual bool isSignificant() = 0;
    virtual string getPresentationName() = 0;
    virtual string getUndoPresentationName() = 0;
    virtual string getRedoPresentationName() = 0;
};

class AbstractUndoableEdit: public UndoableEdit {
public:
    AbstractUndoableEdit: has_been_done_(true), alive_(true) {}

    void undo() { has_been_done_ = false;}
    bool canUndo() { return has_been_done_;}
    void redo() { has_been_done_ = true;}
    bool canRedo() { return !has_been_done_;}
    void die() { alive_ = false;}
protected:
    string undo_name_;
    string redo_name_;
private:
    bool has_been_done_;
    bool alive_;
};

class CompoundEdit: public AbstractUndoableEdit {
public:
    &UndoableEdit lastEdit() { return edits[edits.size() - 1];}
    void addEdit(UndoableEdit anEdit) { edits.push_back(anEdit);}
protected:
    vector<UndoableEdit> edits;
};

//TODO
class UndoManager: public CompoundEdit {
public:
    UndoManager(): limit_(100), index_of_next_add_(0) {}

    int getLimit() { return limit_;}
    void setLimit(int l) { limit_ = l;}

    void discardAllEdits();
    void undoTo(UndoableEdit edit);
    void redoTo(UndoableEdit edit);
    void undoOrRedo();
    bool canUndoOrRedo();

    void undoableEditHappened();
    string toString();
protected:
    void trimForLimit();
    void trimEdits(int from, int to);
    UndoableEdit editToBeUndone();
    UndoableEdit editToBeRedone();
private:
    int limit_;
    int index_of_next_add_;
};