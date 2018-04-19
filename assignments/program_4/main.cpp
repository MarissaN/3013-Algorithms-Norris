
///////////////////////////////////////////////////////////////////////////////
//                   
// Title:            Spanning Trees
// Files:            csv.h
//					 main.cpp
//					 Distance.h
//					 graph.h
//					 filtered_cities.csv
// Semester:         3013-Algorithms Spring 2018
//
// Author:           Marissa Noris
// Email:            rissanorris16@gmail.com
// Description:
//      Creates a graph structure with cities as Vertices and no Edges initially. 
//		Fully connects the cities by adding edges between cities that are close together.
//		Then creates a connected graph of all the cities so that every city is reachable 
//		by ensuring that each vertex has a max degree of 3, 
//		where each edge represents one of three closest cities to that vertex
/////////////////////////////////////////////////////////////////////////////////

// A simple representation of graph using STL
#include "graph.h"
#include <fstream>
using namespace std;

/**
* randomEdges - creates random edges between vertices
* Params:
*     graph object and number of edges
* Returns
*     none
*/
void randomEdges(graph &g, int numEdges) {
	int r1, r2;
	latlon from;
	latlon to;
	double d;
	//runs till reach desire number edges
	for (int i = 0;i<numEdges;i++) {
		r1 = rand() % g.vertexList.size();
		r2 = rand() % g.vertexList.size();
		from = g.vertexList[r1]->loc;
		to = g.vertexList[r2]->loc;
		d = distanceEarth(from.lat, from.lon, to.lat, to.lon);
		g.addEdge(r1, r2, (int)d, true);
	}
}

/**
* loadGraphCSV - loads a graph with the given csv
* Params:
*     string filename  - filename to open
* Returns
*     graph
*/
graph loadGraphCSV(string filename, int max = 0)
{
	int zip;
	double lat;
	double lon;
	string city;
	string state;
	string county;


	strMapInt cityCheck;

	int i = 0;

	graph G;

	ifstream file(filename);

	for (CSVIterator loop(file); loop != CSVIterator(); ++loop)
	{
		zip = stoi((*loop)[0]);
		if ((*loop)[1].length() > 0)
		{
			lat = stod((*loop)[1]);
		}
		else
		{
			lat = 0.0;
		}

		if ((*loop)[2].length() > 0)
		{
			lon = stod((*loop)[2]);
		}
		else
		{
			lon = 0.0;
		}

		city = (*loop)[3];
		state = (*loop)[4];
		county = (*loop)[5];


		if (cityCheck.find(city) == cityCheck.end())
		{
			// Add the city as a key to the map.
			cityCheck[city] = 0;

			//creats vertices for the specifiled state
			if (state == "PR") {
				G.addVertex(city, state, lat, lon);
				i++;
			}
		}

		if (i > max && max != 0) {
			return G;
		}

	}

	return G;
}

/**
* filterDups - filters out duplicate cities and creates new output file
* Params:
*     string filename  - filename to open
*     string outfile   - filename to write to
* Returns
*     graph
*/
void filterDups(string filename, string outfile)
{
	int zip;
	double lat;
	double lon;
	string city;
	string state;
	string county;

	strMapInt cityCheck;

	int i = 0;


	ifstream file(filename);
	ofstream out(outfile);

	for (CSVIterator loop(file); loop != CSVIterator(); ++loop)
	{
		zip = stoi((*loop)[0]);
		if ((*loop)[1].length() > 0)
		{
			lat = stod((*loop)[1]);
		}
		else
		{
			lat = 0.0;
		}

		if ((*loop)[2].length() > 0)
		{
			lon = stod((*loop)[2]);
		}
		else
		{
			lon = 0.0;
		}

		city = (*loop)[3];
		state = (*loop)[4];
		county = (*loop)[5];


		if (cityCheck.find(city) == cityCheck.end())
		{
			// Add the city as a key to the map.
			cityCheck[city] = 0;
			out << zip << "," << lat << "," << lon << "," << city << "," << state << "," << county << "\n";

		}


	}

}

// Test Driver
int main(int argc, char **argv)
{
	srand(984325);
	int max_vertices = 0;
	int max_edges = 0;
	int degree;
	argc = 3;

	ofstream outfile;
	outfile.open("output.txt", ofstream::app);

	if (argc > 2) {
		
		max_vertices = 18952;
		
	}
	else {
		cout << "Usage: ./graph max_vertices max_edges" << endl;
		system("pause");
		exit(0);
	}

	cout << "\n";
	cout << " Enter desired number of edges: ";
	cin >> degree;
	cout << endl;

	//creates the graph of cites
	graph G = loadGraphCSV("filtered_cities.csv", max_vertices);

	outfile << "\n";
	//creats spanning tree for states
	//and prints results in outfile
	outfile << "Lebanon, Kansas" << "\n";
	G.createSpanningTree("KS", degree);
	outfile << G.miles << " miles " << G.edges << " edges " << "\n";
	outfile << "Miami, Florida" << "\n";
	G.createSpanningTree("FL", degree);
	outfile << G.miles << " miles " << G.edges << " edges " << "\n";
	outfile << "Dallas, Texas" << "\n";
	G.createSpanningTree("TX", degree);
	outfile << G.miles << " miles " << G.edges << " edges " << "\n";
	outfile << "Boston, Massachusetts" << "\n";
	G.createSpanningTree("MA", degree);
	outfile << G.miles << " miles " << G.edges << " edges " << "\n";
	outfile << "San Juan, Puerto Rico" << "\n";
	G.createSpanningTree("PR", degree);
	outfile << G.miles << " miles " << G.edges << " edges " << "\n";

	//if true it prints a directed graph, false undirected
	cout<<G.graphViz(true);

	int *size = G.graphSize();

	//print number of vertices and edges
	cout<<"V= "<<size[0]<<" E= "<<size[1]<<endl;

	//prints out list of  vertices
	for(int i=0;i<G.vertexList.size();i++){
	     cout<<(*G.vertexList[i])<<endl;
     }

	outfile.close();
	system("pause");
	return 0;
}