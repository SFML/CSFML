set(INCROOT ${PROJECT_SOURCE_DIR}/include/CSFML/Graphics)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/CSFML/Graphics)

# all source files
set(SRC
    ${INCROOT}/Export.h
    ${SRCROOT}/BlendMode.cpp
    ${INCROOT}/BlendMode.h
    ${SRCROOT}/CircleShape.cpp
    ${SRCROOT}/CircleShapeStruct.hpp
    ${INCROOT}/CircleShape.h
    ${SRCROOT}/Color.cpp
    ${INCROOT}/Color.h
    ${SRCROOT}/ConvertColor.hpp
    ${SRCROOT}/ConvertRect.hpp
    ${SRCROOT}/ConvertRenderStates.hpp
    ${SRCROOT}/ConvertTransform.hpp
    ${SRCROOT}/ConvexShape.cpp
    ${SRCROOT}/ConvexShapeStruct.hpp
    ${INCROOT}/ConvexShape.h
    ${SRCROOT}/Font.cpp
    ${SRCROOT}/FontStruct.hpp
    ${INCROOT}/Font.h
    ${INCROOT}/FontInfo.h
    ${INCROOT}/Glyph.h
    ${SRCROOT}/Image.cpp
    ${SRCROOT}/ImageStruct.hpp
    ${INCROOT}/Image.h
    ${SRCROOT}/Rect.cpp
    ${INCROOT}/Rect.h
    ${SRCROOT}/RectangleShape.cpp
    ${SRCROOT}/RectangleShapeStruct.hpp
    ${INCROOT}/RectangleShape.h
    ${SRCROOT}/RenderStates.cpp
    ${SRCROOT}/RenderTexture.cpp
    ${SRCROOT}/RenderTextureStruct.hpp
    ${INCROOT}/RenderTexture.h
    ${SRCROOT}/RenderWindow.cpp
    ${SRCROOT}/RenderWindowStruct.hpp
    ${INCROOT}/RenderWindow.h
    ${SRCROOT}/Shader.cpp
    ${SRCROOT}/ShaderStruct.hpp
    ${INCROOT}/Shader.h
    ${SRCROOT}/Shape.cpp
    ${SRCROOT}/ShapeStruct.hpp
    ${INCROOT}/Shape.h
    ${SRCROOT}/Sprite.cpp
    ${SRCROOT}/SpriteStruct.hpp
    ${INCROOT}/Sprite.h
    ${SRCROOT}/Text.cpp
    ${SRCROOT}/TextStruct.hpp
    ${INCROOT}/Text.h
    ${SRCROOT}/Texture.cpp
    ${SRCROOT}/TextureStruct.hpp
    ${INCROOT}/Texture.h
    ${SRCROOT}/Transform.cpp
    ${INCROOT}/Transform.h
    ${SRCROOT}/Transformable.cpp
    ${SRCROOT}/TransformableStruct.hpp
    ${INCROOT}/Transformable.h
    ${INCROOT}/Types.h
    ${INCROOT}/Vertex.h
    ${SRCROOT}/VertexArray.cpp
    ${SRCROOT}/VertexArrayStruct.hpp
    ${INCROOT}/VertexArray.h
    ${INCROOT}/VertexBuffer.h
    ${SRCROOT}/VertexBuffer.cpp
    ${SRCROOT}/VertexBufferStruct.hpp
    ${SRCROOT}/View.cpp
    ${SRCROOT}/ViewStruct.hpp
    ${INCROOT}/View.h
)

# define the csfml-graphics target
csfml_add_library(csfml-graphics
                  SOURCES ${SRC}
                  DEPENDS SFML::Graphics)
