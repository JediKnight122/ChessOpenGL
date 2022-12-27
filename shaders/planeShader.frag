in vec4 color;
in vec2 tileSizeFrag;
in vec2 position;

out vec4 fragColor;

void main(void){

    vec4 tempColor = vec4(1, 1, 1, 1);
    float tempPositionX = mod(floor(position.x), 10.0f);


    float tempPositionY = mod(floor(position.y), 10.0f);


    if(tempPositionX < 5.0f){
        tempColor = vec4(1, 1, 1, 1);
    }else{
        tempColor = vec4(0, 0, 0, 1);
    }

    if(tempColor == vec4(1, 1, 1, 1) && tempPositionY < 5){
        tempColor = vec4(0, 0, 0, 1);
    }

    if(tempPositionX >= 5.0f && tempPositionY < 5){
        tempColor = vec4(1, 1, 1, 1);
    }




    fragColor = tempColor;
}
