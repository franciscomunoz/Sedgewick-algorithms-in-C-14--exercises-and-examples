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
        std::vector<point> points;
        unsigned count = 0;
        constexpr unsigned number_points = 3;
        for(point current_point ; count < number_points && (std::cin >> current_point.x && std::cin >> current_point.y);){
			points.push_back(current_point);
            count++;
        }
        float shortest_distance = 0;
        float current_distance = 0;
        point point1; //Points which constitute the shortest distance
        point point2;
        for(std::size_t i = 0; i < points.size(); i++){
            for(std::size_t j = i + 1; j < points.size(); j++)
                if(i == 0 && j == 1){
                    shortest_distance = distance(points[i],points[j]);
                }
                else{
                    current_distance = distance(points[i],points[j]);
                    if(current_distance < shortest_distance){
                        shortest_distance = current_distance;
                        point1.x = points[i].x;
                        point1.y = points[i].y;
                        point2.x = points[j].x;
                        point2.y = points[j].y;
                    }
                }
        }
        std::cout << "The shortest distance amongst the points is " << shortest_distance << std::endl;
        std::cout<<"Shortest points are : " << point1.x << " " << point1.y << "--------" << point2.x << " " << point2.y << std::endl;
	return 0;
}

