#shader vertex
#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec2 texCoord;
<<<<<<< Updated upstream
layout(location = 2) in vec4 vertColor;

out vec2 v_TexCoord;
out vec4 v_vertColor;
=======
layout(location = 2) in vec4 vertexColor;

out vec2 v_TexCoord;
out vec4 v_VertexColor;
>>>>>>> Stashed changes

void main()
{
    gl_Position = position;
    v_TexCoord = texCoord;
<<<<<<< Updated upstream
    v_vertColor = vertColor;
=======
    v_VertexColor = vertexColor;
>>>>>>> Stashed changes
};


#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

in vec2 v_TexCoord;
<<<<<<< Updated upstream
in vec4 v_vertColor;
=======
in vec4 v_VertexColor;
>>>>>>> Stashed changes

uniform vec4 u_Color;
uniform sampler2D u_Texture;

void main()
{

    vec4 texColor = texture(u_Texture, v_TexCoord);
<<<<<<< Updated upstream
    color = v_vertColor;
=======
    color = v_VertexColor;
>>>>>>> Stashed changes
};