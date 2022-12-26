in vec4 color;
in vec2 tileSizeFrag;
in vec2 position;

out vec4 fragColor;

void main(void){

    vec4 tempColor = vec4(1, 1, 1, 1);
    float tempPositionX = mod(floor(position.x), 10.0f);
    int compareX = (int)tempPositionX;

    float tempPositionY = mod(floor(position.y), 10.0f);
    int compareY = (int)tempPositionY;

    if(compareX < 5){
        tempColor = vec4(1, 1, 1, 1);
    }else{
        tempColor = vec4(0, 0, 0, 1);
    }

    if(tempColor == vec4(1, 1, 1, 1) && compareY < 5){
        tempColor = vec4(0, 0, 0, 1);
    }

    if(compareX >= 5 && compareY < 5){
        tempColor = vec4(1, 1, 1, 1);
    }




    fragColor = tempColor;
}
