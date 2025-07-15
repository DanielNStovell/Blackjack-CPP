#ifndef EBO_CLASS_H
#define EBO_CLASS_H

#include<glad/glad.h>

class EBO {
    public:
        GLuint ID;

        // Constructor that generates an Element Buffer Object and links it to indices
        EBO(GLuint* indices, GLsizeiptr size) {
            // Generate the EBO
            glGenBuffers(1, &ID);
            // Bind the EBO to the GL_ELEMENT_ARRAY_BUFFER target
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
            // Upload the index data to the EBO
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
        }

        void Bind() {
            // Bind the EBO to the GL_ELEMENT_ARRAY_BUFFER target
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
        }

        void Unbind() {
            // Unbind the EBO from the GL_ELEMENT_ARRAY_BUFFER target
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        }

        void Delete() {
            // Delete the EBO
            glDeleteBuffers(1, &ID);
        }
};

#endif // EBO_CLASS_H