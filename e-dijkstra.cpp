//#include "e-dijkstra.h"
//#include <iostream>
//#include <fstream>
//#include <sstream>
//#include <vector>
//#include <string>
//#include <queue>
//
//
//struct Grid
//{
//	std::vector<std::pair<int, int>> End_Cost = {};
//};
//struct City
//{
//	City() {}
//	City(int cn, int b, int c) :cityNumber(cn), battery(b), charge(c), visited(false) {}
//
//	int cityNumber = 0;
//	int battery = 0;
//	int charge = 0;
//	bool visited = false;
//};
//struct CompareBattery
//{
//	bool operator()(City const& p1, City const& p2)
//	{
//		if (p1.charge == p2.charge)
//			return p1.battery < p2.battery;
//		else
//			return p1.charge < p2.charge;
//	}
//};
//
//std::vector<Grid> Readfile(const char* filename, int& numlocation, int& recharges, int& edges, const int range)
//{
//	std::ifstream infile(filename);
//	if (!infile.is_open())
//	{
//		std::cout << "ERROR READING FILE\n";
//		exit(1);
//	}
//
//	std::vector<Grid> cities;
//
//	unsigned linenum = 0;
//	std::string line;
//
//	while (std::getline(infile, line))
//	{
//		std::stringstream s(line);
//
//		if (!linenum)
//		{
//			s >> numlocation >> recharges >> edges;
//			cities.resize(numlocation);
//		}
//
//		else
//		{
//			int _start = 0;
//			int _end = 0;
//			int weight = 0;
//
//			s >> _start >> _end >> weight;
//			if (weight > range) continue;
//
//			cities[_start].End_Cost.emplace_back(std::make_pair(_end, weight));
//			cities[_end].End_Cost.emplace_back(std::make_pair(_start, weight));
//		}
//		++linenum;
//	}
//	return cities;
//}
//
//void Charge(int& currbattery, int& chargeCount, int range)
//{
//	currbattery = range;
//	--chargeCount;
//}
//
//bool e_dijkstra(char const* filename, int range)
//{
//	int numLocation = 0;
//	int numCharge = 0;
//	int numEdge = 0;
//
//	std::vector<Grid> grid = Readfile(filename, numLocation, numCharge, numEdge, range);
//	const std::vector<Grid> original = grid;
//	std::priority_queue<City, std::vector<City>, CompareBattery> Q;
//	std::vector<bool>visited(numLocation, false);
//
//	int currBattery = 0;
//	const int originalChargeCount = numCharge;
//	Charge(currBattery, numCharge, range);
//
//	//Pick every city as starting point
//	for(int j=0; j<numLocation; ++j)
//	{
//		//push first city into queue
//		Q.push(City(j, currBattery, numCharge));
//		
//		while (!Q.empty())
//		{
//			int currCity = Q.top().cityNumber;
//			int currRecharge = Q.top().charge;
//			int currBattery = Q.top().battery;
//			int numChoice = grid.at(currCity).End_Cost.size();
//
//			visited.at(currCity) = true;
//			Q.pop();
//
//			//for every connected city
//			for (int i = 0; i < numChoice; ++i)
//			{
//				int nextIndex = grid.at(currCity).End_Cost.at(i).first;
//				//if already visited, skip
//				if (visited.at(nextIndex))
//				{
//					continue;
//				}
//				//if there is enough battery
//				if (grid.at(currCity).End_Cost.at(i).second <= currBattery)
//				{
//					int cityNumber = grid.at(currCity).End_Cost.at(i).first;
//					int nextRange = currBattery - grid.at(currCity).End_Cost.at(i).second;
//					int nextRecharge = currRecharge;
//					Q.push(City(cityNumber, nextRange, nextRecharge));
//				}
//				//if you can get there by charging
//				else
//				{
//					if (currRecharge > 0)
//					{
//						if (grid.at(currCity).End_Cost.at(i).second < range)
//						{
//							int cityNumber = grid.at(currCity).End_Cost.at(i).first;
//							int nextRange = range - grid.at(currCity).End_Cost.at(i).second;
//							int nextRecharge = currRecharge - 1;
//							Q.push(City(cityNumber, nextRange, nextRecharge));
//						}
//					}
//				}
//			}
//		}
//		
//		for (unsigned i = 0; i < visited.size(); ++i)
//		{
//			//if any city wasn't visited
//			if (visited.at(i) == false)
//				return false;
//			//reset for next trip
//			else
//				visited.at(i) = false;
//		}
//		//reset variables for next trip
//		grid.clear();
//		grid = original;
//		numCharge = originalChargeCount;
//		Charge(currBattery, numCharge, range);
//	}
//	return true;
//}
