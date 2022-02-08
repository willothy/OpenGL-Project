
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Renderer.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"
#include "VertexBufferLayout.h"
#include "Texture.h"

// Simply use VertexColor or Basic. Currently, parameters for both are implemented so even though the layouts are different they both work. 
const std::string SHADER { "VertexColor" };

int main(void) {
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    if (glewInit() != GLEW_OK) {
        std::cout << "Error in GLEW init." << std::endl;
    }

    {
        float positions[] = {
            -0.5f, -0.5f, 0.0f, 0.0f,
            1.0f, 0.0f, 0.0f, 1.0f, // Color
            0.5f, -0.5f, 1.0f, 0.0f,
            0.0f, 1.0f, 0.0f, 1.0f, // Color
            0.5f, 0.5f, 1.0f, 1.0f,
            0.0f, 0.0f, 1.0f, 1.0f, // Color
            -0.5f, 0.5f, 0.0f, 1.0f,
            1.0f, 0.0f, 1.0f, 1.0f, // Color
        };

        unsigned int indices[] = {
            0, 1, 2,
            2, 3, 0
        };

        GLCall(glEnable(GL_BLEND));
        GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

        //unsigned int vao;
        //GLCall(glGenVertexArrays(1, &vao));
        //GLCall(glBindVertexArray(vao));

        VertexArray va;
        VertexBuffer vb(positions, 4 * 8 * sizeof(float));
        

        VertexBufferLayout layout;
        layout.Push<float>(2);
        layout.Push<float>(2);
        layout.Push<float>(4);
        va.AddBuffer(vb, layout);
        
        //GLCall(glEnableVertexAttribArray(0));
        //GLCall(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0));

        IndexBuffer ib(indices, 6);

        Shader shader("Resources/Shaders/" + SHADER + ".shader");
        shader.Bind();

        // Must have shader bound to set uniforms
        shader.SetUniform4f("u_Color", 1.0f, 0.0f, 0.0f, 1.0f);

        Texture texture("Resources/Textures/rock.png");
        texture.Bind();
        shader.SetUniform1i("u_Texture", 0);
        

        va.Unbind();
        vb.Unbind();
        ib.Unbind();;
        shader.Unbind();

        Renderer renderer;

        float r = 0.0f;
        float increment = 0.05f;

        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(window)) {
            /* Render here */
            renderer.Clear();

            shader.Bind();
            //shader.SetUniform4f("u_Color", r, 0.3f, 0.2f, 1.0f);

            renderer.Draw(va, ib, shader);

            if (r > 1.0f || r < 0.0f)
                increment = -increment;

            r += increment;

            /* Swap front and back buffers */
            glfwSwapBuffers(window);

            /* Poll for and process events */
            glfwPollEvents();
        }
    }

    glfwTerminate();
    return 0;
};