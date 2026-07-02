#include <raylib.h>
#include <stdio.h>

int main(){
    const int screenWidth = 800;
    const int screenHeight = 450;

    Vector2 ballPosition;
    Color ballColor = GREEN;
    InitWindow(screenWidth, screenHeight, "Mouse Input");

    SetTargetFPS(60);

    while(!WindowShouldClose()){

        if(IsKeyPressed(KEY_H)){
            if(IsCursorHidden()) ShowCursor();
            else HideCursor();
        }

        ballPosition = GetMousePosition();


        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) ballColor = MAROON;
        else if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) { ballColor = LIME;
                                                            printf("Mouse Position %f %f\n", ballPosition.x, ballPosition.y);
        }

        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawCircleV(ballPosition, 20, ballColor);

            DrawText("Move Ball with mouse and click mouse button to change color", 10, 10, 20, DARKGRAY);
            
            if(IsCursorHidden()) DrawText("CURSOR HIDDEN", 20, 60, 20, RED);
            else DrawText("CURSOR VISIBLE", 20, 60, 20, LIME);

        EndDrawing();

    }

    CloseWindow();
    return 0;
}
