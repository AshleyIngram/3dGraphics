varying vec4 ShadowCoord;
uniform mat4 depthMVP;

void main() {
	gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
	gl_FrontColor = gl_Color;
	ShadowCoord = depthMVP * gl_Vertex;
}