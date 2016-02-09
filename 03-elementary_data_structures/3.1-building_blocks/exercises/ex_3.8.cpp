#include<iostream>
#include<vector>
#include<cmath>

struct point {
     float x;
     float y;
 };

float distance(point a, point b)
{
	float dx = a.x - b.x;
    float dy = a.y - b.y;
    return std::sqrt(dx*dx + dy*dy);
}

int main()
{
		//Assume points are in the unit square
		std::vector<point> points;
		int count = 0; //For this particular problem we just need three points
        constexpr unsigned number_points = 3;
		for(point current_point ; count < number_points && (std::cin >> current_point.x && std::cin >> current_point.y);){
			points.push_back(current_point);
            count++;
        }
		//For the sake of being illustrative 6 variables will be used for the math.
		double x1 = points[0].x;
		double y1 = points[0].y;
		double x2 = points[1].x;
		double y2 = points[1].y;
		double x3 = points[2].x;
		double y3 = points[2].y;
        //This is how we test whether points are collinear.
		double  collinear = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);

        if(collinear == 0.0){
		    std::cout<<"Points are collinear." << std::endl;
        }
        else{
		    std::cout<<"Points are not collinear." << std::endl;
        }
	return 0;
}

