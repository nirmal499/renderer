#include <window/window.hpp>
#include <tool/logger.hpp>

bool Window::init(unsigned int width, unsigned int height, std::string title)
{
  if (!glfwInit())
  {
    Logger::log(1, "%s: glfwInit() error\n", __FUNCTION__);
    return false;
  }

  if (!glfwVulkanSupported())
  {
    glfwTerminate();
    Logger::log(1, "%s error: Vulkan is not supported\n", __FUNCTION__);
    return false;
  }

  /* set a "hint" for the NEXT window created*/
  // glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

  /* Vulkan needs no context */
  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

  m_window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

  if (!m_window)
  {
    Logger::log(1, "%s: Could not create window\n", __FUNCTION__);
    glfwTerminate();
    return false;
  }

  Logger::log(1, "%s: Window successfully initialized\n", __FUNCTION__);

  m_renderer = std::make_unique<MVkRenderer>(m_window);
  if(!m_renderer->init(width, height))
  {
    glfwTerminate();
    Logger::log(1, "%s error: Could not init Vulkan\n", __FUNCTION__);
    return false;
  }

  /* save the pointer m_renderer for later use in lambda functions. m_window is a mandatory parameter in every glfwWindow functions */
  glfwSetWindowUserPointer(m_window, m_renderer.get());

  glfwSetWindowSizeCallback(m_window, [](GLFWwindow* win, int width, int height){
    auto m_renderer_pointer_that_we_saved_earlier = static_cast<MVkRenderer*>(glfwGetWindowUserPointer(win));
    m_renderer_pointer_that_we_saved_earlier->setSize(width, height);
  });

  m_model = std::make_unique<Model>();
  m_model->init();
  
  Logger::log(1, "%s: mockup model data loaded\n", __FUNCTION__);

  Logger::log(1, "%s: Window with Vulkan successfully initialized\n", __FUNCTION__);

  return true;
}

void Window::main_loop()
{

  /* upload only once for now */
  m_renderer->uploadData(m_model->getVertexData());

  glfwSwapInterval(1);
  float color = 0.0f;
  while (!glfwWindowShouldClose(m_window))
  {

    if(!m_renderer->draw())
    {
      /* If draw of m_renderer returns false */
      break;
    }
    /* poll events in a loop */
    glfwPollEvents();

  }
}

void Window::clean_up()
{

  m_renderer->cleanup();
  
  glfwDestroyWindow(m_window);
  glfwTerminate();
  Logger::log(1, "%s: Terminating Window\n", __FUNCTION__);
}