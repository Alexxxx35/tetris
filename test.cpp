// #include <SFML/Graphics.hpp>
// using namespace std;
// using namespace sf;

// const int cell_size = 40;
// const int w_cnt = 10;
// const int h_cnt = 20;

// int main(void)
// {
//     RenderWindow window(VideoMode(w_cnt * cell_size, h_cnt * cell_size), "Tetris");
//     RectangleShape cell(Vector2f(cell_size, cell_size));
//     while (window.isOpen())
//     {
//         Event e;
//         while (window.pollEvent(e))
//         {
//             if (e.type == Event::Closed)
//                 window.close();
//         }
//         window.clear();
//         cell.setFillColor(Color::Green);
//         window.draw(cell);
//         window.display();
//     }

//     return 0;
// }