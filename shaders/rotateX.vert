in vec3 vertexPosition;
in vec3 vertexColor;

uniform float Time;
uniform float xs=2.0, zs=10.0; // frequencies
uniform float h=1.0; // height scale

uniform mat4 projectionMatrix;
uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
mat4 modelViewMatrix = viewMatrix*modelMatrix;

uniform mat3 normalMatrix;

out vec4 color;

mat4 RotateX(float alpha){
    return mat4(1,0,0,0,
                0, cos(alpha), sin(alpha),0,
                0, -sin(alpha), cos(alpha),0,
                 0, 0, 0, 1);
}

void main()
{
    color=vec4(1,0,1,1);
    float factorx = 1.;
    float factorz = 5.;
    float ltime = 2.*Time;
    vec4 t = vec4(vertexPosition,1.);

   t=t*RotateX(25*ltime);

    gl_Position = projectionMatrix*modelViewMatrix*t;
}

