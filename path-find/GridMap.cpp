#include "GridMap.h"
#include <fstream>
#include <iostream>
GridMap::GridMap(std::string& map_path, float res)
{
	this->map_path = map_path;
	this->resolution = res;
	std::fstream file(map_path);
	if (!file.is_open()) throw std::runtime_error("The file " + map_path + " could not be opened");
	else std::cout << "File opened successfully" << std::endl;
}

void GridMap::ReadFile()
{
	std::fstream file(map_path);
	if (!file.is_open()) throw std::runtime_error("The file " + map_path + " could not be opened");
	file >> magic_word >> width >> height >> mapMaxVal;
	total_size = width * height;
	for (int i = 0; i < total_size; i++) {
		int curr_val;
		file >> curr_val;
		map_data[i] = (curr_val > 0); // bigger than 0 means white 
	}


}

bool GridMap::isFree(float x, float y) const
{
	int col = x / resolution;
	int row = y / resolution;
	int index = row * width + col;
	return map_data[index];
}

bool GridMap::isCollision(float x, float y, float degree) const
{
	
	int l_checkPoint[] = { -L / 2,0.0f,L / 2 };
	int w_checkPoint[] = { -W / 2, 0.0f , W / 2 };
	for (float lx : l_checkPoint) {
		for (float ly : w_checkPoint) {
			float wx = x + lx * cos(degree) - ly * sin(degree);
			float wy = y + lx * sin(degree) + ly * cos(degree);
			if (!isFree(wx, wy)) return true;
		}
		
	}
	return false;
}


