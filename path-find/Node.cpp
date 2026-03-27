#include <memory>
#define M_PI 3.14
struct Node {
	float x; float y; float degree;
	float g; float h;
	int ix; int iy; int idegree;
	std::shared_ptr<Node> parent = nullptr;
	float get_total_cost() const {
		return g + h;
	}
	void discretize(float res, float dtheta) {
		ix = x / res;
		iy = y / res;
		idegree = (degree + M_PI) / dtheta;
	}
};