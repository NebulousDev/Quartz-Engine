#version 450
#extension GL_ARB_separate_shader_objects : enable

layout(location = 0) in struct
{
	vec3 fragPos;
}
fragIn;

layout(location = 0) out vec4 fragOut;

void main()
{
    fragOut = vec4(fragIn.fragPos, 1.0);
}