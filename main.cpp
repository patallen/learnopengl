#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const char* APP_NAME = "Learn OpenGL";

// Forward declaration of helpers... for cleanliness or whatever.
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);


/**
 * For the time-being, this is where the magic happens.
 * */
int main() {

    // Initialize the GLFW Windoww.
    glfwInit();

    // Configure the window by telling GLFW what values to hold for specific Enums.
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // Create the actual GLFW Window with (width, height, title.
    // The NULLs here are for passing optional(?) GLFWmonitor and GLFWwindow objects.
    GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, APP_NAME, NULL, NULL);

    if (window == NULL)
    {
        std::cout << "Failed to create the window." << std::endl;
        glfwTerminate();
        return -1;
    }

    // Make this window the main context on this thread.
    glfwMakeContextCurrent(window);

    // Set the resize callback we defined above.
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Initialize GLAD. Glad is the library that handles all the OpenGL pointers for us.
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // Program/Event loop! Keeps the window from just closing immediately after entry.
    // Every iteration of this loop we:
    //  - Process user input using function defined above.
    //  - Set the clear color, and clear the buffer based on which "buffer bit" we pass.
    //  - Swap the 'back/front' buffers to update the screen
    //  - Poll for events - This is even necessary for the window to open.
    while(!glfwWindowShouldClose(window))
    {
        processInput(window);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Finally, make sure we clean up after our sloppy-selves.
    glfwTerminate();

    return 0;
}

/**
 * Callback to pass to GLFW function `glfwSetFramebufferSizeCallback`.
 * This function is called whenever the user resizes the window. If we
 * don't do so, the viewport within the window will not be re-adjusted.
 */
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
}

/**
 * Here we are just checking to see if the user pressed the escape key.
 * If so, we set the "Should Close" state to true. This will be picked up the
 * next loop iteration by the `glfwWindowShouldClose` call.
 */
void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}


