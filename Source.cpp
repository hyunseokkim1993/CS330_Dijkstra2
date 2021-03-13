//#include <vector>
//#include <iostream>
//#include <fstream>
//#include <sstream>
//#include <utility>
//#include <queue>
//#include <algorithm>
//#include "e-dijkstra.h"
//
//int LocationNumber = 0;
//std::vector<std::vector<std::pair<unsigned, int>>>
//
//Readfile(const char* FileName, int& Location, int& Recharge, int& Edge, const int Range) {
//	std::ifstream infile(FileName);
//	std::vector<std::vector<std::pair<unsigned, int>>> Cities;
//	unsigned LineNumber = 0;
//	std::string LineString;
//	while (std::getline(infile, LineString)) {
//		std::stringstream SStream(LineString);
//		if (!LineNumber) {
//			SStream >> Location >> Recharge >> Edge;
//			Cities.resize(Location);
//		}
//		else {
//			int Start;
//			int End;
//			int Weight;
//			SStream >> Start >> End >> Weight;
//			//if cannot Testing in full electrocity, skip
//			if (Weight > Range) {
//				continue;
//			}
//			Cities[Start].push_back(std::make_pair(End, Weight));
//			Cities[End].push_back(std::make_pair(Start, Weight));
//		}
//		++LineNumber;
//	}
//	return Cities;
//}
//
////Find Arrivable Verticies
//void SetQueue(int Index, std::priority_queue< std::pair<std::pair<int, unsigned>, std::pair<int, int>> >& d, std::vector<std::vector<std::pair<unsigned, int>>> Location, int Recharge, int Range) {
//	for (unsigned i = 0; i < Location[Index].size(); ++i) {
//		d.push(std::make_pair(std::make_pair(Range - Location[Index][i].second + Range * Recharge, Location[Index][i].first), 
//			std::make_pair(Range - Location[Index][i].second, Recharge)));
//	}
//}
//
////Check Bool Vector is True
//bool CheckVector(std::vector<bool> Testing) {
//	for (unsigned i = 0; i < Testing.size(); ++i) {
//		if (!Testing[i]) {
//			return false;
//		}
//	}
//	return true;
//}
//
////Dijkstra for Vertices
//bool dijkstra(int Start, std::vector<std::vector<std::pair<unsigned, int>>> Location, int Recharge, int Range, std::vector <bool>& Evaluated) {
//	int RechargeValue = Recharge - 1;
//
//	//Queue for Vertices which Can be Arrived with Electricity
//	std::priority_queue< std::pair<std::pair<int, unsigned>, std::pair<int, int>> > Available;
//	SetQueue(Start, Available, Location, RechargeValue, Range);
//
//	//Until Queue is Empty
//	while (!Available.empty()) {
//		//Current Values
//		unsigned CurrentIndex = Available.top().first.second;
//		int CurrentRecharge = Available.top().second.second;
//		int CurrentRange = Available.top().second.first;
//		Evaluated[CurrentIndex] = true;
//
//		Available.pop();
//
//		//See Next Vertices to Go
//		for (unsigned i = 0; i < Location[CurrentIndex].size(); ++i) 
//		{
//			unsigned NextIndex = Location[CurrentIndex][i].first;
//
//			//Skip Visited Vertices
//			if (Evaluated[NextIndex]) 
//			{
//				continue;
//			}
//			//Electricity is Enough
//			if (Location[CurrentIndex][i].second <= CurrentRange) {
//				//Next Values after Movement
//				int NextRange = CurrentRange - Location[CurrentIndex][i].second;
//				int NextRecharge = CurrentRecharge;
//				Available.push(std::make_pair(std::make_pair(NextRange + NextRecharge * Range, NextIndex), std::make_pair(NextRange, NextRecharge)));
//			}
//			else 
//			{
//				//Recharge is Available
//				if (CurrentRecharge) {
//					//Next Values after Movement
//					int NextRange = Range - Location[CurrentIndex][i].second;
//					int NextRecharge = CurrentRecharge - 1;
//					Available.push(std::make_pair(std::make_pair(NextRange + NextRecharge * Range, NextIndex), std::make_pair(NextRange, NextRecharge)));
//				}
//			}
//		}
//	}
//	//Check Visited Vertices
//	if (!CheckVector(Evaluated)) 
//	{
//		return false;
//	}
//	return true;
//}
//
//bool e_dijkstra(char const* FileName, int Range) {
//	int Recharge = 0;
//	int Edge = 0;
//
//	//Pair(Destination, Weight)
//	std::vector<std::vector<std::pair<unsigned, int>>> Location;
//	Location = Readfile(FileName, LocationNumber, Recharge, Edge, Range);
//
//	//Loop for Start Point
//	for (int i = 0; i < LocationNumber; ++i) {
//		std::vector<bool> Evaluated(LocationNumber, false);
//		Evaluated[i] = true;
//		if (!dijkstra(i, Location, Recharge, Range, Evaluated)) {
//			return false;
//		}
//	}
//	return true;
//}