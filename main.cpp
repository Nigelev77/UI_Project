#include "editor_config.h"

#include <GLAD/glad.h>

#include "libs/GLFW/glfw3.h"
#include <gl/gl.h>
#include <iostream>
#include "shader_core.h"


void processInput(GLFWwindow *window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, true);
  }
}

const float triangles[] = {-0.5f, 0.0f, 0.0f, 0.0f, 0.5f,
                           0.0f,  0.5f, 0.0f, 0.0f};

const GLuint indices[] = {0, 1, 2};

int main(int argc, char *argv[]) {
  std::cout << "Hello World";

  int success = glfwInit();
  if (!success) {
    return -1;
  }

  GLFWwindow *window = glfwCreateWindow(640, 900, "Hello World", NULL, NULL);
  









  glfwMakeContextCurrent(window);
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to init GLAD\n";
    return -1;
  }
  glViewport(0, 0, 2560, 1280);


  // Shader shader = CreateShader("ui");
  // BindShader(shader.id);
  Shader shader = CreateShader("ui");
  LoadShader(shader.progID);







  GLuint vao;
  glGenVertexArrays(1, &vao);

  GLuint vbo;
  glGenBuffers(1, &vbo);
  GLuint ibo;
  glGenBuffers(1, &ibo);

  glBindVertexArray(vao);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(float) * sizeof(triangles), triangles,
               GL_STATIC_DRAW);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * sizeof(indices),
               indices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, false, 0, 0);
  glEnableVertexAttribArray(0);

// UI_Box* box = UI_BoxCreate();
// box.addText("Some Text");
// box.addBackground("Blue");
// box.setLayout(UI_FILL, 1.0f);
// 
// 
// 
// 

  while (!glfwWindowShouldClose(window)) {

    processInput(window);
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glDrawElements(GL_TRIANGLES, sizeof(triangles), GL_UNSIGNED_INT, 0);
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
