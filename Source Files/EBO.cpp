#include"EBO.h"

EBO::EBO(GLuint* indices, GLsizeiptr size) {
    // Generate the EBO
    glGenBuffers(1, &ID);
    // Bind the EBO to the GL_ELEMENT_ARRAY_BUFFER target
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
    // Upload the index data to the EBO
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
}

void EBO::Bind() {
    // Bind the EBO to the GL_ELEMENT_ARRAY_BUFFER target
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
}

void EBO::Unbind() {
    // Unbind the EBO from the GL_ELEMENT_ARRAY_BUFFER target
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void EBO::Delete() {
    // Delete the EBO
    glDeleteBuffers(1, &ID);
}