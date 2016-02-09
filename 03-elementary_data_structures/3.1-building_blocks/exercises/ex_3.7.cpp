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
    point nearest_point{0,0};
    //std::cin returns bool
    for(point current_point ; (std::cin >> current_point.x && std::cin >> current_point.y);)
        points.push_back(current_point);
    //Find the closest point to the first skipping the first element
    auto it = points.begin();
    point first{it->x,it->y};
    it++;
    if (it != points.end()){
        point second{it->x, it->y};
        auto shortest_distance = distance(first, second);
        nearest_point = second;
            //Advance iterator to avoid comparing with the second element
            for(it++;it != points.end(); it++){
                point current{*it};
                auto current_distance = distance(first, current);
                if( current_distance < shortest_distance ){
                    nearest_point = current;
                    shortest_distance = current_distance;
                }
            }
    }
    std::cout << "Total amount of points : " << std::endl;
    //Note that variable it below is not a pointer
    for(auto it : points)
        std::cout<< it.x << "    "<< it.y << std::endl;
    if(nearest_point.x == 0 && nearest_point.y == 0 && points.size() <= 1){
        std::cout << "You need at least two points to compare " << std::endl;
    }
    else{
        std::cout << "Closest point  : " << nearest_point.x <<"," << nearest_point.y <<std::endl;
    }
    return 0;
}

