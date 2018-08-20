
set(INCROOT ${CMAKE_SOURCE_DIR}/include/SFML/Graphics)
set(SRCROOT ${CMAKE_SOURCE_DIR}/src/SFML/Graphics)

# all source files
set(SRC
    ${INCROOT}/Export.h
    ${SRCROOT}/BlendMode.cpp
    ${INCROOT}/BlendMode.h
    ${SRCROOT}/CircleShape.cpp
    ${SRCROOT}/CircleShapeStruct.h
    ${INCROOT}/CircleShape.h
    ${SRCROOT}/Color.cpp
    ${INCROOT}/Color.h
    ${SRCROOT}/ConvertRenderStates.hpp
    ${SRCROOT}/ConvertTransform.hpp
    ${SRCROOT}/ConvexShape.cpp
    ${SRCROOT}/ConvexShapeStruct.h
    ${INCROOT}/ConvexShape.h
    ${SRCROOT}/Font.cpp
    ${SRCROOT}/FontStruct.h
    ${INCROOT}/Font.h
    ${INCROOT}/FontInfo.h
    ${INCROOT}/Glyph.h
    ${SRCROOT}/Image.cpp
    ${SRCROOT}/ImageStruct.h
    ${INCROOT}/Image.h
    ${SRCROOT}/Rect.cpp
    ${INCROOT}/Rect.h
    ${SRCROOT}/RectangleShape.cpp
    ${SRCROOT}/RectangleShapeStruct.h
    ${INCROOT}/RectangleShape.h
    ${SRCROOT}/RenderTexture.cpp
    ${SRCROOT}/RenderTextureStruct.h
    ${INCROOT}/RenderTexture.h
    ${SRCROOT}/RenderWindow.cpp
    ${SRCROOT}/RenderWindowStruct.h
    ${INCROOT}/RenderWindow.h
    ${SRCROOT}/Shader.cpp
    ${SRCROOT}/ShaderStruct.h
    ${INCROOT}/Shader.h
    ${SRCROOT}/Shape.cpp
    ${SRCROOT}/ShapeStruct.h
    ${INCROOT}/Shape.h
    ${SRCROOT}/Sprite.cpp
    ${SRCROOT}/SpriteStruct.h
    ${INCROOT}/Sprite.h
    ${SRCROOT}/Text.cpp
    ${SRCROOT}/TextStruct.h
    ${INCROOT}/Text.h
    ${SRCROOT}/Texture.cpp
    ${SRCROOT}/TextureStruct.h
    ${INCROOT}/Texture.h
    ${SRCROOT}/Transform.cpp
    ${INCROOT}/Transform.h
    ${SRCROOT}/Transformable.cpp
    ${SRCROOT}/TransformableStruct.h
    ${INCROOT}/Transformable.h
    ${INCROOT}/Types.h
    ${INCROOT}/Vertex.h
    ${SRCROOT}/VertexArray.cpp
    ${SRCROOT}/VertexArrayStruct.h
    ${INCROOT}/VertexArray.h
    ${INCROOT}/VertexBuffer.h
    ${SRCROOT}/VertexBuffer.cpp
    ${SRCROOT}/VertexBufferStruct.h
    ${SRCROOT}/View.cpp
    ${SRCROOT}/ViewStruct.h
    ${INCROOT}/View.h
)

# define the csfml-graphics target
csfml_add_library(csfml-graphics
                  SOURCES ${SRC}
                  DEPENDS sfml-graphics)
