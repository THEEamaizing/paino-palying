#include <iostream>
#include <conio.h> // For _getch() on Windows
#include <vector>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

using namespace std;

// Game dimensions
const int WIDTH = 20;
const int HEIGHT = 20;

// Snake structure
struct Point {
    int x, y;
};

// Game variables
vector<Point> snake;
Point food;
int score;
bool gameOver;
enum Direction { UP, DOWN, LEFT, RIGHT };
Direction dir;

// Function to initialize the game
void setup() {
    gameOver = false;
    dir = RIGHT;
    snake.clear();
    snake.push_back({WIDTH / 2, HEIGHT / 2}); // Initial snake position
    score = 0;

    // Seed the random number generator
    srand(time(0));

    // Generate initial food position
    food.x = rand() % (WIDTH - 2) + 1;
    food.y = rand() % (HEIGHT - 2) + 1;
}

// Function to draw the game board
void draw() {
    system("cls"); // Clear the console (Windows)
    for (int i = 0; i < WIDTH + 2; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < HEIGHT; i++) {
        cout << "#";
        for (int j = 0; j < WIDTH; j++) {
            bool isSnake = false;
            for (auto &p : snake) {
                if (p.x == j && p.y == i) {
                    cout << "O";
                    isSnake = true;
                    break;
                }
            }
            if (j == food.x && i == food.y)
                cout << "@";
            else if (!isSnake)
                cout << " ";
        }
        cout << "#" << endl;
    }

    for (int i = 0; i < WIDTH + 2; i++)
        cout << "#";
    cout << endl;
    cout << "Score: " << score << endl;
}

// Function to handle user input
void input() {
    if (_kbhit()) { // Check if a key is pressed
        switch (_getch()) {
            case 'w': if(dir != DOWN) dir = UP; break;
            case 's': if(dir != UP) dir = DOWN; break;
            case 'a': if(dir != RIGHT) dir = LEFT; break;
            case 'd': if(dir != LEFT) dir = RIGHT; break;
        }
    }
}

// Function to update the game logic
void logic() {
    Point head = snake[0];
    switch (dir) {
        case UP: head.y--; break;
        case DOWN: head.y++; break;
        case LEFT: head.x--; break;
        case RIGHT: head.x++; break;
    }

    // Check for collision with walls
    if (head.x < 0 || head.x >= WIDTH || head.y < 0 || head.y >= HEIGHT) {
        gameOver = true;
    }

    // Check for collision with itself
    for (int i = 1; i < snake.size(); i++) {
        if (head.x == snake[i].x && head.y == snake[i].y) {
            gameOver = true;
            break;
        }
    }

    if (head.x == food.x && head.y == food.y) {
        score++;
        food.x = rand() % (WIDTH - 2) + 1;
        food.y = rand() % (HEIGHT - 2) + 1;
        snake.insert(snake.begin(), head); // Grow the snake
    } else {
        snake.insert(snake.begin(), head);
        snake.pop_back(); // Move the snake
    }
}

int main() {
    setup();
    while (!gameOver) {
        draw();
        input();
        logic();
        // Add a small delay to control game speed (optional)
        // For Windows: Sleep(100);  // Include <windows.h>
        // For Linux/macOS: usleep(100000); // Include <unistd.h>
    }
    cout << "Game Over!" << endl;
    return 0;
}