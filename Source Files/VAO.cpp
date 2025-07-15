#include"VAO.h"

VAO::VAO() {
    // Generate the VAO
    glGenVertexArrays(1, &ID);
}

void VAO::LinkVBO(VBO& vbo, GLuint layout) {
    // Bind the VBO to the GL_ARRAY_BUFFER target
    vbo.Bind();
    // Specify the layout of the vertex data in the VBO
    glVertexAttribPointer(layout, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    // Enable the vertex attribute so OpenGL knows to use it
    glEnableVertexAttribArray(layout);
}