/*
Compile: g++ -std=c++11 "Source Files/main.cpp" "Source Files/glad.c" "Source Files/shaderClass.cpp" -Iinclude -I"Header Files" -I/opt/homebrew/include -L/opt/homebrew/lib -lglfw -framework OpenGL -o compiled_code
Run: ./compiled_code
*/

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "shaderClass.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// Coordinate map is normalised (center of screen is (0, 0))
// This means the right side is x = 1
//                left side is x = -1
//                top side is y = 1
//                bottom side is y = -1
GLfloat vertices[] = {
    -0.1f, -0.3f, 0.0f,
    -0.1f, 0.3f, 0.0f,
    0.1f, -0.3f, 0.0f,
    0.1f, 0.3f, 0.0f
};

GLuint indices[] = {
    0, 1, 2,
    2, 1, 3
};

int main() {
    // Initialise GLFW
    glfwInit();
    
    // Tell what version of GLFW we are using
    // In this case we are using 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    
    // Tell GLFW e are using the CORE profile
    // So that means we only have modern functions
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Initialise dimensions of the window
    int width = 640, height = 360;

    // Create a GLFWwindow object of width x height pixels with the name "Window"
    GLFWwindow* window = glfwCreateWindow(width, height, "Window", NULL, NULL); // Parameters: (width, height, title, fullscreen, smth idk)

    // Check if there is an Error when creating the window
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Introduce the window in the current context
    glfwMakeContextCurrent(window);

    // Load GLAD so it configures OpenGL
    gladLoadGL();

    // Specify the viewport of OpenGL in the window
    // In this case the viewport goes from x = 0, y = 0 to x = width, y = height
    glViewport(0, 0, width, height);

    Shader shaderProgram("Resource Files/Shaders/default.vert", "Resource Files/Shaders/default.frag");

    VAO VAO1;
    VAO1.Bind();

    VBO VBO1(vertices, sizeof(vertices));
    EBO EBO1(indices, sizeof(indices));

    VAO1.LinkVBO(VBO1, 0); // Link the VBO to the VAO at layout 0
    VAO1.Unbind(); // Unbind the VAO so we don't accidentally modify it
    VBO1.Unbind(); // Unbind the VBO so we don't accidentally modify it
    EBO1.Unbind(); // Unbind the EBO so we don't accidentally modify it

    // Main while loop
    while (!glfwWindowShouldClose(window)) { // While the close button is not clicked
        glClearColor(0.039f, 0.6f, 0.0f, 1.0f); // Background Colour 0.039, 0.6, 0
        glClear(GL_COLOR_BUFFER_BIT);

        // Activate the shader program
        shaderProgram.Activate();

        // Set the card color (e.g., white)
        int colorLoc = glGetUniformLocation(shaderProgram.ID, "cardColor");
        glUniform4f(colorLoc, 1.0f, 1.0f, 1.0f, 1.0f); // RGBA: white

        int modelLoc = glGetUniformLocation(shaderProgram.ID, "model");

        // Bind the VAO so OpenGL knows to use it
        VAO1.Bind();
        
        // Drawing multiple cards by translation 
        for (int i = 0; i < 3; ++i) {
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, glm::vec3(-0.5f + i * 0.3f, 0.0f, 0.0f));
            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        }

        glfwSwapBuffers(window);

        // Take care all GLFW events
        glfwPollEvents(); // Processes poll events e.g., window being resized
    }

    // Delete all the object we've created
    VAO1.Delete();
    VBO1.Delete();
    EBO1.Delete();
    shaderProgram.Delete();
    // Delete the window before ending the program
    glfwDestroyWindow(window);

    // Terminate GLFW before exitinendingg the program
    glfwTerminate();
    return 0;
}
