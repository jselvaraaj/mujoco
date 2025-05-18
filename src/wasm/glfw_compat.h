#pragma once
#if defined(__EMSCRIPTEN__)
  #include <GLFW/glfw3.h>
  static inline void mj_request_es_context() {
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
  }
#else
  static inline void mj_request_es_context() {}
#endif
