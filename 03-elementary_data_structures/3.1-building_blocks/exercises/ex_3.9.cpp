#include<iostream>
#include<cmath>
#include<vector>

struct point{
    float x;
    float y;
};

class RandomTriangle
{
public:
    void    generate_points();
    float   compute_area();
private:
    std::vector<point> points = {{0,0},{0,0},{0,0}};
};

void RandomTriangle :: generate_points()
{
    //Hack to generate random values between 0 and 1
    constexpr unsigned  local_rand_max = 100000;
    std::for_each(points.begin(), points.end(),
                    [](auto &point)
                    {
                     point.x = static_cast<float>(std::rand()%local_rand_max)/local_rand_max;
                     point.y = static_cast<float>(std::rand()%local_rand_max)/local_rand_max;
                    }
                    );
}

float RandomTriangle :: compute_area()
{
	//Again we use helper variables to simplify the math.
	float x1 = points[0].x;
	float y1 = points[0].y;
	float x2 = points[1].x;
	float y2 = points[1].y;
	float x3 = points[2].x;
	float y3 = points[2].y;
	//This is how we compute the area
	return std::abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2);
}


int main()
{
    std::vector<RandomTriangle> triangles;
	constexpr int triangle_amount = 5;
	float area_avg = 0;
    int i;
	for(RandomTriangle triangle; i < triangle_amount; i++){
		triangles.push_back(triangle);
	}

	for(auto it : triangles){
		it.generate_points();
		auto area = it.compute_area();
		area_avg += area / triangle_amount;
	}
	std::cout << "Average area of triangles generated : " << area_avg << std::endl;
	return 0;
}

