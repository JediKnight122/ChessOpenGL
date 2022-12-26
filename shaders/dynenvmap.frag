uniform float hastextureMap0=0.0f;
uniform samplerCube textureMap0;
uniform mat4 modelViewMatrix;

in vec3 eyeN;
in vec3 eyeVertex;
in vec3 temptc;
in vec2 vertTexCoords;
in vec3 refl;
out vec4 fragColor;

void main()
{
    if(hastextureMap0 > 0.5)
    {
        vec3 normEyeN = normalize(eyeN);
        vec3 normEyeVertex = normalize(eyeVertex);
        vec3 lTC;

        //Refraktion (Brechung) geht genau so, dann refract() verwenden
        vec3 eyeReflected = vec3(inverse(modelViewMatrix)*vec4(reflect(normEyeVertex, normEyeN),0.0));

        vec4 textureFrag = texture(textureMap0, refl);
//        lTC = 0.5*vec3(vertTexCoords.x, -2.0, vertTexCoords.y);
        lTC = temptc;
        textureFrag = texture(textureMap0, lTC);
        fragColor = vec4(textureFrag.rgb, textureFrag.a);
    }
    else
        fragColor = vec4(1.,0.,0.,1.);
}
