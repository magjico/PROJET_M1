#include "mainwindow.h"

#include <iostream>

static int draw_value = GL_FILL;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

MainWindow::MainWindow()
{
    const GLFWvidmode * mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    width   = mode->width;
    height  = mode->height;

    window = glfwCreateWindow(width, height, "LearnOpenGL", NULL, NULL);
    if (window == NULL){
        glfwTerminate();
        throw "Failed to create GLFW window";
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetKeyCallback(window, key_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        throw "Failed to initialize GLAD";
}

MainWindow::~MainWindow()
{
    glfwTerminate();
}

void MainWindow::draw(OpenglObject* obj)
{
    while (!glfwWindowShouldClose(window)){
        processInput(window);
        glPolygonMode(GL_FRONT_AND_BACK, draw_value);

        obj->draw();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

int MainWindow::activate(unsigned int numdemo)
{
    OpenglObject* obj;
    std::vector<std::vector<glm::vec3>> checkpoint = {
                {
                    glm::vec3(-0.8f,   -0.4f,  0.8f),
                    glm::vec3(-0.85f,  -0.3f,  0.3f),
                    glm::vec3(-0.825f, -0.1f, -0.3f),
                    glm::vec3(-0.9f,    0.2f, -0.8f)
                },
                {
                    glm::vec3(-0.2f,  -0.35f,  0.8f),
                    glm::vec3(-0.25f, -0.25f,  0.3f),
                    glm::vec3(-0.225f,-0.05f, -0.3f),
                    glm::vec3(-0.3f,   0.25f, -0.8f)
                },
                {
                    glm::vec3(0.4f,   -0.4f,  0.8f),
                    glm::vec3(0.35f,  -0.3f,  0.3f),
                    glm::vec3(0.375f, -0.1f, -0.3f),
                    glm::vec3(0.3f,    0.2f, -0.8f)
                },
                {
                    glm::vec3(0.8f,   -0.3f,  0.8f),
                    glm::vec3(0.75f,  -0.2f,  0.3f),
                    glm::vec3(0.775f,  0.f,  -0.3f),
                    glm::vec3(0.7f,    0.3f, -0.8f)
                }
            };
    switch(numdemo){
        case 0:
            std::cout << "blank window demo" << std::endl;
            obj = new OpenglObject();
            draw(obj);
            break;
        case 1:
            std::cout << "Hello Triangle" << std::endl;
            try {
                obj = new SimpleTriangle();
                draw(obj);
            }
            catch (const char* err) {
                std::cout << err << std::endl;
                return -1;
            }
            break;
        case 2:
            std::cout << "Hello Bezier" << std::endl;
            
            try {
                obj = new BesierSurface(checkpoint, 10, 12);
                draw(obj);
            } catch (const char* err) {
                std::cout << err << std::endl;
                return -1;
            }
            break;
        default:
            std::cout << "No others demo" << std::endl;
    }
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ENTER && action == GLFW_PRESS) 
        draw_value = (draw_value == GL_LINE ? GL_FILL : GL_LINE);
}