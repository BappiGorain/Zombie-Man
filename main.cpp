#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
    VideoMode vm(1920, 1080);
    RenderWindow window(vm, "Zombie-Man", Style::Fullscreen);

    // Texture background;
    // background.loadFromFile("graphics/background_sheet.png");
    // Sprite spriteBackground;
    // spriteBackground.setTexture(background);
    // spriteBackground.setPosition(0,0);

    VertexArray background;
    Texture textureBackground;
    textureBackground.loadFromFile("graphics/background_sheet.png");

    //     background[0].position = Vector2f(0, 0);
    //     background[1].position = Vector2f(49, 0);
    //     background[2].position = Vector2f(49,49);
    //     background[3].position = Vector2f(0, 49);

    //     background[0].texCoords = Vector2f(0, 0);
    //     background[1].texCoords = Vector2f(49, 0);
    //     background[2].texCoords = Vector2f(49, 49);
    //     background[3].texCoords = Vector2f(0, 49);

    //     background[0].texCoords = Vector2f(0, 50);
    // background[1].texCoords = Vector2f(49, 50);
    // background[2].texCoords = Vector2f(49, 99);
    // background[3].texCoords = Vector2f(0, 99);

    const int TILE_SIZE = 50;
    const int TILE_TYPES = 3;
    const int VERTS_IN_QUAD = 4;
    int worldWidth = window.getSize().x / TILE_SIZE;
    int worldHeight = window.getSize().y / TILE_SIZE;
    // What type of primitive are we using?
    background.setPrimitiveType(Quads);
    // Set the size of the vertex array
    background.resize(worldWidth * worldHeight * VERTS_IN_QUAD);
    // Start at the beginning of the vertex array
    int currentVertex = 0;

    for (int w = 0; w < worldWidth; w++)
    {
        for (int h = 0; h < worldHeight; h++)
        {
            // Position each vertex in the current quad
            background[currentVertex + 0].position = Vector2f(w * TILE_SIZE, h * TILE_SIZE);
            background[currentVertex + 1].position = Vector2f((w * TILE_SIZE) + TILE_SIZE, h * TILE_SIZE);
            background[currentVertex + 2].position = Vector2f((w * TILE_SIZE) + TILE_SIZE, (h * TILE_SIZE) + TILE_SIZE);
            background[currentVertex + 3].position = Vector2f((w * TILE_SIZE), (h * TILE_SIZE) + TILE_SIZE);
            // Position ready for the next four vertices
            currentVertex = currentVertex + VERTS_IN_QUAD;
        }
    }

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }
        window.clear();

        window.draw(background, &textureBackground);

        window.display();
    }

    return 0;
}