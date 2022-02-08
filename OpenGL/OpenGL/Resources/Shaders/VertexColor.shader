#shader vertex
#version 330 core

layout(location = 0) in vec4 position;
layout(location = 2) in vec4 vertexColor;

out vec4 v_VertexColor;

void main()
{
    gl_Position = position;
    v_VertexColor = vertexColor;
};


#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

in vec4 v_VertexColor;

void main()
{
    color = v_VertexColor;
};