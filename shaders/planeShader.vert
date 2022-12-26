#sginclude "://shaders/common.vert.inc" //Absoluten Pfad angeben welche Datei inkludiert werden soll, relativ wenn shader nicht in qrc

uniform vec2 tileSize;
out vec4 color;
out vec2 tileSizeFrag;
out vec2 position;

void main(){

    tileSizeFrag = tileSize;
    position = vertexPosition.xy;

    color = vec4(1, 1, 1, 1);

    gl_Position = projectionMatrix * modelViewMatrix * vertexPosition;

}
