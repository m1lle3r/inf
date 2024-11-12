#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    int cellSize = 50;
    const int gridSize = 10;

    RenderWindow window(VideoMode(500, 500), "Diagonal Pattern");

    RectangleShape cells[gridSize][gridSize];
    for (int x = 0; x < gridSize; x++) {
        for (int y = 0; y < gridSize; y++) {
            cells[x][y] = RectangleShape(Vector2f(cellSize - 2, cellSize - 2));
            cells[x][y].setPosition(x * cellSize, y * cellSize);
            
            if ((x + y -1) % 3 == 0) {
                cells[x][y].setFillColor(Color::Green);
            } else {
                cells[x][y].setFillColor(Color::White);
            }
            
            cells[x][y].setOutlineColor(Color::Black);
            cells[x][y].setOutlineThickness(1);
        }
    }

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();

        for (int x = 0; x < gridSize; x++) {
            for (int y = 0; y < gridSize; y++) {
                window.draw(cells[x][y]);
            }
        }

        window.display();
    }

    return 0;
}
