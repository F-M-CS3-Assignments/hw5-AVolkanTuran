
#include "Graph.h"
#include "BetterPriorityQueue.h"
#include "Dijkstra.h"

#include <iostream>
#include <cassert>

using namespace std;


int DijkstraTest(){
	cout << "Testing Dijkstra Algorithm..." << endl;
	
	// Test 1: graph from assignment
	Graph *g = new Graph();
	
	g->AddNode(1);
	g->AddNode(2);
	g->AddNode(3);
	g->AddNode(4);
	g->AddNode(5);
	g->AddNode(6);
	
	g->AddEdge(1, 2, 7);
	g->AddEdge(2, 1, 7);
	g->AddEdge(1, 3, 9);
	g->AddEdge(3, 1, 9);
	g->AddEdge(1, 6, 14);
	g->AddEdge(6, 1, 14);
	
	g->AddEdge(2, 3, 10);
	g->AddEdge(3, 2, 10);
	g->AddEdge(2, 4, 15);
	g->AddEdge(4, 2, 15);
	
	g->AddEdge(3, 6, 2);
	g->AddEdge(6, 3, 2);
	g->AddEdge(3, 4, 11);
	g->AddEdge(4, 3, 11);
	
	g->AddEdge(6, 5, 9);
	g->AddEdge(5, 6, 9);
	
	g->AddEdge(4, 5, 6);
	g->AddEdge(5, 4, 6);
	
	cout <<  "---Graph---" << endl;
	cout << "\tnodes: " << g->NodesToString() << endl;
	cout << "\tedges: " << g->EdgesToString() << endl;
	cout << "---Graph---" << endl << endl;

	nodekey_t start = 1;
	nodekey_t end = 5;

	cout << "start: " << to_string(start) << "  goal: " << to_string(end) << endl;
	
	int ans = dijkstra(start, end, g);
	cout << "Output from Dijkstra(" << to_string(start) << ", " << to_string(end) << ") => " << ans << endl;
	assert(ans == 20);

	delete g;
	
	cout << "DONE Testing Dijkstra Algorithm" << endl;
	
	return ans;
}


void MoreDijkstraTests(){
	cout << "Deep Testing Dijkstra Algorithm..." << endl;

	// Your code goes here!
	Graph *g = new Graph();
	
	g->AddNode(1);
	g->AddNode(2);
	g->AddNode(3);
	g->AddNode(4);
	g->AddNode(5);

	g->AddEdge(1,2,7);
	g->AddEdge(1,5,1);
	g->AddEdge(2,3,3);
	g->AddEdge(2,1,7);
	g->AddEdge(5,1,1);
	g->AddEdge(3,2,3);
	g->AddEdge(2,5,8);
	g->AddEdge(5,2,8);
	g->AddEdge(3,4,6);
	g->AddEdge(4,3,6);
	g->AddEdge(3,5,2);
	g->AddEdge(5,3,2);
	g->AddEdge(4,5,7);
	g->AddEdge(5,4,7);

	cout <<  "---Graph---" << endl;
	cout << "\tnodes: " << g->NodesToString() << endl;
	cout << "\tedges: " << g->EdgesToString() << endl;
	cout << "---Graph---" << endl << endl;

	nodekey_t start = 1;
	nodekey_t end = 2;

	cout << "start: " << to_string(start) << "  goal: " << to_string(end) << endl;
	
	int ans = dijkstra(start, end, g);
	cout << "Output from Dijkstra(" << to_string(start) << ", " << to_string(end) << ") => " << ans << endl;
	assert(ans == 6);

	start = 1;
	end = 3;

	cout << "start: " << to_string(start) << "  goal: " << to_string(end) << endl;
	
	ans = dijkstra(start, end, g);
	cout << "Output from Dijkstra(" << to_string(start) << ", " << to_string(end) << ") => " << ans << endl;
	assert(ans == 3);

	start = 1;
	end = 4;

	cout << "start: " << to_string(start) << "  goal: " << to_string(end) << endl;
	
	ans = dijkstra(start, end, g);
	cout << "Output from Dijkstra(" << to_string(start) << ", " << to_string(end) << ") => " << ans << endl;
	assert(ans == 8);

	start = 1;
	end = 5;

	cout << "start: " << to_string(start) << "  goal: " << to_string(end) << endl;
	
	ans = dijkstra(start, end, g);
	cout << "Output from Dijkstra(" << to_string(start) << ", " << to_string(end) << ") => " << ans << endl;
	assert(ans == 1);

	delete g;

	Graph *g1 = new Graph();

	try{
		dijkstra(0,1,g1);
		assert(false);
	}
	catch(exception &e){
	}

	g1->AddNode(5);
	g1->AddNode(3);
	g1->AddEdge(5,3,1);
	g1->AddEdge(3,5,1);

	start = 3;
	end = 5;

	cout << "start: " << to_string(start) << "  goal: " << to_string(end) << endl;
	
	ans = dijkstra(start, end, g1);
	cout << "Output from Dijkstra(" << to_string(start) << ", " << to_string(end) << ") => " << ans << endl;
	assert(ans == 1);

	start = 5;
	end = 3;

	cout << "start: " << to_string(start) << "  goal: " << to_string(end) << endl;
	
	ans = dijkstra(start, end, g1);
	cout << "Output from Dijkstra(" << to_string(start) << ", " << to_string(end) << ") => " << ans << endl;
	assert(ans == 1);	

	try{
		dijkstra(3,4,g1);
		assert(false);
	}
	catch(exception &e){}

	try{
		dijkstra(2,5,g1);
		assert(false);
	}
	catch(exception &e){}

	delete g1;

	cout << "DONE Deep Testing Dijkstra Algorithm" << endl;
}


int main(){
	
	DijkstraTest(); // this one by itself tests the graph on the assignment
	cout << endl;
	MoreDijkstraTests();
	cout << endl;
	cout << "ALL TESTS PASSED!" << endl;

	return 0;
}
