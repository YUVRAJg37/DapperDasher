#include "raylib.h"

int main()
{
    const int width{512};
    const int height{380};

    InitWindow(width, height, "main");

    // const int recWidth{50};
    // const int recheight{80};

    const int gravity{1000};
    const int jumpvelocity{-600};
    bool isInAir = false;

    int velocity{0};
    int frame{};
    const float updateTime{1.0 / 12.0};
    float runningTime{};

    // int posY{height - recheight};

    Texture2D scarfy = LoadTexture("textures/scarfy.png");
    Rectangle recScarfy;

    recScarfy.height = scarfy.height;
    recScarfy.width = scarfy.width / 6;
    recScarfy.x = 0;
    recScarfy.y = 0;

    Vector2 posScarfy;
    posScarfy.x = (width / 2) - (recScarfy.width / 2);
    posScarfy.y = (height) - (recScarfy.width);

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();

        runningTime += dt;

        BeginDrawing();

        ClearBackground(WHITE);

        DrawTextureRec(scarfy, recScarfy, posScarfy, WHITE);

        if (posScarfy.y >= height - recScarfy.height)
        {

            isInAir = false;
            velocity = 0;
        }
        else
        {
            isInAir = true;
            velocity += gravity * dt;
        }

        if (IsKeyPressed(KEY_SPACE) && !isInAir)
        {
            velocity = jumpvelocity;
        }

        posScarfy.y += velocity * dt;

        if (runningTime >= updateTime)
        {
            runningTime = 0.0f;
            recScarfy.x = frame * recScarfy.width;
            frame++;

            if (frame > 5)
            {
                frame = 0;
            }
        }

        EndDrawing();
    }
    UnloadTexture(scarfy);
    CloseWindow();
}
