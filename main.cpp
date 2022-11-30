#include "EasyBMP.hpp"
#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <random>
using namespace std;

struct point{

public:
    int x , y;
    int r,g,b;
    float distanceTo(int x1, int y1){
        
        int dx = (x1 - x);
        int dy = (y1 - y);
        
        return sqrt((float)((dx*dx)+(dy*dy)));
    }
};

point points[10];


int findClosest(int x , int y ){

    int closest = 0;

    for(int i = 0 ; i < 10; i++){

        point c = points[i];
        point k = points[closest];

        if(c.distanceTo(x,y) < k.distanceTo(x,y)) closest = i;

    }

    return closest;

}

int main(){


    EasyBMP::RGBColor black(0, 0, 0);  

    system("TIMEOUT 1");

    EasyBMP::Image img(512, 512, "sample.bmp", black);


    default_random_engine gr(time(NULL));
    uniform_int_distribution<int> dist(0,512);
    uniform_int_distribution<int> dist2(0,255);

    for(int i = 0 ; i < 10; i++){
        points[i].x = dist(gr);
        points[i].y = dist(gr);
        points[i].r = dist2(gr);
        points[i].g = dist2(gr);
        points[i].b = dist2(gr);
    };

    for(int y = 0 ; y < 512 ; y++ ){
        for(int x = 0 ; x < 512 ; x++){
            int closest = findClosest(x,y);

            int r = points[closest].r;
            int g = points[closest].g;
            int b = points[closest].b;

            img.SetPixel(x, y, EasyBMP::RGBColor(r, g, b));
        }
    }


    img.Write();

    return 0;
}