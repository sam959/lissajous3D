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

in vec4  position;
in vec2  texcoord;
in vec3  normal;

out vec4 colorVarying;	
out vec2 texCoordVarying;


// ---------------------------------------------------------------------- 

void main()
{
	float rad  = 57.295;
	float zRotation = sin((((freqZ + timeValue) * 360) / rad)*2);

	//float instanceX = float(gl_InstanceID%(numberOfElements) - numberOfElements/2) / numberOfElements;
	//float instanceY = float(gl_InstanceID/(numberOfElements) - numberOfElements/2) / numberOfElements;  
	
	float instanceX = sin(mod(gl_InstanceID,360)/rad*freqX);
	float instanceY = cos(mod(gl_InstanceID,360)/rad*freqY);
	float instanceZ = sin(mod(gl_InstanceID,360)/rad*freqZ + zRotation);


	vec4 vPos = position;
	vPos = vPos + vec4(
						instanceX*2*numberOfElements,
						instanceY*2*numberOfElements, 
						instanceZ*2*numberOfElements,
						0
						);

	/*vPos.x = position.x;
	vPos.y = position.y;*/

	/*
	vPos.x = sin(vPos.x);
	vPos.y = cos(vPos.y);

	*/
	colorVarying = globalColor;
	gl_Position = projectionMatrix * modelViewMatrix * vPos ;
}