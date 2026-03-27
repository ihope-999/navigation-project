#pragma once
#include "Node.cpp"
#include <vector>
#include "GridMap.h"
class Math
{
	static float normalizeAngle(float angle);
	float distance_of_nodes(const Node& myNode, const Node& goalNode);
	std::vector<Node> generate_possible_nodes(const Node& curr, const GridMap& map);
};

