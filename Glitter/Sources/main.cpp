// System Headers
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

GLFWwindow* window;

void init( void );
void loop( void );

void run( void )
{
    init( );
    loop( );

    glfwTerminate( );
}

static void key_callback(GLFWwindow* window, int key, int scancode, 
    int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

void init( void )
{
    // Initialize GLFW. Most GLFW functions will not work before doing this.
    if ( !glfwInit( ) )
    {
        throw;
    }

    // Configure GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    // Create the window
    window = glfwCreateWindow(800, 600, "Hello World!", nullptr, nullptr);
    if (window == nullptr)
    {
        std::cerr << "Failed to create the GLFW window" << std::endl;
        throw;
    }

    // Setup a key callback. It will be called every time a key is pressed, repeated or released.
    glfwSetKeyCallback(window, key_callback);

        // Make the OpenGL context current
    glfwMakeContextCurrent(window);

    // Enable v-sync
    glfwSwapInterval(1);

    // Make the window visible
    glfwShowWindow(window);

    gladLoadGL();
}

void loop( void )
{
    while (!glfwWindowShouldClose(window))
    {
        // Poll for window events. The key callback above will only be
        // invoked during this call.
        glfwPollEvents();

        // render
        // ------
        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window); // swap the color buffers
    }
}

int main(int, char**)
{
    run( );

    return 0;
}
