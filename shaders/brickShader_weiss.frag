//in vec4 color;
in vec2 pos;
in vec2 brickSizeFrag;

uniform float Time;

out vec4 fragColor;

void main()
{

    vec2 useBrick;

    vec2 newPosition = pos/brickSizeFrag;

       if(fract(newPosition.y*0.5f)>0.5f){

           newPosition.x+=0.5f;
       }

       newPosition=fract(newPosition);

       useBrick=step(newPosition, vec2(0.9f, 0.85f));

       vec4 color= vec4(0.,1.,1.,1.);

       vec3 tempColor = color.xyz*(sin(Time*10));

       tempColor = mix(tempColor, vec3(1,1,1) , useBrick.x*useBrick.y);
                        //mix(HintergrundFarbe, BrickFarbe, Faktor)


       fragColor =  vec4(tempColor, 1.0);



}
