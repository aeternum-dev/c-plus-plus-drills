/*
    Use line below to compile:
    g++ drill15.cpp ../../GUI/Graph.cpp ../../GUI/Window.cpp ../../GUI/GUI.cpp ../../GUI/Simple_window.cpp -o d15.out `fltk-config --ldflags --use-images`
*/
#include "../../GUI/Simple_window.h"
#include "../../GUI/Graph.h"

double one(double x) { return 1; }
double slope(double x) { return x/2; }
double square(double x) { return x*x; }
//adds a cosine to slope:
double sloping_cos(double x){return cos(x)+slope(x);}

int main()
{
    using namespace Graph_lib;

    constexpr int xmax = 600;
    constexpr int ymax = 600;

	//1 
    Simple_window win {Point{100,100},xmax,ymax,"Function graphs"};
	Axis x {Axis::x,Point{100,300},400,20,"x: 1 = = 20 pixels"};
    Axis y {Axis::y,Point{300,500},400,20,"y: 1 = = 20 pixels"};
    x.set_color(Color::red);
    y.set_color(Color::red);
    win.attach(x);
    win.attach(y);

	//2
	//(0,0) is the center of window
	constexpr int x_orig = xmax/2;
	constexpr int y_orig = ymax/2;
	const Point orig {x_orig,y_orig};

	constexpr int r_min=-10;
	constexpr int r_max=11;
	constexpr int n_points = 400; //number of points in the range
	constexpr int x_scale = 20;
	constexpr int y_scale = 20;

	//Function f_one {one,r_min,r_max,orig}; without x and y scale
	Function f_one {one,r_min,r_max,orig,n_points,x_scale,y_scale};
	win.attach(f_one);

	Function f_slope {slope,r_min,r_max,orig,n_points,x_scale,y_scale};
	Text slope_label {Point{100,y_orig+5*y_scale},"x/2"};
	win.attach(f_slope);
	win.attach(slope_label);

	Function f_square {square,r_min,r_max,orig,n_points,x_scale,y_scale};
	win.attach(f_square);

	Function f_cos {cos,r_min,r_max,orig,n_points,x_scale,y_scale};
	f_cos.set_color(Color::blue);
	win.attach(f_cos);

	Function f_sloping_cos {sloping_cos,r_min,r_max,orig,n_points,x_scale,y_scale};
	win.attach(f_sloping_cos);

    win.wait_for_button();
}
