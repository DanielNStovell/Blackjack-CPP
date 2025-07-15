#ifndef VAO_CLASS_H
#define VAO_CLASS_H

#include<glad/glad.h>
#include<VBO.h>

class VAO {
    public:
        GLuint ID;

        // Constructor that generates a Vertex Array Object and links it to VBO
        VAO() {
            // Generate the VAO
            glGenVertexArrays(1, &ID);
            // Bind the VAO to the GL_VERTEX_ARRAY target
            glBindVertexArray(ID);
        }

        void LinkVBO(VBO& vbo, GLuint layout) {
            // Bind the VBO to the GL_ARRAY_BUFFER target
            vbo.Bind();
            // Specify the layout of the vertex data in the VBO
            glVertexAttribPointer(layout, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
            // Enable the vertex attribute so OpenGL knows to use it
            glEnableVertexAttribArray(layout);
        }

        void Bind() {
            // Bind the VAO to the GL_VERTEX_ARRAY target
            glBindVertexArray(ID);
        }

        void Unbind() {
            // Unbind the VAO from the GL_VERTEX_ARRAY target
            glBindVertexArray(0);
        }

        void Delete() {
            // Delete the VAO
            glDeleteVertexArrays(1, &ID);
        }
};

#endif