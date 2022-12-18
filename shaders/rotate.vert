in vec3 vertexPosition;
in vec3 vertexColor;

uniform float Time=0.5f;
uniform float xs=2.0, zs=10.0; // frequencies
uniform float h=1.0; // height scale

uniform mat4 projectionMatrix;
uniform mat4 modelMatrix;
uniform mat4 viewMatrix;


uniform mat3 normalMatrix;
mat4 modelViewMatrix = viewMatrix*modelMatrix;

//Custom Uniforms

uniform vec3 rotationVec = vec3(0,0,1);
uniform vec4 colorInput = vec4(1,1,1,1);

out vec4 color;

mat4 Rotate(float alpha, vec3 axes){

    if(axes.x==1) {
    return mat4(1,0,0,0,
                0, cos(alpha), sin(alpha),0,
                0, -sin(alpha), cos(alpha),0,
                 0, 0, 0, 1);
    }
    else if(axes.y==1){
        return mat4(
                     cos(alpha),0,  -sin(alpha),0,
                     0,         1,  0,          0,
                     sin(alpha),0, cos(alpha),  0,
                     0,         0,  0,          1
                                                );
    }
    else {
        return mat4(
                cos(alpha), sin(alpha),  0  ,0,
                -sin(alpha), cos(alpha),0,  0,
                0,          0,          1,  0,
                0,          0,          0,  1
                                           );
         }
}

void main()
{



    float factorx = 1.;
    float factorz = 5.;
    float ltime = 2.*Time;
    vec4 t = vec4(vertexPosition,1.);

    t=Rotate(25*ltime, rotationVec)*t;

   // t=t*Rotate(25*ltime, vec3(1,0,0)); //Feste Achse ohne Uniform

    gl_Position = projectionMatrix*modelViewMatrix*t;

    color=vec4(Time,0,1,1);
}

