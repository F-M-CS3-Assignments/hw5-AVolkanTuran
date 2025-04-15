#include "Dijkstra.h"
#include "BetterPriorityQueue.h"

using namespace std;


//The time complexity of this algorithm is O(E*Vlog(V))
//The time complexity for the first for loop is O(V*log(V)) because it is a binary heap tree
//In the worst case there is an update for each edge so there are E Update() calls
//Each Update call creates a new binary heap tree so each of them have O(V*log(V)) time complexity
//This means that the total time complexity for updating is O(E*Vlog(V))
//The final for loop is just O(V); therefore, the total time complexity is the biggest one O(E*Vlog(V))
int dijkstra(nodekey_t start, nodekey_t end, const Graph *g){

    //Throws an invalid argument if the start or end nodes don't exist
    if(!(g->IsPresent(start) && g->IsPresent(end))){
        throw invalid_argument("The start and end nodes must exist in the graph.");
    }

    //Creates a priority queue to keep track of which node to visit next
    BetterPriorityQueue pq;
    set<nodekey_t> nodes = g->GetNodes();

    for(nodekey_t node : nodes){
        BPQNode curr;
        curr.gnode = node;

        if(node == start){
            curr.pri = 0;
        }

        pq.push(curr);
    }

    vector<BPQNode> result;

    //Goes through the adjacent vertices of the node with the lowest priority and updates the paths to the adjacent vertices accordingly
    while(!pq.empty()){
        BPQNode curr = pq.top();
        pq.pop();

        result.push_back(curr);

        set<const GraphEdge*> edges = g->GetOutwardEdgesFrom(curr.gnode);

        for(const GraphEdge* edge : edges){
            BPQNode adjVertex;
            adjVertex.gnode = edge->to;

            int edgeWeight = edge->weight;
            adjVertex.pri = edgeWeight + curr.pri;
            
            pq.Update(adjVertex);
            
        }
    }

    int distance = INT_MAX;

    //Finds the distance to the end node and returns it
    for(size_t i = 0; i<result.size(); i++){
        if(result.at(i).gnode == end){
            distance = result.at(i).pri;
        }
    }

    return distance;
}
