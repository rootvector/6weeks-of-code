#include <stdio.h>
#include <raylib.h>

int main(){
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "rootvector");
    SetTargetFPS(60);

    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hello, Rohan", screenWidth/2-30, screenHeight/2-20, 20, LIGHTGRAY);

        EndDrawing();
    }
    CloseWindow();
    return 0;
}
