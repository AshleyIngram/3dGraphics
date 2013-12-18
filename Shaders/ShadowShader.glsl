uniform sampler2D tex;
varying vec4 ShadowCoord;

void main(void) {
	float visibility = 1.0;

	if (texture2D(tex, ShadowCoord.xy).z < ShadowCoord.z - 0.009)
	{
		visibility = 0.5;
	}

	gl_FragColor = gl_Color * visibility;
}