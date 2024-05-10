#include "raylib.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <memory.h>
#include "Mab/Mab.h"
#include "invoke.h"
#include "analyser.h"

#define MAX_INPUT_CHARS  50
#define MAX_LENGTH 1024

void get_res(char * cmd , char *buff , Mab *commands){

   int  stdout_bk; //is fd for stdout backup

   
   stdout_bk = dup(fileno(stdout));

   int pipefd[2];
   pipe2(pipefd, 0); // O_NONBLOCK);

   // What used to be stdout will now go to the pipe.
   dup2(pipefd[1], fileno(stdout));

   handle_command(cmd , commands);
   fflush(stdout);//flushall();
   
   close(pipefd[1]);

   dup2(stdout_bk, fileno(stdout));

   read(pipefd[0], buff, MAX_LENGTH); 

}
int main(void)
{
    #define BACKGROUND  CLITERAL(Color){ 35, 37, 45}
    
    char path[MAX_LENGTH];
    
    Mab commands;
    init_mab(&commands);
    extract_lines(&commands);
    
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1800;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "Shell");

    char name[MAX_INPUT_CHARS + 1] = "\0";      // NOTE: One extra space required for null terminator char '\0'
    int letterCount = 0;

    Rectangle textBox = { 10 , 50, screenWidth - 100, 50 };
    bool mouseOnText = false;

    int framesCounter = 0;

    SetTargetFPS(60);               
    
    
    
    Font out_font = LoadFont("./resoures/fonts/RobotoMono-Medium.ttf");
    char buff[1024] = {0};


    while (!WindowShouldClose())    
    {
       
        if (CheckCollisionPointRec(GetMousePosition(), textBox)) mouseOnText = true;
        else mouseOnText = false;

        if (mouseOnText)
        {
            // Set the window's cursor to the I-Beam
            SetMouseCursor(MOUSE_CURSOR_IBEAM);

            // Get char pressed (unicode character) on the queue
            int key = GetCharPressed();

            // Check if more characters have been pressed on the same frame
            while (key > 0)
            {
                // NOTE: Only allow keys in range [32..125]
                if ((key >= 32) && (key <= 125) && (letterCount < MAX_INPUT_CHARS))
                {
                    name[letterCount] = (char)key;
                    name[letterCount+1] = '\0'; // Add null terminator at the end of the string.
                    letterCount++;
                }

                key = GetCharPressed();  // Check next character in the queue
            }

            if (IsKeyPressed(KEY_BACKSPACE))
            {
                letterCount--;
                if (letterCount < 0) letterCount = 0;
                name[letterCount] = '\0';
            }
        }
        else SetMouseCursor(MOUSE_CURSOR_DEFAULT);

        if (mouseOnText) framesCounter++;
        else framesCounter = 0;
        
        

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(BACKGROUND);

            //DrawText("PLACE MOUSE OVER INPUT BOX!", 240, 140, 20, GRAY);

            DrawRectangleRec(textBox, LIGHTGRAY);
            if (mouseOnText) DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, RED);
            else DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, DARKGRAY);

            DrawText(name, (int)textBox.x + 5, (int)textBox.y + 8, 40, MAROON);
            getcwd(path, sizeof(path));

            DrawText(TextFormat("INPUT CHARS: %i/%i", letterCount, MAX_INPUT_CHARS), 100, 10, 20, ORANGE);
            DrawText(TextFormat("path = %s", path), 400, 10, 20, ORANGE);

            if (mouseOnText)
            {
                if (letterCount < MAX_INPUT_CHARS)
                {
                    // Draw blinking underscore char
                    if (((framesCounter/20)%2) == 0) DrawText("_", (int)textBox.x + 8 + MeasureText(name, 40), (int)textBox.y + 12, 40, MAROON);
                }
                // else DrawText("Press BACKSPACE to delete chars...", 230, 300, 20, GRAY);
            }
            
            
            if(IsKeyPressed(KEY_ENTER)){
            	fflush(stdout);
            	memset(buff, 0,sizeof(buff)); 
            	get_res( name , buff , &commands);
            	fflush(stdout);
            	letterCount = 0;
            	name[0] = 0; 
        	
            }
            //DrawText(buff, (int)textBox.x + 5, (int)textBox.y + 50, 40, WHITE);
            
            DrawTextEx(out_font, buff, (Vector2){ (int)textBox.x + 5, (int)textBox.y + 60 }, 24, 1, WHITE);

        EndDrawing();
        
    }
    UnloadFont(out_font);

    CloseWindow();    
        

    return 0;
}



bool IsAnyKeyPressed()
{
    bool keyPressed = false;
    int key = GetKeyPressed();

    if ((key >= 32) && (key <= 126)) keyPressed = true;

    return keyPressed;
}
