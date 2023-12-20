#include <SFML/Audio.h>
#include <SFML/Graphics.h>

#include <stdlib.h>

int main(void)
{
    // Create the main window
    const sfVideoMode mode = {800, 600, 32};
    sfRenderWindow* window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);
    if (!window)
        return EXIT_FAILURE;

    // Load a sprite to display
    sfTexture* texture = sfTexture_createFromFile("sfml_logo.png", NULL);
    if (!texture)
    {
        sfRenderWindow_destroy(window);
        return EXIT_FAILURE;
    }
    sfSprite* sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    const sfVector2f spritePosition = {200, 200};
    sfSprite_setPosition(sprite, spritePosition);

    // Create a graphical text to display
    sfFont* font = sfFont_createFromFile("tuffy.ttf");
    if (!font)
    {
        sfSprite_destroy(sprite);
        sfTexture_destroy(texture);
        sfRenderWindow_destroy(window);
        return EXIT_FAILURE;
    }
    sfText* text = sfText_create();
    sfText_setString(text, "Hello, SFML!");
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 50);

    // Load a music to play
    sfMusic* music = sfMusic_createFromFile("doodle_pop.ogg");
    if (!music)
    {
        sfText_destroy(text);
        sfFont_destroy(font);
        sfSprite_destroy(sprite);
        sfTexture_destroy(texture);
        sfRenderWindow_destroy(window);
        return EXIT_FAILURE;
    }

    // Play the music
    sfMusic_play(music);

    // Start the game loop
    sfEvent event;
    while (sfRenderWindow_isOpen(window))
    {
        // Process events
        while (sfRenderWindow_pollEvent(window, &event))
        {
            // Close window : exit
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }

        // Clear the screen
        sfRenderWindow_clear(window, sfBlack);

        // Draw the sprite
        sfRenderWindow_drawSprite(window, sprite, NULL);

        // Draw the text
        sfRenderWindow_drawText(window, text, NULL);

        // Update the window
        sfRenderWindow_display(window);
    }

    // Cleanup resources
    sfMusic_destroy(music);
    sfText_destroy(text);
    sfFont_destroy(font);
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    sfRenderWindow_destroy(window);

    return EXIT_SUCCESS;
}
