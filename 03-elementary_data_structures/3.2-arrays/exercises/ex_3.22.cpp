#include<iostream>
#include<array>
#include<cmath>
//Set variables below to adjust dimensions and number of points
constexpr unsigned dimension_amount = 2;
constexpr unsigned number_points = 10;
//Generates random points considering  dimension_amount
auto generatePoints(){
    std::array<float,dimension_amount> points;
    for( auto &it : points){
        it = std::rand()%100;
    }
    return points;
}
//We use a variable size as we do not want to hardcode it
template<std::size_t SIZE>
float distance(std::array<float,SIZE> a, std::array<float,SIZE> b)
{
    float square_sum = 0;
    if(a.size() != b.size()){
        std::cout << "Dimensions must match " << std::endl; //Naive error handling
        return -1;
    }
    for(std::size_t i = 0; i < a.size(); i++){
        square_sum += std::pow(b[i] - a[i],2);
    }
    return std::sqrt(square_sum);
}

int main()
{
    //Compute distance amongst points of d dimension_amount
    std::array< std::array<float,dimension_amount>, number_points >  points;
    std::for_each(points.begin(),points.end(),
                        [](auto & currentPoint){
                            //This where we create our points of random coordinates
                            currentPoint = generatePoints();
                        });
    float shortest_distance = 0;
    float current_distance = 0;
    //These two points below are just for printing the two closest points
    //and do not play any other role
    std::array<float,dimension_amount> point1;
    std::array<float,dimension_amount> point2;

    for(std::size_t i = 0; i < points.size(); i++){
        for(std::size_t j = i + 1; j < points.size(); j++){
            if( i == 0 && j == 1){
               shortest_distance = distance(points[i],points[j]);
            }
            else{
                current_distance = distance(points[i],points[j]);
                if(current_distance < shortest_distance){
                        shortest_distance = current_distance;
                        point1 = points[i];
                        point2 = points[j];
                }

            }
        }
    }
    std::cout << "The shortest distance amongst points of " << dimension_amount << " dimensions is :" << shortest_distance << std::endl;
    std::cout <<"The two closest points are : " << std::endl;
    for(std::size_t i = 0; i < point1.size(); i++){
        std::cout<< point1[i] << "-----" << point2[i] << std::endl;
    }

    return 0;
}
