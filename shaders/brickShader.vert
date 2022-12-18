#sginclude "://shaders/common.vert.inc" //Absoluten Pfad angeben welche Datei inkludiert werden soll, relativ wenn shader nicht in qrc


uniform vec2 brickSize;

out vec2 pos;
out vec2 brickSizeFrag;
out vec4 color;

void main()
{



brickSizeFrag=brickSize;

pos=vertexPosition.xy;

color=vec4(1,0,0,1);

   gl_Position = projectionMatrix*modelViewMatrix*vertexPosition;
}
