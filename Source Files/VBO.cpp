#include<VBO.h>

VBO::VBO(GLfloat* vertices, GLsizeiptr size) {
    // Generate the VBO
    glGenBuffers(1, &ID);
    // Bind the VBO to the GL_ARRAY_BUFFER target
    glBindBuffer(GL_ARRAY_BUFFER, ID);
    // Upload the vertex data to the VBO
    glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

void VBO::Bind() {
    // Bind the VBO to the GL_ARRAY_BUFFER target
    glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void VBO::Unbind() {
    // Unbind the VBO from the GL_ARRAY_BUFFER target
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::Delete() {
    // Delete the VBO
    glDeleteBuffers(1, &ID);
}