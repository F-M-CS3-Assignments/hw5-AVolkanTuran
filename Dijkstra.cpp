#include "Dijkstra.h"
#include "BetterPriorityQueue.h"

using namespace std;


//The time complexity of this algorithm is O()
int dijkstra(nodekey_t start, nodekey_t end, const Graph *g){
    if(!(g->IsPresent(start) && g->IsPresent(end))){
        throw invalid_argument("The start and end nodes must exist in the graph.");
    }

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

    for(size_t i = 0; i<result.size(); i++){
        if(result.at(i).gnode == end){
            distance = result.at(i).pri;
        }
    }

    return distance;
}
