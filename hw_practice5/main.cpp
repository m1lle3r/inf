#include <SFML/Graphics.hpp>
#include <functional>
#include <cmath> 

// Функция для отрисовки графика
void drawGraph(sf::RenderWindow & window, std::function<float(float)> func, float xMin, float xMax, float scaleX, float scaleY, sf::Color color) {
    sf::VertexArray graph(sf::LinesStrip);

    for (float x = xMin; x <= xMax; x += 0.1f) {
        float y = func(x); // Вычисление значения функции

        // Преобразование координат в экранные
        float screenX = 400 + x * scaleX;
        float screenY = 300 - y * scaleY;

        // Добавление точки в массив вершин
        graph.append(sf::Vertex(sf::Vector2f(screenX, screenY), color));
    }

    window.draw(graph);
} 

int main() {
    // Создание окна
    sf::RenderWindow window(sf::VideoMode(800, 600), "Приложение для вывода графиков");

    // Переменная для хранения пользовательской точки
    sf::CircleShape userPoint(5); // Радиус 5 пикселей
    userPoint.setFillColor(sf::Color::Red);
    bool userPointExists = false; // Переменная для проверки существования пользовательской точки

    // 1 _ Загрузка шрифта (допишите код)
    sf::Font font;
    font.loadFromFile("Arial.ttf");

    // 2 _ Текст для отображения координат точки (допишите код)
    // Размер текста 20, положение текста (10,10), цвет белый. Текст храните в переменной coordinatesText
    sf::Text coordinatesText;
    coordinatesText.setFont(font);
    coordinatesText.setCharacterSize(20);
    coordinatesText.setFillColor(sf::Color::White);
    coordinatesText.setPosition(10, 10);  

    // Оси X и Y
    sf::VertexArray xAxis(sf::Lines, 2);
    xAxis[0].position = sf::Vector2f(50, 300); // Начало оси X
    xAxis[0].color = sf::Color::White; // Цвет оси
    xAxis[1].position = sf::Vector2f(750, 300); // Конец оси X
    xAxis[1].color = sf::Color::White;

    sf::VertexArray yAxis(sf::Lines, 2);
    yAxis[0].position = sf::Vector2f(400, 50); // Начало оси Y
    yAxis[0].color = sf::Color::White; // Цвет оси
    yAxis[1].position = sf::Vector2f(400, 550); // Конец оси Y
    yAxis[1].color = sf::Color::White;

    std::string section;
    while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();

        // Проверка клика мышью
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                // Получение позиции клика
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                // Преобразование экранных координат в "математические"
                float mathX = (mousePos.x - 400) / 30.0f; // Масштаб 30 по X
                float mathY = -(mousePos.y - 300) / 100.0f; // Масштаб 100 по Y

                // Установка новой пользовательской точки
                userPoint.setPosition(mousePos.x - userPoint.getRadius(), mousePos.y - userPoint.getRadius());
                userPointExists = true; // Помечаем, что точка существует

                // 3 _ Допишите логику проверки точки по переменным mathX и mathY !
                float y = mathY;
                float x = mathX;
                if (y == x + 3 || y == (-x - 5)){
                    section = "Граница";
                }else if (y < x + 3 && y < (-x - 5)){
                    section = "1";
                }else if (y > x + 3 && y > (-x - 5)){
                    section = "2";
                }else if (y > x + 3 && y < (-x - 5)){
                    section = "3";
                }else if (y < x + 3 && y > (-x - 5)){
                    section = "4";
                }

 

                // Обновление текста с координатами точки 
                coordinatesText.setString("Coordinates: (" + std::to_string(x) + ", " + std::to_string(y) + ") Position: " + section);
            }
        }
    }


        // 4 _ Очистка экрана (допишите код)
        window.clear();


        // Отрисовка осей
        window.draw(xAxis);
        window.draw(yAxis);



        // 5 _  Отрисовка графика y1 = 0.5*x (Замените на ваш график)
        drawGraph(window, [](float x) { return -x - 5; }, -10, 10, 30, 100, sf::Color::Blue);

        // 5 _   Отрисовка графика y2 = x * x - 5 (Замените на ваш график)
        drawGraph(window, [](float x) { return x + 3; }, -10, 10, 30, 10, sf::Color::Red);

        // Отрисовка пользовательской точки, если она существует
        if (userPointExists) {
            window.draw(userPoint);
            window.draw(coordinatesText);
        }

        // Отображение нового кадра
        window.display();
    }

    return 0;
}