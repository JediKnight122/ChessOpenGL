in vec4 vertexPosition;
in vec3 vertexNormal;
in vec4 vertexColor;
in vec2 textureCoords;

uniform mat4 projectionMatrix;
uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat3 normalMatrix;

mat4 modelViewMatrix = viewMatrix*modelMatrix;

out vec3 eyeN;
out vec3 eyeVertex;
out vec3 temptc;
out vec2 vertTexCoords;
out vec3 refl;


void main()
{
    eyeVertex = normalize(vec3(modelViewMatrix*vertexPosition)); //Entspricht dem Vektor von Kamera zum Vertex im KKS
    eyeN = normalize(normalMatrix * vertexNormal);
    gl_Position = projectionMatrix*modelViewMatrix*vertexPosition;
    refl = reflect(eyeVertex, eyeN);

    //Die Koordinatenachsen bei OpenGL Cubemaps stimmen nicht mit den typischen Cubemaps (Renderman, DirectX, ...) überein
    //siehe hierzu GLSpec 4.5 Core, Seite 240

    temptc = vec3(vertexPosition.x, vertexPosition.yz);
    vertTexCoords = textureCoords;
}
