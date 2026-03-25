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
	bool isCollision(float x, float y, float degree) const;

private:
	const float L = 5.0f;
	const float W = 3.0f;
};

