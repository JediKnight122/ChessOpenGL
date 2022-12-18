in vec4 color;
in vec2 pos;
in vec2 brickSizeFrag;


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

       vec3 tempColor = color.xyz;
       tempColor = mix(tempColor, vec3(0,0.2,0.1) , useBrick.x*useBrick.y);
                        //mix(HintergrundFarbe, BrickFarbe, Faktor)


       fragColor =  vec4(tempColor, 1.0);



}
