//To compile: g++ drill12.cpp ../../GUI/Graph.cpp ../../GUI/Window.cpp ../../GUI/GUI.cpp ../../GUI/Simple_window.cpp -o drill12 `fltk-config --ldflags --use-images`

#include "../../GUI/Window.h"
#include "../../GUI/Graph.h"
#include "../../GUI/Simple_window.h"

using namespace Graph_lib;

int main() {
	try{
		Point tl {100,100};
		Simple_window win {tl,600,400,"My window"};

		Axis xa {Axis::x, Point{20,310}, 280, 10, "x axis"};
		win.attach(xa); // attach xa to the window, win
		//win.set_label("Canvas #2");
		Axis ya {Axis::y, Point{20,310}, 280, 10, "y axis"};
		ya.set_color(Color::dark_green); // choose a color
		ya.label.set_color(Color::dark_red); // choose a color for the text
		win.attach(ya);
		win.set_label("My window");//Change window title

		Function sine {sin,0,100,Point{20,150},1000,50,50};
		// plot sin() in the range [0:100) with (0,0) at (20,150)
 		// using 1000 points; scale x values *50, scale y values *50
		win.attach(sine);
		sine.set_color(Color::blue); // we changed our mind about sine’s color

		Polygon poly; // a polygon; a Polygon is a kind of Shape
		poly.add(Point{300,200}); // three points make a triangle
		poly.add(Point{300,100});
		poly.add(Point{400,100});
		poly.add(Point{400,200});
		poly.set_color(Color::red);
		poly.set_style(Line_style::dash);
		win.attach(poly);

		Rectangle r {Point{200,200}, 100, 50}; // top left corner, width, height
		win.attach(r); 
		
		Closed_polyline poly_rect;
		poly_rect.add(Point{100,50}); 
		poly_rect.add(Point{200,50});
		poly_rect.add(Point{200,100});
		poly_rect.add(Point{100,100});
		poly_rect.add(Point{50,75});
		win.attach(poly_rect);

		r.set_fill_color(Color::yellow); // color the inside of the rectangle
		poly.set_style(Line_style(Line_style::dash,4)); 
		poly_rect.set_style(Line_style(Line_style::dash,2));
		poly_rect.set_fill_color(Color::green);

		Text t {Point{150,150}, "Hello, drill12!"};
		win.attach(t);
		t.set_font(Font::times_bold);
		t.set_font_size(20);

		//Image ii {Point{100,50},"apple.jpg"}; 
		//win.attach(ii);
		//ii.move(100,200);


		Circle c {Point{100,200},50};
		Ellipse e {Point{100,200}, 75,25}; 
		e.set_color(Color::dark_red);
		Mark m {Point{100,200},'x'};
		ostringstream oss;
		oss << "screen size: " << x_max() << "*" << y_max()
		 << "; window size: " << win.x_max() << "*" << win.y_max();
		Text sizes {Point{100,20},oss.str()};
		Image cal {Point{225,225},"skyline.jpg"}; // 320*240-pixel gif
		cal.set_mask(Point{40,40},200,150);

		win.attach(c);
		win.attach(m);
		win.attach(e);

		win.attach(sizes);
		win.attach(cal);


		win.wait_for_button(); 
	}
	catch(exception& e) {
 		return 1;
 	}
 	catch(...) {
 		return 2;
 	}


} 