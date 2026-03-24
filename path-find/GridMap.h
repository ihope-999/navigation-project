#pragma once
#include <vector>
#include <string>
class GridMap
{
public:
	float resolution;
	int width;
	int height;
	int mapMaxVal;
	int total_size;
	std::string magic_word;
	std::string map_path;
	std::vector<bool> map_data;
	GridMap(std::string& map_path, float res);
	void ReadFile();
	bool isFree(float x, float y) const;

};

