#include "Math.h"
#include <iostream>
#define M_PI 3.14

float Math::normalizeAngle(float angle)
{
	while (angle > M_PI) angle -= 2.0f * M_PI;
	while (angle < M_PI) angle += 2.0f * M_PI;
	return angle;
}

float Math:: distance_of_nodes(const Node& myNode, const Node& goalNode)
{
	float dx = goalNode.x - myNode.x;
	float dy = goalNode.x - myNode.y;
	float distance = std::hypot(dx, dy);
	return distance;
}

std::vector<Node> Math:: generate_possible_nodes(const Node& curr, const GridMap& map)
{
	return;
}
