#version 150

uniform mat4 projectionMatrix;
uniform mat4 modelViewMatrix;
uniform mat4 modelViewProjectionMatrix;
uniform vec4 globalColor;
uniform float timeValue=0.0;	// we get this from our ofApp, it's a time value moving from 0 to 1 every 30 seconds
uniform float freqX;
uniform float freqY;
uniform float freqZ;
uniform int numberOfElements;

in vec4  position1;
in vec2  texcoord;

out vec4 colorVarying;	
out vec2 texCoordVarying;


// ---------------------------------------------------------------------- 

void main()
{
	float rad  = 57.295;
	float zRotation = sin((((freqZ + timeValue) * 360) / rad)*2);

		
	float instanceX = sin(mod(gl_InstanceID,360)/rad*freqX);
	float instanceY = cos(mod(gl_InstanceID,360)/rad*freqY);
	float instanceZ = sin(mod(gl_InstanceID,360)/rad*freqZ + zRotation);


	vec4 vPos = position1;
	vPos = vPos + vec4(
						instanceX*2*numberOfElements,
						instanceY*2*numberOfElements, 
						instanceZ*2*numberOfElements,
						0
						);

	colorVarying = vec4(0.7, instanceY*2,instanceZ*2, 1.0);
	gl_Position = projectionMatrix * modelViewMatrix * vPos ;
}