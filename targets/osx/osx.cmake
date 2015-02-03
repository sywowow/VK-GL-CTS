# OS X Target

set(DEQP_TARGET_NAME	"OS X")

set(DEQP_SUPPORT_OPENGL	ON)

find_package(OpenGL REQUIRED)
set(DEQP_PLATFORM_LIBRARIES ${OPENGL_LIBRARIES})
include_directories(${OPENGL_INCLUDE_DIRS})
