#shader vertex
#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec2 texCoord;
layout(location = 2) in vec4 vertColor;

out vec2 v_TexCoord;
out vec4 v_vertColor;

void main()
{
    gl_Position = position;
    v_TexCoord = texCoord;
    v_vertColor = vertColor;
};


#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

in vec2 v_TexCoord;
in vec4 v_vertColor;

uniform vec4 u_Color;
uniform sampler2D u_Texture;

void main()
{

    vec4 texColor = texture(u_Texture, v_TexCoord);
    color = v_vertColor;
};