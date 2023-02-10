#include "../../GUI/Graph.h"
#include "../../GUI/Simple_window.h"



int main() {

	using namespace Graph_lib;

	//1. Make an 800-by-1000 Simple_window.
	int x_size = 1000;
	int y_size = 800;

	Simple_window win {Point{100,100}, x_size, y_size, "myGUI"};
	
	//2. Put an 8-by-8 grid on the leftmost 800-by-800 part of that window.
	//So that each square is 100-by-100.
	int x_cell = 100;
	int y_cell = 100;
	int x_grid = 800;
	int y_grid = 800;
	
	Lines grid;
	for (int x=x_cell; x<=x_grid; x+=x_cell)
	 	grid.add(Point{x,0},Point{x,y_grid}); // vertical line
	for (int y=y_cell; y<y_grid; y+=y_cell)
	 	grid.add(Point{0,y},Point{x_grid,y}); // horizontal line
	win.attach(grid);

	 //3.Insert 8 rectangles diagonally into the grid
	int rect_x = 0;
	int rect_y = 0;
	Vector_ref<Rectangle> RedRects;
	for (int i = 0; i < 8; ++i)
	{
		RedRects.push_back(new Rectangle{Point{rect_x,rect_y},100,100});
		RedRects[RedRects.size()-1].set_fill_color(Color::red);
		rect_x += 100;
		rect_y += 100;
	}
	for (int i = 0; i < RedRects.size(); ++i)
		win.attach(RedRects[i]);

	//4. Insert 3 200-by-200 images into the grid
	Image img1 {Point{0,400},"badge.jpg"};
	Image img2 {Point{200,600},"badge.jpg"};
	Image img3 {Point{400,0},"badge.jpg"};
	
	win.attach(img1);
	win.attach(img2);
	win.attach(img3);

	//moving image in grid system
	Image cat {Point{0,0}, "nyan-cat.jpg"};
    win.attach(cat);
    win.wait_for_button();

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 7; ++j) {
            cat.move(100, 0);
            win.wait_for_button();
        }
        cat.move(-700, 100);
        win.wait_for_button();
    }


	win.wait_for_button();
}