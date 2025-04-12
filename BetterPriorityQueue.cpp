#include "BetterPriorityQueue.h"

using namespace std;

//returns a string representation of the BPQ Nodes
static const string BPQNodeToString(BPQNode node){
    return "(" + to_string(node.gnode) + ", pri: " + to_string(node.pri) + ")";
}

//Checks if a BPQ node is in the BPQ
const bool BetterPriorityQueue::Contains(BPQNode node){
    for(size_t i = 0; i<c.size(); i++){
        if(c.at(i)==node){
            return true;
        }
    }
    return false;
}

//Updates the BPQ only if the new node exists and its priority is less than the current one
bool BetterPriorityQueue::Update(BPQNode node){
    bool success = false;
    vector<BPQNode> items;
    for(size_t i = 0; i<c.size(); i++){
        BPQNode curr = c.at(i);
        if((node == curr) && (node.pri < curr.pri)){
            success = true;
            curr.pri = node.pri;
        }
        items.push_back(curr);
    }
    c.clear();
    for(size_t i = 0; i<items.size(); i++){
        this->push(items.at(i));
    }
    return success;
}

//returns a string representation of the BPQ
const string BetterPriorityQueue::ToString(){
    string result = "[";
    for(size_t i = 0; i<c.size()-1; i++){
        result += BPQNodeToString(c.at(i)) + ", ";
    }
    result += BPQNodeToString(c.back()) + "]";
    return result;
}